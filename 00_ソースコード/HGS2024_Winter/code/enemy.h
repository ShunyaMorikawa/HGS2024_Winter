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
class CBillboard;

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
	virtual HRESULT Init(std::string pfile);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Hit(int nPresent);
	virtual void Angry();

	int GetNumPresent() { return m_nNumPresent; }
	void SetParent(CEnemy* pEnemy) { m_pParent = pEnemy; }
	void SetChild(CEnemy* pChild) { m_pChild = pChild; }
	void SetNumLane(int nNumLane) { m_nNumLane = nNumLane; }

protected:

	//メンバ変数
	CBillboard* m_pBillboard[2];
	D3DXVECTOR3 m_GolePos;
	int m_nNumPresent;	// カウント
	int m_nNumLane;		// カウント
	int m_nCntWait;		// カウント

private:
	void NockBack();
	void Motion();
	void CollisionPlayer(int nDamage);
	void CollisionCircle();

	//メンバ変数
	CEnemy* m_pParent;
	CEnemy* m_pChild;
	
	
	int m_nState;		// 状態

	bool bGet;

	ENEMYSTATE m_eState;	// 状態
};

//========================================
//子供のエネミークラス
//========================================
class CEnemyChild : public CEnemy
{
public:

	static CEnemyChild* Create(std::string pfile);
	HRESULT Init(std::string pfile) override;

private:
	void Angry() override;

};

//========================================
//オタクのエネミークラス
//========================================
class CEnemyOtaku : public CEnemy
{
public:

	static CEnemyOtaku* Create(std::string pfile);
	HRESULT Init(std::string pfile) override;

private:
	void Angry() override;

};

#endif
