//========================================
//
//�`���[�g���A��[tutorial.h]
//Author�F�X��x��
//
//========================================

#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "main.h"
#include "manager.h"

//========================================
//�O���錾
//========================================
class CObjectX;
class CObject3D;
class CLight;
class CPlayer;
class CIdxMeshField;
class CField;
class CFade;
class CGauge;
class CObject2D;
class CMapObject;

//========================================
//�`���[�g���A���N���X
//========================================
class CTutorial : public CScene
{
public:
	CTutorial();	//�R���X�g���N�^
	~CTutorial();	//�f�X�g���N�^

	static CTutorial* GetInstance();

	//�����o�֐�
	static CTutorial *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static CTutorial* m_pTutorial;		// �`���[�g���A���̃|�C���^

	bool m_bEnd;				// �`���[�g���A���I�����ǂ���

	CObject2D* m_pObj2D;		// �I�u�W�F�N�g2D�̃|�C���^

	CFade* m_pFade;				// �t�F�[�h�̃|�C���^
};

#endif
