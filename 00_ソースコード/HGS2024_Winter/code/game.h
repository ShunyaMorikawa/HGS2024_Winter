//========================================
//
//�Q�[��������[game.h]
//Author�F�X��x��
//
//========================================

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "manager.h"

//========================================
//�O���錾
//========================================
class CObjectX;
class CObject2D;
class CObject3D;
class CLight;
class CPlayer;
class CIdxMeshField;
class CField;
class CEnemy;
class CFade;
class CGauge;
class CWall;
class CMapObject;
class CEnemyManager;

//========================================
// �萔��`
//========================================
namespace
{
	const int ITEM_MAX = 256;	// �A�C�e���̍ő吔
}

//========================================
//�Q�[���N���X
//========================================
class CGame : public CScene
{
public:
	CGame();	//�R���X�g���N�^
	~CGame();	//�f�X�g���N�^

	//�����o�֐�
	static CGame *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void PauseState(bool bPauseState) { m_bPause = bPauseState; }	//�|�[�Y��Ԃ��ǂ���

	static CGame* GetInstance();		// �Q�[���}�l�[�W���[�̏��
	
private:
	static CGame *m_pGame;		// �Q�[���}�l�[�W���[�̃|�C���^

	int m_nTransition;			// �J�E���^�[

	bool m_bPause;				// �|�[�Y��Ԃ�ON/OFF

	CObjectX *m_pObjectX;		// X�t�@�C���I�u�W�F�N�g�̃|�C���^
	CIdxMeshField *m_pIdxMesh;	// ���b�V���t�B�[���h�̃|�C���^
	CFade* m_pFade;				// �t�F�[�h�̃|�C���^
	CObject2D* m_pObj2D;		// �I�u�W�F�N�g2D�̃|�C���^
	CEnemyManager* m_pEnemyManager;	// �G�}�l�[�W���[�̃|�C���^
};

#endif
