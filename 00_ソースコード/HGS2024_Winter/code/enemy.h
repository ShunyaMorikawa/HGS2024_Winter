//========================================
//
// �G�̏���[enemy.h]
// Author�F�X��x��
//
//========================================

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

//========================================
// �O���錾
//========================================
class CModel;
class CMotion;
class CEffect;
class CGauge;
class CBillboard;

//========================================
//�G�l�~�[�N���X
//========================================
class CEnemy : public CCharacter
{
public:
	// ���
	enum ENEMYSTATE
	{// �v���C���[�̏��
		STATE_NONE = 0,
		STATE_NORMAL,	// �ʏ�
		STATE_DAMAGE,	// �_���[�W
		STATE_DEATH,	// ���S
		STATE_MAX
	};

	CEnemy(int nPriority = 4);		//�R���X�g���N�^
	~CEnemy();		//�f�X�g���N�^

	// �����o�֐�
	static CEnemy* Create(std::string pfile);
	HRESULT Init(void) { return S_OK; }		// �������z
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

	//�����o�ϐ�
	CBillboard* m_pBillboard[2];
	D3DXVECTOR3 m_GolePos;
	int m_nNumPresent;	// �J�E���g
	int m_nNumLane;		// �J�E���g
	int m_nCntWait;		// �J�E���g

private:
	void NockBack();
	void Motion();
	void CollisionPlayer(int nDamage);
	void CollisionCircle();

	//�����o�ϐ�
	CEnemy* m_pParent;
	CEnemy* m_pChild;
	
	
	int m_nState;		// ���

	bool bGet;

	ENEMYSTATE m_eState;	// ���
};

//========================================
//�q���̃G�l�~�[�N���X
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
//�I�^�N�̃G�l�~�[�N���X
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
