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
	const int MAX_ENEMY = 10;				// �̗�
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
	return S_OK;
}

//========================================
// �I��
//========================================
void CEnemyManager::Uninit(void)
{
	for (int i = 0; i < 3; i++)
	{
		listEnemy[i].clear();
	}
}

//========================================
// �X�V
//========================================
void CEnemyManager::Update(void)
{
	m_nCntEnemy++;

	if (m_nCntEnemy < 30) { return; }

	int nLane = rand() % 3;

	// �G�̐�����萔��������o���Ȃ�
	if ((int)listEnemy[nLane].size() > MAX_ENEMY) { return; }

	m_nCntEnemy = 0;

	CEnemy* pEnemy;
	if (rand() % 100 > 75)
	{
		// �G�l�~�[����
		pEnemy = CEnemyOtaku::Create(Constance::OTAKU_TXT[0]);
	}
	else
	{
		// �G�l�~�[����
		pEnemy = CEnemyChild::Create(Constance::ENEMY_TXT);
	}

	// �G�ɏ���ݒ�
	if (listEnemy[nLane].empty())
	{
		pEnemy->SetParent(nullptr);
	}
	else
	{
		CEnemy* pEnemyParent = listEnemy[nLane].back();
		pEnemy->SetParent(pEnemyParent);
		pEnemyParent->SetChild(pEnemy);
	}
	
	pEnemy->SetNumLane(nLane);
	listEnemy[nLane].push_back(pEnemy);
}
