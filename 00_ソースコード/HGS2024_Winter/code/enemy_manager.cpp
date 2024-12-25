//========================================
//
// 敵マネージャーの処理[enemy_manager.cpp]
// Author：中村陸
//
//========================================

#include "enemy.h"
#include "enemy_manager.h"
#include "debugproc.h"

//========================================
//名前空間
//========================================
namespace
{
	const int MAX_ENEMY = 10;				// 体力
}

//静的メンバ変数宣言-------------------
CEnemyManager* CEnemyManager::m_pEnemyManager = NULL;

//========================================
//コンストラクタ
//========================================
CEnemyManager::CEnemyManager()
{//値をクリア
	m_nCntEnemy = 0;
}

//========================================
//デストラクタ
//========================================
CEnemyManager::~CEnemyManager()
{
}

//========================================
// 生成
//========================================
CEnemyManager* CEnemyManager::GetInstance()
{
	if (m_pEnemyManager == NULL)
	{
		m_pEnemyManager = new CEnemyManager;
		return m_pEnemyManager;
	}
	else
	{
		return m_pEnemyManager;
	}
}

//=====================================
// マネージャーの破棄
//=====================================
HRESULT CEnemyManager::Release(void)
{
	if (m_pEnemyManager != NULL)
	{
		m_pEnemyManager->Uninit();

		delete m_pEnemyManager;
		m_pEnemyManager = NULL;
	}

	return S_OK;
}

//========================================
// 初期化
//========================================
HRESULT CEnemyManager::Init()
{
	return S_OK;
}

//========================================
// 終了
//========================================
void CEnemyManager::Uninit(void)
{
	for (int i = 0; i < 3; i++)
	{
		listEnemy[i].clear();
	}
}

//========================================
// 更新
//========================================
void CEnemyManager::Update(void)
{
	m_nCntEnemy++;

	if (m_nCntEnemy < 30) { return; }

	int nLane = rand() % 3;

	// 敵の数が一定数超えたら出さない
	if ((int)listEnemy[nLane].size() > MAX_ENEMY) { return; }

	m_nCntEnemy = 0;

	CEnemy* pEnemy;
	if (rand() % 100 > 75)
	{
		// エネミー生成
		pEnemy = CEnemyOtaku::Create(Constance::OTAKU_TXT[0]);
	}
	else
	{
		// エネミー生成
		pEnemy = CEnemyChild::Create(Constance::ENEMY_TXT);
	}

	// 敵に情報を設定
	if (listEnemy[nLane].empty())
	{
		pEnemy->SetParent(nullptr);
	}
	else
	{
		CEnemy* pEnemyParent = listEnemy[nLane].back();
		pEnemy->SetParent(pEnemyParent);
		pEnemyParent->SetChild(pEnemy);
	}
	
	pEnemy->SetNumLane(nLane);
	listEnemy[nLane].push_back(pEnemy);
}
