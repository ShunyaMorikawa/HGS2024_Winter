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
	const std::string TUTORIAL_TEX = "data\\texture\\tutorial\\tutorial00.jpg";
	const std::string TUTORIAL_SECOND_TEX = "data\\texture\\tutorial\\tutorial01.jpg";
}

//=======================================
//コンストラクタ
//=======================================
CTutorial::CTutorial():
m_bEnd(false),
m_pObj2D(nullptr)	// 2Dポインタ
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
	// テクスチャ情報取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	if (m_pObj2D == nullptr)
	{// オブジェクト2D生成
		m_pObj2D = CObject2D::Create();
	}

	if (m_pObj2D != nullptr)
	{//	各種設定
		// テクスチャ
		m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_TEX));

		// 座標
		m_pObj2D->SetPos(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		// サイズ
		m_pObj2D->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	// 終了してない
	m_bEnd = false;

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_TUTORIAL);

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
	// テクスチャ情報取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//CInputKeyboard情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad情報取得
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	if (!m_bEnd
		&& pInputKeyboard->GetTrigger(DIK_RETURN)
		|| pInputKeyboard->GetTrigger(DIK_SPACE)
		|| pInputKeyboard->GetTrigger(DIK_D)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0))
	{// 二枚目のテクスチャにする
		
		if (m_pObj2D != nullptr)
		{
			// テクスチャ設定
			m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_SECOND_TEX));
		}

		// 終了状態にする
		m_bEnd = true;

		return;
	}
	else if (pInputKeyboard->GetTrigger(DIK_A)
				|| pInputPad->GetTrigger(CInputPad::BUTTON_B, 0))
	{// 前のテクスチャにする
		if (m_pObj2D != nullptr)
		{// テクスチャ設定
			m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_TEX));
		}

		// 終了状態解除
		m_bEnd = false;
	}

	if (m_bEnd
		&& pInputKeyboard->GetTrigger(DIK_RETURN)
		|| pInputKeyboard->GetTrigger(DIK_SPACE)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_START, 0))
	{// 画面遷移(フェード)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);
	}

	// デバッグ表示
	pDebugProc->Print("\nチュートリアル\n");
}

//=======================================
//描画
//=======================================
void CTutorial::Draw(void)
{
}
