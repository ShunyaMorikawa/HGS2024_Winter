//========================================
//
// 敵の処理[enemy.h]
// Author：森川駿弥
//
//========================================

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

//========================================
// 前方宣言
//========================================
class CModel;
class CMotion;
class CEffect;
class CGauge;

//========================================
//エネミークラス
//========================================
class CEnemy : public CCharacter
{
public:
	// 状態
	enum ENEMYSTATE
	{// プレイヤーの状態
		STATE_NONE = 0,
		STATE_NORMAL,	// 通常
		STATE_DAMAGE,	// ダメージ
		STATE_DEATH,	// 死亡
		STATE_MAX
	};

	CEnemy(int nPriority = 4);		//コンストラクタ
	~CEnemy();		//デストラクタ

	// メンバ関数
	static CEnemy* Create(std::string pfile);
	HRESULT Init(void) { return S_OK; }		// 純粋仮想
	HRESULT Init(std::string pfile);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Hit(int nLife);

private:
	void NockBack();
	void Motion();
	void CollisionPlayer(int nDamage);
	void CollisionCircle();

	//メンバ変数
	int m_nCnt;			// カウント
	int m_nState;		// 状態

	ENEMYSTATE m_eState;	// 状態
};

#endif
