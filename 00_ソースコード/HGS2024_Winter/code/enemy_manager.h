//========================================
//
// 敵マネージャーの処理[enemy_manager.h]
// Author：中村陸
//
//========================================

#ifndef _ENEMYMANAGER_H_
#define _ENEMYMANAGER_H_

#include <list>

//========================================
// 前方宣言
//========================================
class CEnemy;

//========================================
//エネミークラス
//========================================
class CEnemyManager
{
public:
	

	CEnemyManager();		//コンストラクタ
	~CEnemyManager();		//デストラクタ

	// メンバ関数
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	std::list<CEnemy*>* GetListEnemy(void) { return &listEnemy; }

	static CEnemyManager* GetInstance();
	static HRESULT Release(void);

private:
	
	//メンバ変数
	std::list<CEnemy*> listEnemy;
	int m_nCntEnemy;

	//静的メンバ変数
	static CEnemyManager* m_pEnemyManager;
};

#endif
