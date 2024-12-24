//=======================================
//
//�e����[bullet.h]
//Author : MORIKAWA SHUNYA
//
//=======================================

#ifndef _BULLET_H_     //���̃}�N����`����`����Ă��Ȃ�������
#define _BULLET_H_     //2�A�C���N���[�h�h�~�̃}�N�����`����

#include "main.h"
#include "billboard.h"

//=======================================
// �萔��`
//=======================================
namespace
{
	const int MAX_BULLET = 128;		// �e�̍ő吔
}

//===========================================
//�G�t�F�N�g�N���X
//===========================================
class CBullet : public CBillboard
{
public:

	CBullet();		//�R���X�g���N�^
	~CBullet();		//�f�X�g���N�^

	//�����o�֐�
	static CBullet* Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& move, int nLife);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void CollisionPlayer(const D3DXVECTOR3& pos);
	void CollisionCircle();

private:
	//�����o�ϐ�
	int m_nLife;			// ����(�\������)

};

#endif
