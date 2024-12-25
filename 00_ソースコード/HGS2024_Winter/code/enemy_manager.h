//========================================
//
// �G�}�l�[�W���[�̏���[enemy_manager.h]
// Author�F������
//
//========================================

#ifndef _ENEMYMANAGER_H_
#define _ENEMYMANAGER_H_

#include <list>

//========================================
// �O���錾
//========================================
class CEnemy;

//========================================
//�G�l�~�[�N���X
//========================================
class CEnemyManager
{
public:
	

	CEnemyManager();		//�R���X�g���N�^
	~CEnemyManager();		//�f�X�g���N�^

	// �����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	std::list<CEnemy*>* GetListEnemy(int nIdx) { return &listEnemy[nIdx]; }

	static CEnemyManager* GetInstance();
	static HRESULT Release(void);

private:
	
	//�����o�ϐ�
	std::list<CEnemy*> listEnemy[3];
	int m_nCntEnemy;

	//�ÓI�����o�ϐ�
	static CEnemyManager* m_pEnemyManager;
};

#endif
