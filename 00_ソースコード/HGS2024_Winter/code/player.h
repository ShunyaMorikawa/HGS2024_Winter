//========================================
//
//�v���C���[����[player.h]
//Author�F�X��x��
//
//========================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

//========================================
// �O���錾
//========================================
class CModel;
class CMotion;
class CEffect;
class CGauge;
class CLockonMarker;
class CShadow;

//========================================
//�v���C���[�N���X
//========================================
class CPlayer : public CCharacter
{
public:
	// ���
	enum PLAYERSTATE
	{// �v���C���[�̏��
		STATE_NONE = 0,
		STATE_NORMAL,	// �ʏ�
		STATE_DAMAGE,	// �_���[�W
		STATE_DEATH,	// ���S
		STATE_MAX
	};

	CPlayer(int nPriority = 4);		//�R���X�g���N�^
	~CPlayer();		//�f�X�g���N�^

	// �����o�֐�
	static CPlayer* Create(std::string pfile);

	HRESULT Init() { return S_OK; }		//�������z
	HRESULT Init(std::string pfile);
	void Uninit();
	void Update();
	void Draw();
	void Hit(int nLife);

	float GetRadius() { return m_fRadius; }		// ���a�擾

	int GetLife() { return m_nLife; }			// �̗͎擾

	// ��Ԏ擾�E�ݒ�
	PLAYERSTATE GetState() { return m_eState; }
	void SetState(PLAYERSTATE nState) { m_eState = nState; }

	void CollisionField();

	void CollisionArena();

	void CollisionEnemy(const D3DXVECTOR3& pos);

	// ���g�̏��
	static CPlayer* GetInstance() { return m_pPlayer; }

private:
	void Act(float fSpeed);
	void Attack();
	void Motion();
	void CollisionEnemy(int nDamage);
	void NockBack();

	void LockOn();
	void DestRot();

	//�����o�ϐ�
	int m_apNumModel;		// ���f��(�p�[�c)�̑���
	int m_nLife;			// �̗�
	int m_nOldMotion;		// �O��̃��[�V����
	int m_WalkCounter;		// ���s���̃J�E���^�[

	float m_fRadius;		// ���a
	float m_fCoolDown;		// �N�[���^�C���o�ߎ���
	float m_fDeltaTime;		// �f���^�^�C��

	bool m_bJump;			// �W�����v
	bool m_bMove;			// �ړ�
	bool m_bWait;			// �ҋ@
	bool m_bMowingdown;		// �U��
	bool m_bCutdown;		// �؂艺�낵
	bool m_bStrongAttack;	// ���U��
	bool m_IsLock;			// ���b�N�I���t���O

	PLAYERSTATE m_eState;	// ���

	CEffect* m_pEffect;				// �G�t�F�N�g�̃|�C���^
	CGauge* m_pGauge;				// �Q�[�W�̃|�C���^
	CModel* m_apModel[MAX_PARTS];	// ���f���̃_�u���|�C���^
	CLockonMarker* m_pMarker;		// ���b�N�I���}�[�J�[�̃|�C���^

	static CPlayer* m_pPlayer;		// ���g�̃|�C���^
};

#endif
