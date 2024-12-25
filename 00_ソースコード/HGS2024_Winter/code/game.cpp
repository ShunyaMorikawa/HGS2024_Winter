//========================================
//
//ゲーム内処理[game.cpp]
//Author：森川駿弥
//
//========================================

#include "game.h"
#include "camera.h"
#include "input.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "enemy.h"
#include "fade.h"
#include "wall.h"
#include "mapobject.h"
#include "sound.h"
#include "debugproc.h"
#include "texture.h"
#include "useful.h"
#include "enemy_manager.h"
#include "score.h"
#include "timer.h"
#include "objectX.h"

//========================================
//静的メンバ変数
//========================================
CGame *CGame::m_pGame = nullptr;		// ゲームのポインタ

//========================================
// 定数定義
//========================================
namespace
{
	const int STATE_TIME[CGame::STATE_MAX] =
	{
		30,
		120,
		0,
		120,
	};// プレイヤーの目標位置
}

//========================================
//コンストラクタ
//========================================
CGame::CGame() : 
m_bPause		(false),	// ポーズ
m_nTransition	(0),		// 遷移時間
m_pObjectX		(nullptr),	// オブジェクトXのポインタ
m_pIdxMesh		(nullptr),	// インデックスメッシュのポインタ
m_pFade			(nullptr),	// フェードのポインタ
m_pObj2D		(nullptr),	// オブジェクト2Dのポインタ
m_pTime			(nullptr)
{
	m_pGame = nullptr;		// ゲームのポインタ
	m_state = STATE_WAIT;
}

//========================================
//デストラクタ
//========================================
CGame::~CGame()
{
}

//========================================
// シングルトン
//========================================
CGame* CGame::GetInstance()
{
	if (m_pGame == nullptr)
	{//インスタンス生成
		return m_pGame = new CGame;
	}
	else
	{//ポインタを返す
		return m_pGame;
	}
}

//========================================
//生成
//========================================
CGame *CGame::Create(void)
{
	if (m_pGame == nullptr)
	{
		//インスタンス生成
		m_pGame = new CGame;
		m_pGame->Init();
	}

	//ポインタを返す
	return m_pGame;
}

//========================================
//初期化
//========================================
HRESULT CGame::Init(void)
{
	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//テクスチャのポインタ
	CSound* pSound = CManager::GetInstance()->GetSound();

	// プレイヤー生成
	CPlayer::Create(Constance::PLAYER_TXT);

	m_pEnemyManager = CEnemyManager::GetInstance();
	m_pEnemyManager->Init();

	// フィールド生成
	CField::Create();

	// 4方向に壁生成
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	//CModel* pModel = CModel::Create("data\\MODEL\\stage\\table.x");
	//pModel->SetPos({ 0.0f, 0.0f, 0.0f });

	// スコア生成
	m_pScore = CScore::Create(D3DXVECTOR3(410.0f, 650.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);

	if (m_pTime == nullptr)
	{// タイム生成
		m_pTime = CTimer::Create(D3DXVECTOR3(700.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);
	}

	// 遷移時間
	m_nTransition = 0;

	//ポーズの状態
	m_bPause = false;

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_GAME);

	return S_OK;
}

//========================================
//終了
//========================================
void CGame::Uninit(void)
{
	if(m_pObj2D != nullptr)
	{
		m_pObj2D->Uninit();
		m_pObj2D = nullptr;
	}

	if (m_pTime != nullptr)
	{
		m_pTime->Uninit();
		m_pTime = nullptr;
	}

	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// サウンド停止
	pSound->Stop();

	if (m_pGame != nullptr)
	{//モード破棄
		delete m_pGame;
		m_pGame = nullptr;
	}

	m_pEnemyManager->Release();
}

//========================================
//更新
//========================================
void CGame::Update(void)
{
	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// CInputKeyboard型のポインタ
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// プレイヤーの情報取得
	CPlayer* pPlayer = CPlayer::GetInstance();

	m_pEnemyManager->Update();

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	m_nTransition++;

	if (m_nTransition > STATE_TIME[m_state])
	{
		m_nTransition = 0;

		switch (m_state)
		{
		case CGame::STATE_WAIT:

			m_pObject2D = CObject2D::Create();
			m_pObject2D->SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
			m_pObject2D->SetSize(960.0f, 540.0f);
			m_pObject2D->BindTexture(pTexture->Regist("data\\TEXTURE\\start.png"));
			m_state = STATE_START;

			break;
		case CGame::STATE_START:

			m_pTime->SetStart(true);
			m_pObject2D->SetSize(0.0f, 0.0f);

			m_state = STATE_GAME;

			break;
		case CGame::STATE_GAME:

			if (m_pTime->GetTimer() <= 0)
			{
				m_pObject2D = CObject2D::Create();
				m_pObject2D->SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
				m_pObject2D->SetSize(960.0f, 540.0f);
				m_pObject2D->BindTexture(pTexture->Regist("data\\TEXTURE\\finish.png"));

				CScore::SetScoreResult(m_pScore->GetScore());

				m_state = STATE_FINISH;
				m_pTime->SetStart(false);
			}

			break;
		case CGame::STATE_FINISH:

			CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);

			break;
		case CGame::STATE_MAX:

			m_state = STATE_START;

			break;
		default:
			break;
		}
	}

	// デバッグ表示
	pDebugProc->Print("\nゲーム\n");

#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_F2) == true)
	{// ゲーム画面に遷移
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// ゲーム画面に遷移
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
	}
#endif
}

//========================================
//描画
//========================================
void CGame::Draw(void)
{
}
