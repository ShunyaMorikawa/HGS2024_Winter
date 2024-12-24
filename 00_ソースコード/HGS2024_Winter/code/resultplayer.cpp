//========================================
//
// ���U���g�v���C���[����[resultplayer.h]
// Author�F�X��x��
//
//========================================

#include "resultplayer.h"
#include "debugproc.h"
#include "player.h"
#include "enemy.h"
#include "result.h"
#include "sound.h"
#include "texture.h"

//========================================
// �萔��`
//========================================
namespace
{
	const char* WIN_TEX = "data\\TEXTURE\\Result_Win.png";		// �����e�N�X�`���̃p�X
	const char* LOSE_TEX = "data\\TEXTURE\\Result_Lose.png";	// �s�k�e�N�X�`���̃p�X

	const float LOGO_POS_Y = 150.0f;		// ���S�e�N�X�`����Y���W
	const float LOGO_SIZE_WIDTH = 640.0f;	// ���S�e�N�X�`���̃T�C�Y
	const float LOGO_SIZE_HEIGHT = 250.0f;	// ���S�e�N�X�`���̃T�C�Y
	const float ENTER_POS_Y = 550.0f;		// �����e�N�X�`����Y���W
	const float ENTER_SIZE = 250.0f;		// �����e�N�X�`���̃T�C�Y

	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, 50.0f };		// �v���C���[�����ʒu
	const D3DXVECTOR3 INITIAL_ROT = { 0.0f, D3DX_PI, 0.0f };	// �v���C���[��������
}

//========================================
// �ÓI�����o�ϐ�
//========================================
CResultPlayer* CResultPlayer::m_pResultPlayer = nullptr;

//========================================
// �R���X�g���N�^
//========================================
CResultPlayer::CResultPlayer(int nPriority) : CCharacter(nPriority),
m_apNumModel	(0),			// ���f���̑���
m_nOldMotion	(0),			// �O��̃��[�V����
m_eState		(STATE_NONE),	// ���
m_pWin(nullptr),	// �����e�N�X�`��
m_pLose(nullptr)	// �s�k�e�N�X�`��

{//�l���N���A
	m_pResultPlayer = nullptr;
	memset(&m_apModel[0], 0, sizeof(m_apModel));	//���f�����
}

//========================================
// �f�X�g���N�^
//========================================
CResultPlayer::~CResultPlayer()
{
}

//=======================================
//�V���O���g��
//=======================================
CResultPlayer* CResultPlayer::GetInstance()
{
	if (m_pResultPlayer == nullptr)
	{//�C���X�^���X����
		return m_pResultPlayer = new CResultPlayer;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pResultPlayer;
	}
}

//========================================
// �^�C�g���v���C���[����
//========================================
CResultPlayer* CResultPlayer::Create(std::string pfile)
{
	if (m_pResultPlayer == nullptr)
	{
		//�v���C���[����
		m_pResultPlayer = new CResultPlayer;

		//������
		m_pResultPlayer->Init(pfile);
	}

	//�|�C���^��Ԃ�
	return m_pResultPlayer;
}

//========================================
// ������
//========================================
HRESULT CResultPlayer::Init(std::string pfile)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �L�����̏�����
	CCharacter::Init(pfile);

	// �v���C���[��Ԃ̏�����
	m_eState = STATE_NONE;

	// �ʒu�ݒ�
	SetPos(INITIAL_POS);

	// �����ݒ�
	SetRot(INITIAL_ROT);

	return S_OK;
}

//========================================
// �I��
//========================================
void CResultPlayer::Uninit(void)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	// �I��
	CCharacter::Uninit();
	m_pResultPlayer = nullptr;
}

//========================================
// �X�V
//========================================
void CResultPlayer::Update(void)
{
	// �ʒu�E�ړ��ʁE�����擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 rot = GetRot();

	// ���[�V����
	Motion();

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n�v���C���[�̈ʒu�F%f�A%f�A%f\n", pos.x, pos.y, pos.z);
}

//========================================
// �`��
//========================================
void CResultPlayer::Draw(void)
{
	// �`��
	CCharacter::Draw();
}

//========================================
// ���[�V�����Ǘ�
//========================================
void CResultPlayer::Motion()
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// ���[�V�������擾
	CMotion* pMotion = GetMotion();

	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// ����
	D3DXVECTOR3 rot = { 0.0f, 0.0f, 0.0f };

	if (pMotion != nullptr)
	{// ���[�V�����X�V
		pMotion->Update();
	}
}
