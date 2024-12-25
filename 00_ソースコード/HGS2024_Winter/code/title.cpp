//========================================
//
//タイトル[title.cpp]
//Author：森川駿弥
//
//========================================

#include "title.h"
#include "texture.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "camera.h"
#include "field.h"
#include "mapobject.h"
#include "wall.h"
#include "titleplayer.h"
#include "useful.h"
#include "debugproc.h"
#include "press_enter.h"

//========================================
//静的メンバ変数
//========================================
CTitle* CTitle::m_pTitle = nullptr;		// ゲームのポインタ

//========================================
// 定数定義
//========================================
namespace
{
	const std::string PLAYER_TXT = "data\\FILE\\titleplayer.txt";	// プレイヤー情報のパス
	const char* TITLE_TEX = "data\\TEXTURE\\title.png";			// タイトルテクスチャのパス
	const char* ENTER_TEX = "data\\TEXTURE\\press_enter.png";	// 文字テクスチャのパス

	const float LOGO_POS_Y = 150.0f;		// ロゴテクスチャのY座標
	const float LOGO_SIZE_WIDTH = 640.0f;	// ロゴテクスチャの幅
	const float LOGO_SIZE_HEIGHT = 250.0f;	// ロゴテクスチャの高さ
	const float ENTER_POS_Y = 550.0f;		// 文字テクスチャのY座標
	const float ENTER_WIDTH = 500.0f;		// 文字テクスチャの幅
	const float ENTER_HEIGHT = 150.0f;		// 文字テクスチャの高さ
}

//=======================================
//コンストラクタ
//=======================================
CTitle::CTitle() :
	m_pObject2D(nullptr),
	m_pEnter(nullptr)
{

}

//=======================================
//デストラクタ
//=======================================
CTitle::~CTitle()
{

}

//=======================================
//シングルトン
//=======================================
CTitle* CTitle::GetInstance()
{
	if (m_pTitle == nullptr)
	{//インスタンス生成
		return m_pTitle = new CTitle;
	}
	else
	{//ポインタを返す
		return m_pTitle;
	}
}

//=======================================
//生成
//=======================================
CTitle* CTitle::Create(void)
{
	if (m_pTitle == nullptr)
	{
		//インスタンス生成
		m_pTitle = new CTitle;

		//初期化
		m_pTitle->Init();
	}

	//ポインタを返す
	return m_pTitle;
}

//=======================================
//初期化
//=======================================
HRESULT CTitle::Init(void)
{
	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// カメラの情報取得
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// カメラの初期化
	pCamera->Init();

	// フィールド生成
	CField::Create();
	
	// 4方向に壁生成
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	m_pObject2D = CObject2D::Create();
	m_pObject2D->SetPos(D3DXVECTOR3(640.0f, 300.0f, 0.0f));
	m_pObject2D->SetSize(960.0f, 540.0f);
	m_pObject2D->BindTexture(pTexture->Regist("data\\TEXTURE\\title\\title_logo.png"));

	// エンター生成
	m_pEnter = CPress_Enter::Create(D3DXVECTOR3(1000.0f, 600.0f, 0.0f));

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_TITLE);

	//成功を返す
	return S_OK;
}

//=======================================
//終了
//=======================================
void CTitle::Uninit(void)
{
	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// サウンド停止
	pSound->Stop();

	if (m_pTitle != nullptr)
	{//モード破棄
		delete m_pTitle;
		m_pTitle = nullptr;
	}
}

//=======================================
//更新
//=======================================
void CTitle::Update(void)
{
	//CInputKeyboard型のポインタ
	CInputKeyboard *pInputKeyboard = pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	
	//CInputPad型のポインタ
	CInputPad *pInputPad = pInputPad = CManager::GetInstance()->GetInputPad();
	
	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// カメラの情報取得
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// タイトルカメラ
	pCamera->Title();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true ||
		pInputKeyboard->GetTrigger(DIK_SPACE) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		pSound->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);

		// 画面遷移(フェード)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TUTORIAL);
	}

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// デバッグ表示
	pDebugProc->Print("\nタイトル\n");
}

//=======================================
//描画
//=======================================
void CTitle::Draw(void)
{
}
