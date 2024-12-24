//========================================
//
// �E�H�[��[wall.cpp]
// Author�F�X��x��
//
//========================================

#include "wall.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//========================================
// ���O���
//========================================
namespace
{
	const char* SKY_TEX = "data\\texture\\sky_02.jpg";	// �w�i�̃e�N�X�`��

	float U_TEX = 0.0001f;	// �e�N�X�`�����W�̍X�V�l
}

//========================================
// �ÓI�����o�ϐ�
//========================================
LPDIRECT3DTEXTURE9 CWall::m_pTexture = nullptr;

//========================================
// �R���X�g���N�^
//========================================
CWall::CWall(int nPriority) : CObject3D(nPriority),
m_aTexU		(0.0f)	// �e�N�X�`����U�l
{
}

//========================================
// �f�X�g���N�^
//========================================
CWall::~CWall()
{
}

//========================================
// �ǐ���
//========================================
CWall* CWall::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot)
{
	// CWall�^�̃|�C���^
	CWall* pWall = new CWall;

	//������
	pWall->Init();

	pWall->SetPos(pos);
	pWall->SetRot(rot);

	//�|�C���^��Ԃ�
	return pWall;
}

//========================================
// ������
//========================================
HRESULT CWall::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �p���̏�����
	CObject3D::Init();

	// U�l�̏�����
	m_aTexU = 0.0f;

	//�e�N�X�`�����蓖��
	BindTexture(pTexture->Regist(SKY_TEX));

	return S_OK;
}

//========================================
// �I��
//========================================
void CWall::Uninit(void)
{
	// �p���̏�����
	CObject3D::Uninit();
}

//========================================
// �X�V
//========================================
void CWall::Update(void)
{
	CObject3D::Update();

	//�e�N�X�`�����W�̍X�V(U�l)
	m_aTexU += U_TEX;
}

//========================================
// �`��
//========================================
void CWall::Draw(void)
{
	//�`��
	CObject3D::Draw();
}

//========================================
// ���_���ݒ�
//========================================
void CWall::SetVertex3D()
{
	CObject3D::SetVertex3D();

	// ���_���̎擾
	LPDIRECT3DVERTEXBUFFER9 Vertex = CObject3D::GetVtxBuff();

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	Vertex->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(m_aTexU, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_aTexU + 0.3f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_aTexU, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_aTexU + 0.3f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	Vertex->Unlock();
}
