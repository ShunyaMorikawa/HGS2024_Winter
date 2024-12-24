//========================================
//
//チュートリアル[tutorial.h]
//Author：森川駿弥
//
//========================================

#include "tutorial.h"
#include "manager.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "fade.h"
#include "texture.h"
#include "wall.h"
#include "mapobject.h"
#include "sound.h"
#include "useful.h"
#include "enemy.h"
#include "debugproc.h"

//========================================
//静的メンバ変数
//========================================
CTutorial* CTutorial::m_pTutorial = nullptr;		// ゲームのポインタ

//========================================
// 定数定義
//========================================
namespace
{
}

//=======================================
//コンストラクタ
//=======================================
CTutorial::CTutorial()
{
	m_pTutorial = nullptr;
}

//=======================================
//デストラクタ
//=======================================
CTutorial::~CTutorial()
{
}

//=======================================
//シングルトン
//=======================================
CTutorial* CTutorial::GetInstance()
{
	if (m_pTutorial == nullptr)
	{//インスタンス生成
		return m_pTutorial = new CTutorial;
	}
	else
	{//ポインタを返す
		return m_pTutorial;
	}
}

//=======================================
//生成
//=======================================
CTutorial* CTutorial::Create(void)
{
	if (m_pTutorial == nullptr)
	{
		//インスタンス生成
		m_pTutorial = new CTutorial;
		m_pTutorial->Init();
	}

	//ポインタを返す
	return m_pTutorial;
}

//=======================================
//初期化
//=======================================
HRESULT CTutorial::Init(void)
{
	// フィールド生成
	CField::Create();

	// 壁生成
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	//成功を返す
	return S_OK;
}

//=======================================
//終了
//=======================================
void CTutorial::Uninit(void)
{
	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// サウンド停止
	pSound->Stop();

	if (m_pTutorial != nullptr)
	{//モード破棄
		delete m_pTutorial;
		m_pTutorial = nullptr;
	}
}

//=======================================
//更新
//=======================================
void CTutorial::Update(void)
{
	//CInputKeyboard情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad情報取得
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_RETURN)||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0))
	{
		// 画面遷移(フェード)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);
	}

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// デバッグ表示
	pDebugProc->Print("\nチュートリアル\n");
}

//=======================================
//描画
//=======================================
void CTutorial::Draw(void)
{
}
