//========================================
//
//�V���[�e�B���O�A�N�V����[title.h]
//Author�F�X��x��
//
//========================================

#ifndef _TITLE_H_
#define _TITLE_H_

#include "main.h"
#include "manager.h"
#include "object2D.h"
#include "renderer.h"

//========================================
// �O���錾
//========================================
class CPress_Enter;

//========================================
//�^�C�g���N���X
//========================================
class CTitle : public CScene
{
public:
	CTitle();	//�R���X�g���N�^
	~CTitle();	//�f�X�g���N�^

	static CTitle* GetInstance();

	//�����o�֐�
	static CTitle *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static CTitle* m_pTitle;		// �`���[�g���A���̃|�C���^
	CObject2D* m_pObject2D;
	CPress_Enter* m_pEnter;
};

#endif
