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
		30,
		30,
		60,
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
	m_state = STATE_START;
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

	// スコア生成
	m_pScore = CScore::Create(D3DXVECTOR3(410.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);

	if (m_pTime == nullptr)
	{// タイム生成
		m_pTime = CTimer::Create(D3DXVECTOR3(640.0f, 320.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);
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
	// CInputKeyboard型のポインタ
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// プレイヤーの情報取得
	CPlayer* pPlayer = CPlayer::GetInstance();

	m_pEnemyManager->Update();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// 画面遷移(フェード)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
	}

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	m_nTransition++;

	if (m_nTransition > STATE_TIME[m_state])
	{
		m_nTransition = 0;

		switch (m_state)
		{
		case CGame::STATE_WAIT:
			m_state = STATE_START;
			break;
		case CGame::STATE_START:
			m_state = STATE_GAME;
			break;
		case CGame::STATE_GAME:
			break;
		case CGame::STATE_FINISH:
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
