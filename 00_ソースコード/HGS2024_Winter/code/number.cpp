//=====================================
//
// 
// Author:中村陸
//
//=====================================
#include "number.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//マクロ定義---------------------------

//列挙型定義---------------------------

//クラス定義---------------------------

//構造体定義---------------------------

//プロトタイプ宣言---------------------

//静的メンバ変数宣言-------------------

//=====================================
// コンストラクタ・デストラクタ
//=====================================
CNumber::CNumber(int nPriority = 6) : CObject2D(nPriority)
{
	m_nNumber = 0;
}

CNumber::~CNumber()
{
}

//=====================================
// 生成処理
//=====================================
CNumber* CNumber::Create(void)
{
	CNumber* pObjectNumber;

	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//2Dオブジェクトの生成
	pObjectNumber = new CNumber();

	if (pObjectNumber != NULL)
	{
		//初期化
		if (FAILED(pObjectNumber->Init()))
		{
			pObjectNumber->Release();
		}

		pObjectNumber->BindTexture(pTexture->Regist("data\\TEXTURE\\number01.png"));
	}

	return pObjectNumber;
}

//=====================================
// ポリゴンの初期化処理
//=====================================
HRESULT CNumber::Init(void)
{
	CObject2D::Init();

	return S_OK;
}

//=====================================
// ポリゴンの終了処理
//=====================================
void CNumber::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// ポリゴンの更新処理
//=====================================
void CNumber::Update(void)
{
	SetVertexAnim(10, m_nNumber);

	//CObject2D::Update();
}

//=====================================
// ポリゴンの描画処理
//=====================================
void CNumber::Draw(void)
{
	CObject2D::Draw();
}