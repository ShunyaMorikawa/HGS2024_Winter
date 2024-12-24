//=======================================
//
//�G�t�F�N�g����[effect.h]
//Author : MORIKAWA SHUNYA
//
//=======================================

#ifndef _LOCKONMARKER_H_     //���̃}�N����`����`����Ă��Ȃ�������
#define _LOCKONMARKER_H_     //2�A�C���N���[�h�h�~�̃}�N�����`����

#include "billboard.h"

//===========================================
//�G�t�F�N�g�N���X
//===========================================
class CLockonMarker : public CBillboard
{
public:
	CLockonMarker(int nPriority = 5);		//�R���X�g���N�^
	~CLockonMarker();		//�f�X�g���N�^

	//�����o�֐�
	static CLockonMarker* Create(bool alpha);

	HRESULT Init(bool alpha);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	// �����o�ϐ�
	bool m_bAlpha;		// ���Z����
};

#endif
