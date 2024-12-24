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
}

//=======================================
//�R���X�g���N�^
//=======================================
CTutorial::CTutorial()
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
	// �t�B�[���h����
	CField::Create();

	// �ǐ���
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

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
	//CInputKeyboard���擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad���擾
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_RETURN)||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0))
	{
		// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n�`���[�g���A��\n");
}

//=======================================
//�`��
//=======================================
void CTutorial::Draw(void)
{
}
