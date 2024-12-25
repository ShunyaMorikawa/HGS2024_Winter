//=======================================
//
//�e[bullet.cpp]
//Author : MORIKAWA SHUNYA
//
//=======================================

#include "bullet.h"
#include "debugproc.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "game.h"
#include "enemy.h"
#include "player.h"
#include "particle.h"

//=======================================
// �萔��`
//=======================================
namespace
{
	const int DAMAGE = 1;	// �q�b�g���̃_���[�W
	const float BULLET_SIZE = 150.0f;	// �e�̍ő吔
}

//===========================================
//�R���X�g���N�^
//===========================================
CBullet::CBullet()
{
}

//===========================================
//�f�X�g���N�^
//===========================================
CBullet::~CBullet()
{
}

//===========================================
//����
//===========================================
CBullet* CBullet::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& move, int nLife)
{
	//CBullet�^�̃|�C���^
	CBullet* pEffect = nullptr;

	if (pEffect == nullptr)
	{//nullptr�̎�
		//�C���X�^���X����
		pEffect = new CBullet;

		pEffect->SetPos(pos);
		pEffect->SetMove(move);
		pEffect->m_nLife = nLife;

		//������
		pEffect->Init();
	}

	//�|�C���^��Ԃ�
	return pEffect;
}

//===========================================
//������
//===========================================
HRESULT CBullet::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//������
	CBillboard::Init();

	// �T�C�Y�ݒ�
	SetSize(BULLET_SIZE, BULLET_SIZE);

	BindTexture(pTexture->Regist("data\\texture\\effect000.png"));

	//������Ԃ�
	return S_OK;
}

//===========================================
//�I��
//===========================================
void CBullet::Uninit(void)
{
	//�I��
	CBillboard::Uninit();
}

//===========================================
//�X�V
//===========================================
void CBullet::Update(void)
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();
	D3DXCOLOR col = GetCol();

	// �X�V
	CBillboard::Update();

	// �ʒu�X�V
	pos += move;

	if (m_nLife % 2 == 0)
	{
		Myparticle::Create(Myparticle::TYPE::TYPE_BULLET, pos);
	}

	// �ʒu�ݒ�
	SetPos(pos);

	// �̗͌��Z
	m_nLife--;

	if (m_nLife < 0)
	{
		//�j������
		Uninit();
	}

	// �v���C���[�Ƃ̓����蔻��
	CollisionPlayer(pos);

	// ���Z��Ƃ̓����蔻��
	CollisionCircle();
}

//===========================================
//�`��
//===========================================
void CBullet::Draw(void)
{
	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//CRenderer�^�̃|�C���^
	CRenderer* pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�A���t�@�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//Z�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�A���t�@�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//z�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}

//===========================================
// �v���C���[�Ƃ̓����蔻��
//===========================================
void CBullet::CollisionPlayer(const D3DXVECTOR3& pos)
{
	// ����
	float fLength;

	float fRadius = GetSize();

	// �v���C���[�̏��擾
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer == nullptr)
	{
		return;
	}

	// �v���C���[�̈ʒu
	D3DXVECTOR3 posPlayer = pPlayer->GetPos();

	// �x�N�g�������߂�
	D3DXVECTOR3 vec = posPlayer - pos;

	//�x�N�g�����
	fLength = D3DXVec3Length(&vec);
}

//===========================================
// ���Z��Ƃ̓����蔻��
//===========================================
void CBullet::CollisionCircle()
{
	// �v���C���[�ʒu
	D3DXVECTOR3 posBullet = GetPos();
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &posBullet);

	if (USEFUL::CollisionCircle(posBullet, Constance::ARENA_SIZE))
	{// ���Z��ɓ���������
		Uninit();

		// �p�[�e�B�N������
		Myparticle::Create(Myparticle::TYPE_DEATH, posBullet);
	}

	// �ʒu�ݒ�
	SetPos(posBullet);
}
