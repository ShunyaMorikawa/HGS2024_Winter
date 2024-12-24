//========================================
//
// ���U���g�v���C���[����[resultplayer.h]
// Author�F�X��x��
//
//========================================

#ifndef _RESULTPLAYER_H_
#define _RESULTPLAYER_H_

#include "character.h"
#include "object2D.h"

//========================================
// �O���錾
//========================================
class CModel;
class CMotion;

//========================================
//�v���C���[�N���X
//========================================
class CResultPlayer : public CCharacter
{
public:
	// ���
	enum RESULTSTATE
	{// �v���C���[�̏��
		STATE_NONE = 0,
		STATE_WIN,		// ����
		STATE_LOSE,		// �s�k
		STATE_MAX
	};

	CResultPlayer(int nPriority = 4);		//�R���X�g���N�^
	~CResultPlayer();		//�f�X�g���N�^

	// �����o�֐�
	static CResultPlayer* Create(std::string pfile);

	HRESULT Init() { return S_OK; }		//�������z
	HRESULT Init(std::string pfile);
	void Uninit();
	void Update();
	void Draw();

	// ��Ԏ擾�E�ݒ�
	RESULTSTATE GetState() { return m_eState; }
	void SetState(RESULTSTATE nState) { m_eState = nState; }

	// ���g�̏��
	static CResultPlayer* GetInstance();

private:
	void Motion();

	//�����o�ϐ�
	int m_apNumModel;		// ���f��(�p�[�c)�̑���
	int m_nOldMotion;		// �O��̃��[�V����

	RESULTSTATE m_eState;	// ���

	bool m_IsWin;	// ����
	bool m_IsLose;	// �s�k

	CObject2D* m_pWin;	// �����e�N�X�`��
	CObject2D* m_pLose;	// �s�k�e�N�X�`��

	CModel* m_apModel[MAX_PARTS];	// ���f���̃_�u���|�C���^

	static CResultPlayer* m_pResultPlayer;	// ���g�̃|�C���^
};

#endif
