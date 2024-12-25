//========================================
//
// �G�}�l�[�W���[�̏���[enemy_manager.cpp]
// Author�F������
//
//========================================

#include "enemy.h"
#include "enemy_manager.h"
#include "debugproc.h"

//========================================
//���O���
//========================================
namespace
{
	
}

//�ÓI�����o�ϐ��錾-------------------
CEnemyManager* CEnemyManager::m_pEnemyManager = NULL;

//========================================
//�R���X�g���N�^
//========================================
CEnemyManager::CEnemyManager()
{//�l���N���A
	m_nCntEnemy = 0;
}

//========================================
//�f�X�g���N�^
//========================================
CEnemyManager::~CEnemyManager()
{
}

//========================================
// ����
//========================================
CEnemyManager* CEnemyManager::GetInstance()
{
	if (m_pEnemyManager == NULL)
	{
		m_pEnemyManager = new CEnemyManager;
		return m_pEnemyManager;
	}
	else
	{
		return m_pEnemyManager;
	}
}

//=====================================
// �}�l�[�W���[�̔j��
//=====================================
HRESULT CEnemyManager::Release(void)
{
	if (m_pEnemyManager != NULL)
	{
		m_pEnemyManager->Uninit();

		delete m_pEnemyManager;
		m_pEnemyManager = NULL;
	}

	return S_OK;
}

//========================================
// ������
//========================================
HRESULT CEnemyManager::Init()
{
	// �G�l�~�[����
	listEnemy.push_back(CEnemy::Create(Constance::ENEMY_TXT));
	m_nCntEnemy = 60;

	return S_OK;
}

//========================================
// �I��
//========================================
void CEnemyManager::Uninit(void)
{
	listEnemy.clear();
}

//========================================
// �X�V
//========================================
void CEnemyManager::Update(void)
{
	m_nCntEnemy++;

	if (m_nCntEnemy > 30)
	{
		std::list<CEnemy*>  listCollisionDef = listEnemy;
		for (auto itrCollision : listCollisionDef)
		{
			itrCollision->Uninit();
		}
	}

	if (m_nCntEnemy > 60)
	{
		m_nCntEnemy = 0;

		// �G�l�~�[����
		listEnemy.push_back(CEnemy::Create(Constance::ENEMY_TXT));
	}

	// �f�o�b�O�\��
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();
	pDebugProc->Print("�G�̐� : %d\n", (int)listEnemy.size());
}
