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
	// エネミー生成
	listEnemy.push_back(CEnemy::Create(Constance::ENEMY_TXT));
	m_nCntEnemy = 60;

	return S_OK;
}

//========================================
// 終了
//========================================
void CEnemyManager::Uninit(void)
{
	listEnemy.clear();
}

//========================================
// 更新
//========================================
void CEnemyManager::Update(void)
{
	m_nCntEnemy++;

	if (m_nCntEnemy > 30)
	{
		std::list<CEnemy*>  listCollisionDef = listEnemy;
		for (auto itrCollision : listCollisionDef)
		{
			itrCollision->Uninit();
		}
	}

	if (m_nCntEnemy > 60)
	{
		m_nCntEnemy = 0;

		// エネミー生成
		listEnemy.push_back(CEnemy::Create(Constance::ENEMY_TXT));
	}

	// デバッグ表示
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();
	pDebugProc->Print("敵の数 : %d\n", (int)listEnemy.size());
}
