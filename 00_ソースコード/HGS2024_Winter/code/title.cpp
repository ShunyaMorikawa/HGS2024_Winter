//========================================
//
//�^�C�g��[title.cpp]
//Author�F�X��x��
//
//========================================

#include "title.h"
#include "texture.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "camera.h"
#include "field.h"
#include "mapobject.h"
#include "wall.h"
#include "titleplayer.h"
#include "useful.h"
#include "debugproc.h"
#include "press_enter.h"

//========================================
//�ÓI�����o�ϐ�
//========================================
CTitle* CTitle::m_pTitle = nullptr;		// �Q�[���̃|�C���^

//========================================
// �萔��`
//========================================
namespace
{
	const std::string PLAYER_TXT = "data\\FILE\\titleplayer.txt";	// �v���C���[���̃p�X
	const char* TITLE_TEX = "data\\TEXTURE\\title.png";			// �^�C�g���e�N�X�`���̃p�X
	const char* ENTER_TEX = "data\\TEXTURE\\press_enter.png";	// �����e�N�X�`���̃p�X

	const float LOGO_POS_Y = 150.0f;		// ���S�e�N�X�`����Y���W
	const float LOGO_SIZE_WIDTH = 640.0f;	// ���S�e�N�X�`���̕�
	const float LOGO_SIZE_HEIGHT = 250.0f;	// ���S�e�N�X�`���̍���
	const float ENTER_POS_Y = 550.0f;		// �����e�N�X�`����Y���W
	const float ENTER_WIDTH = 500.0f;		// �����e�N�X�`���̕�
	const float ENTER_HEIGHT = 150.0f;		// �����e�N�X�`���̍���
}

//=======================================
//�R���X�g���N�^
//=======================================
CTitle::CTitle() :
	m_pObject2D(nullptr),
	m_pEnter(nullptr)
{

}

//=======================================
//�f�X�g���N�^
//=======================================
CTitle::~CTitle()
{

}

//=======================================
//�V���O���g��
//=======================================
CTitle* CTitle::GetInstance()
{
	if (m_pTitle == nullptr)
	{//�C���X�^���X����
		return m_pTitle = new CTitle;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pTitle;
	}
}

//=======================================
//����
//=======================================
CTitle* CTitle::Create(void)
{
	if (m_pTitle == nullptr)
	{
		//�C���X�^���X����
		m_pTitle = new CTitle;

		//������
		m_pTitle->Init();
	}

	//�|�C���^��Ԃ�
	return m_pTitle;
}

//=======================================
//������
//=======================================
HRESULT CTitle::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �J�����̏��擾
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �J�����̏�����
	pCamera->Init();

	// �t�B�[���h����
	CField::Create();
	
	// 4�����ɕǐ���
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	m_pObject2D = CObject2D::Create();
	m_pObject2D->SetPos(D3DXVECTOR3(640.0f, 300.0f, 0.0f));
	m_pObject2D->SetSize(960.0f, 540.0f);
	m_pObject2D->BindTexture(pTexture->Regist("data\\TEXTURE\\title\\title_logo.png"));

	// �G���^�[����
	m_pEnter = CPress_Enter::Create(D3DXVECTOR3(1000.0f, 600.0f, 0.0f));

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_TITLE);

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CTitle::Uninit(void)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pTitle != nullptr)
	{//���[�h�j��
		delete m_pTitle;
		m_pTitle = nullptr;
	}
}

//=======================================
//�X�V
//=======================================
void CTitle::Update(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard *pInputKeyboard = pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	
	//CInputPad�^�̃|�C���^
	CInputPad *pInputPad = pInputPad = CManager::GetInstance()->GetInputPad();
	
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �J�����̏��擾
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// �^�C�g���J����
	pCamera->Title();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true ||
		pInputKeyboard->GetTrigger(DIK_SPACE) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		pSound->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);

		// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TUTORIAL);
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n�^�C�g��\n");
}

//=======================================
//�`��
//=======================================
void CTitle::Draw(void)
{
}
