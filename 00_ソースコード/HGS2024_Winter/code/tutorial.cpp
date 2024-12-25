//========================================
//
//�`���[�g���A��[tutorial.h]
//Author�F�X��x��
//
//========================================

#include "tutorial.h"
#include "manager.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "fade.h"
#include "texture.h"
#include "wall.h"
#include "mapobject.h"
#include "sound.h"
#include "useful.h"
#include "enemy.h"
#include "debugproc.h"

//========================================
//�ÓI�����o�ϐ�
//========================================
CTutorial* CTutorial::m_pTutorial = nullptr;		// �Q�[���̃|�C���^

//========================================
// �萔��`
//========================================
namespace
{
	const std::string TUTORIAL_TEX = "data\\texture\\tutorial\\tutorial00.jpg";
	const std::string TUTORIAL_SECOND_TEX = "data\\texture\\tutorial\\tutorial01.jpg";
}

//=======================================
//�R���X�g���N�^
//=======================================
CTutorial::CTutorial():
m_bEnd(false),
m_pObj2D(nullptr)	// 2D�|�C���^
{
	m_pTutorial = nullptr;
}

//=======================================
//�f�X�g���N�^
//=======================================
CTutorial::~CTutorial()
{
}

//=======================================
//�V���O���g��
//=======================================
CTutorial* CTutorial::GetInstance()
{
	if (m_pTutorial == nullptr)
	{//�C���X�^���X����
		return m_pTutorial = new CTutorial;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pTutorial;
	}
}

//=======================================
//����
//=======================================
CTutorial* CTutorial::Create(void)
{
	if (m_pTutorial == nullptr)
	{
		//�C���X�^���X����
		m_pTutorial = new CTutorial;
		m_pTutorial->Init();
	}

	//�|�C���^��Ԃ�
	return m_pTutorial;
}

//=======================================
//������
//=======================================
HRESULT CTutorial::Init(void)
{
	// �e�N�X�`�����擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	if (m_pObj2D == nullptr)
	{// �I�u�W�F�N�g2D����
		m_pObj2D = CObject2D::Create();
	}

	if (m_pObj2D != nullptr)
	{//	�e��ݒ�
		// �e�N�X�`��
		m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_TEX));

		// ���W
		m_pObj2D->SetPos(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		// �T�C�Y
		m_pObj2D->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	// �I�����ĂȂ�
	m_bEnd = false;

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_TUTORIAL);

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CTutorial::Uninit(void)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pTutorial != nullptr)
	{//���[�h�j��
		delete m_pTutorial;
		m_pTutorial = nullptr;
	}
}

//=======================================
//�X�V
//=======================================
void CTutorial::Update(void)
{
	// �e�N�X�`�����擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//CInputKeyboard���擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad���擾
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	if (!m_bEnd
		&& pInputKeyboard->GetTrigger(DIK_RETURN)
		|| pInputKeyboard->GetTrigger(DIK_SPACE)
		|| pInputKeyboard->GetTrigger(DIK_D)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0))
	{// �񖇖ڂ̃e�N�X�`���ɂ���
		
		if (m_pObj2D != nullptr)
		{
			// �e�N�X�`���ݒ�
			m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_SECOND_TEX));
		}

		// �I����Ԃɂ���
		m_bEnd = true;

		return;
	}
	else if (pInputKeyboard->GetTrigger(DIK_A)
				|| pInputPad->GetTrigger(CInputPad::BUTTON_B, 0))
	{// �O�̃e�N�X�`���ɂ���
		if (m_pObj2D != nullptr)
		{// �e�N�X�`���ݒ�
			m_pObj2D->BindTexture(pTexture->Regist(TUTORIAL_TEX));
		}

		// �I����ԉ���
		m_bEnd = false;
	}

	if (m_bEnd
		&& pInputKeyboard->GetTrigger(DIK_RETURN)
		|| pInputKeyboard->GetTrigger(DIK_SPACE)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0)
		|| pInputPad->GetTrigger(CInputPad::BUTTON_START, 0))
	{// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);
	}

	// �f�o�b�O�\��
	pDebugProc->Print("\n�`���[�g���A��\n");
}

//=======================================
//�`��
//=======================================
void CTutorial::Draw(void)
{
}
