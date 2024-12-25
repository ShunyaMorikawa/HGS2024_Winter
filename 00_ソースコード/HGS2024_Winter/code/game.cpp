//========================================
//
//�Q�[��������[game.cpp]
//Author�F�X��x��
//
//========================================

#include "game.h"
#include "camera.h"
#include "input.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "enemy.h"
#include "fade.h"
#include "wall.h"
#include "mapobject.h"
#include "sound.h"
#include "debugproc.h"
#include "texture.h"
#include "useful.h"
#include "enemy_manager.h"
#include "score.h"
#include "timer.h"

//========================================
//�ÓI�����o�ϐ�
//========================================
CGame *CGame::m_pGame = nullptr;		// �Q�[���̃|�C���^

//========================================
// �萔��`
//========================================
namespace
{
	const int STATE_TIME[CGame::STATE_MAX] =
	{
		30,
		30,
		30,
		60,
	};// �v���C���[�̖ڕW�ʒu
}

//========================================
//�R���X�g���N�^
//========================================
CGame::CGame() : 
m_bPause		(false),	// �|�[�Y
m_nTransition	(0),		// �J�ڎ���
m_pObjectX		(nullptr),	// �I�u�W�F�N�gX�̃|�C���^
m_pIdxMesh		(nullptr),	// �C���f�b�N�X���b�V���̃|�C���^
m_pFade			(nullptr),	// �t�F�[�h�̃|�C���^
m_pObj2D		(nullptr),	// �I�u�W�F�N�g2D�̃|�C���^
m_pTime			(nullptr)
{
	m_pGame = nullptr;		// �Q�[���̃|�C���^
	m_state = STATE_START;
}

//========================================
//�f�X�g���N�^
//========================================
CGame::~CGame()
{
}

//========================================
// �V���O���g��
//========================================
CGame* CGame::GetInstance()
{
	if (m_pGame == nullptr)
	{//�C���X�^���X����
		return m_pGame = new CGame;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pGame;
	}
}

//========================================
//����
//========================================
CGame *CGame::Create(void)
{
	if (m_pGame == nullptr)
	{
		//�C���X�^���X����
		m_pGame = new CGame;
		m_pGame->Init();
	}

	//�|�C���^��Ԃ�
	return m_pGame;
}

//========================================
//������
//========================================
HRESULT CGame::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//�e�N�X�`���̃|�C���^
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �v���C���[����
	CPlayer::Create(Constance::PLAYER_TXT);

	m_pEnemyManager = CEnemyManager::GetInstance();
	m_pEnemyManager->Init();

	// �t�B�[���h����
	CField::Create();

	// �X�R�A����
	m_pScore = CScore::Create(D3DXVECTOR3(410.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);

	if (m_pTime == nullptr)
	{// �^�C������
		m_pTime = CTimer::Create(D3DXVECTOR3(640.0f, 320.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 80.0f, 50.0f);
	}

	// �J�ڎ���
	m_nTransition = 0;

	//�|�[�Y�̏��
	m_bPause = false;

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_GAME);

	return S_OK;
}

//========================================
//�I��
//========================================
void CGame::Uninit(void)
{
	if(m_pObj2D != nullptr)
	{
		m_pObj2D->Uninit();
		m_pObj2D = nullptr;
	}

	if (m_pTime != nullptr)
	{
		m_pTime->Uninit();
		m_pTime = nullptr;
	}

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pGame != nullptr)
	{//���[�h�j��
		delete m_pGame;
		m_pGame = nullptr;
	}

	m_pEnemyManager->Release();
}

//========================================
//�X�V
//========================================
void CGame::Update(void)
{
	// CInputKeyboard�^�̃|�C���^
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �v���C���[�̏��擾
	CPlayer* pPlayer = CPlayer::GetInstance();

	m_pEnemyManager->Update();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	m_nTransition++;

	if (m_nTransition > STATE_TIME[m_state])
	{
		m_nTransition = 0;

		switch (m_state)
		{
		case CGame::STATE_WAIT:
			m_state = STATE_START;
			break;
		case CGame::STATE_START:
			m_state = STATE_GAME;
			break;
		case CGame::STATE_GAME:
			break;
		case CGame::STATE_FINISH:
			break;
		case CGame::STATE_MAX:
			m_state = STATE_START;
			break;
		default:
			break;
		}
	}

	// �f�o�b�O�\��
	pDebugProc->Print("\n�Q�[��\n");

#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_F2) == true)
	{// �Q�[����ʂɑJ��
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// �Q�[����ʂɑJ��
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
	}
#endif
}

//========================================
//�`��
//========================================
void CGame::Draw(void)
{
}
