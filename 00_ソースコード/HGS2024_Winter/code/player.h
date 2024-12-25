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

	// ��Ԏ擾�E�ݒ�
	PLAYERSTATE GetState() { return m_eState; }
	void SetState(PLAYERSTATE nState) { m_eState = nState; }

	void CollisionField();

	void CollisionArena();

	// ���g�̏��
	static CPlayer* GetInstance() { return m_pPlayer; }

private:
	void Act(float fSpeed);
	void Present();
	void Motion();
	void DestRot();

	//�����o�ϐ�
	int m_apNumModel;		// ���f��(�p�[�c)�̑���
	int m_nOldMotion;		// �O��̃��[�V����
	int m_nMoveCounter;		// �ړ��̃J�E���^�[
	int m_nPosCounter;		// �ړ��ʒu�̃J�E���^�[

	float m_fDeltaTime;		// �f���^�^�C��

	PLAYERSTATE m_eState;	// ���

	CEffect* m_pEffect;				// �G�t�F�N�g�̃|�C���^
	CGauge* m_pGauge;				// �Q�[�W�̃|�C���^
	CModel* m_apModel[MAX_PARTS];	// ���f���̃_�u���|�C���^
	CLockonMarker* m_pMarker;		// ���b�N�I���}�[�J�[�̃|�C���^

	static CPlayer* m_pPlayer;		// ���g�̃|�C���^
};

#endif
