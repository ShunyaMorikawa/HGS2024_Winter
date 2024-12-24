//========================================
//
// �^�C�g���v���C���[����[titleplayer.h]
// Author�F�X��x��
//
//========================================

#include "titleplayer.h"
#include "debugproc.h"

//========================================
// �萔��`
//========================================
namespace
{
	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, 50.0f };	// �v���C���[�����ʒu
	const D3DXVECTOR3 INITIAL_ROT = { 0.0f, 0.0f, 0.0f };	// �v���C���[��������
}

//========================================
// �ÓI�����o�ϐ�
//========================================
CTitlePlayer* CTitlePlayer::m_pTitlePlayer = nullptr;

//========================================
// �R���X�g���N�^
//========================================
CTitlePlayer::CTitlePlayer(int nPriority) : CCharacter(nPriority),
m_apNumModel(0),	// ���f���̑���
m_nOldMotion(0)		// �O��̃��[�V����
{//�l���N���A
	m_pTitlePlayer = nullptr;
	memset(&m_apModel[0], 0, sizeof(m_apModel));	//���f�����
}

//========================================
// �f�X�g���N�^
//========================================
CTitlePlayer::~CTitlePlayer()
{
}

//=======================================
//�V���O���g��
//=======================================
CTitlePlayer* CTitlePlayer::GetInstance()
{
	if (m_pTitlePlayer == nullptr)
	{//�C���X�^���X����
		return m_pTitlePlayer = new CTitlePlayer;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pTitlePlayer;
	}
}

//========================================
// �^�C�g���v���C���[����
//========================================
CTitlePlayer* CTitlePlayer::Create(std::string pfile)
{
	if (m_pTitlePlayer == nullptr)
	{
		//�v���C���[����
		m_pTitlePlayer = new CTitlePlayer;

		//������
		m_pTitlePlayer->Init(pfile);
	}

	//�|�C���^��Ԃ�
	return m_pTitlePlayer;
}

//========================================
// ������
//========================================
HRESULT CTitlePlayer::Init(std::string pfile)
{
	// �L�����̏�����
	CCharacter::Init(pfile);

	// �ʒu�ݒ�
	SetPos(INITIAL_POS);

	// �����ݒ�
	SetRot(INITIAL_ROT);

	return S_OK;
}

//========================================
//�I��
//========================================
void CTitlePlayer::Uninit(void)
{
	// �I��
	CCharacter::Uninit();
	m_pTitlePlayer = nullptr;
}

//========================================
//�X�V
//========================================
void CTitlePlayer::Update(void)
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
//�`��
//========================================
void CTitlePlayer::Draw(void)
{
	// �`��
	CCharacter::Draw();
}

//========================================
// ���[�V�����Ǘ�
//========================================
void CTitlePlayer::Motion()
{
	// ���[�V�������擾
	CMotion* pMotion = GetMotion();

	// �^�C�g�����[�V����
	pMotion->Set(CMotion::PLAYER_MOTIONTYPE_NEUTRAL);

	if (pMotion != nullptr)
	{// ���[�V�����X�V
		pMotion->Update();
	}
}
