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

	//�����o�ϐ�
	int m_nCnt;			// �J�E���g
	int m_nState;		// ���

	ENEMYSTATE m_eState;	// ���
};

#endif
