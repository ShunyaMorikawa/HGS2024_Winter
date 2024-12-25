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

//========================================
//�ÓI�����o�ϐ�
//========================================
CGame *CGame::m_pGame = nullptr;		// �Q�[���̃|�C���^

//========================================
// �萔��`
//========================================
namespace
{
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
m_pObj2D		(nullptr)	// �I�u�W�F�N�g2D�̃|�C���^
{
	m_pGame = nullptr;		// �Q�[���̃|�C���^
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

	// �v���C���[����
	CPlayer::Create(Constance::PLAYER_TXT);

	// �G�l�~�[����
	CEnemy::Create(Constance::ENEMY_TXT);

	// �t�B�[���h����
	CField::Create();

	// 4�����ɕǐ���
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	// �J�ڎ���
	m_nTransition = 0;

	//�|�[�Y�̏��
	m_bPause = false;

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

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pGame != nullptr)
	{//���[�h�j��
		delete m_pGame;
		m_pGame = nullptr;
	}
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

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

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
