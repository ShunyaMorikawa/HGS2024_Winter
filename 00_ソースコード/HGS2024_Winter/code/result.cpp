//========================================
//
// リザルト[result.h]
// Author：森川駿弥
//
//========================================

#include "result.h"
#include "texture.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "camera.h"
#include "field.h"
#include "mapobject.h"
#include "wall.h"
#include "useful.h"
#include "resultplayer.h"
#include "debugproc.h"
#include "score.h"

//========================================
// 定数定義
//========================================
namespace
{
	const std::string RESULT_PLAYER_TXT = "data\\FILE\\resultplayer.txt";	// プレイヤー情報のパス
}

//========================================
// 静的メンバ変数
//========================================
CResult* CResult::m_pResult = nullptr;

//=======================================
//コンストラクタ
//=======================================
CResult::CResult()
{
	
}

//=======================================
//デストラクタ
//=======================================
CResult::~CResult()
{
}

//=======================================
//シングルトン
//=======================================
CResult* CResult::GetInstance()
{
	if (m_pResult == nullptr)
	{//インスタンス生成
		return m_pResult = new CResult;
	}
	else
	{//ポインタを返す
		return m_pResult;
	}
}

//=======================================
//生成
//=======================================
CResult* CResult::Create(void)
{
	if (m_pResult == nullptr)
	{
		//インスタンス生成
		m_pResult = new CResult;

		//初期化
		m_pResult->Init();
	}

	//ポインタを返す
	return m_pResult;
}

//=======================================
//初期化
//=======================================
HRESULT CResult::Init(void)
{
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

	FILE* pFile;

	//ファイルから問題を読み込み
	pFile = fopen("data\\RANKING\\ranking.bin", "rb");

	int nScore[6] = {};

	if (pFile != NULL)
	{//開けた場合
		fread(&nScore[0], sizeof(int), 6, pFile);
		fclose(pFile);
	}
	else
	{//開けなかった場合

	 //ランキング初期化
		for (int nCnt = 0; nCnt < 6; nCnt++)
		{
			nScore[nCnt] = 0;
		}
	}

	nScore[5] = CScore::GetScoreResult();

	int nMaxNumber, nTemp;
	//降順挿入ソート
	for (int nCnt1 = 1; nCnt1 < 6; nCnt1++)
	{
		nMaxNumber = nCnt1;

		while (nMaxNumber > 0 && nScore[nMaxNumber - 1] < nScore[nMaxNumber])
		{
			nTemp = nScore[nMaxNumber - 1];
			nScore[nMaxNumber - 1] = nScore[nMaxNumber];
			nScore[nMaxNumber] = nTemp;

			nMaxNumber--;
		}
	}

	//ファイルから問題を読み込み
	pFile = fopen("data\\RANKING\\ranking.bin", "wb");

	if (pFile != NULL)
	{//開けた場合

		fwrite(&nScore[0], sizeof(int), 6, pFile);
		fclose(pFile);
	}
	else
	{//開けなかった場合

	}

	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		m_pScore[nCnt] = CScore::Create(D3DXVECTOR3(800.0f, 101.0f * nCnt + 235.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);
		m_pScore[nCnt]->AddScore(nScore[nCnt]);
	}

	m_pScore[5] = CScore::Create(D3DXVECTOR3(800.0f, 70.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);
	m_pScore[5]->AddScore(CScore::GetScoreResult());

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_RESULT);

	//成功を返す
	return S_OK;
}

//=======================================
//終了
//=======================================
void CResult::Uninit(void)
{
	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// サウンド停止
	pSound->Stop();

	if (m_pResult != nullptr)
	{//モード破棄
		delete m_pResult;
		m_pResult = nullptr;
	}
}

//=======================================
//更新
//=======================================
void CResult::Update(void)
{
	//CInputKeyboard型のポインタ
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad型のポインタ
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// カメラの情報取得
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// リザルトカメラ
	pCamera->Result();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		// 画面遷移(フェード)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// デバッグ表示
	pDebugProc->Print("\nリザルト\n");
}

//=======================================
//描画
//=======================================
void CResult::Draw(void)
{
}
