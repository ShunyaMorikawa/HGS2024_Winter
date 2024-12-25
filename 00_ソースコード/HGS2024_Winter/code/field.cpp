//========================================
//
// �t�B�[���h[field.cpp]
// Author�F�X��x��
//
//========================================

#include "field.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//========================================
//���O���
//========================================
namespace
{
	const char* FIELD_TEX = "data\\texture\\snow.jpg";	// �n�ʂ̃e�N�X�`��
}

//========================================
//�ÓI�����o�ϐ�
//========================================
LPDIRECT3DTEXTURE9 CField::m_pTexture = nullptr;

//========================================
//�R���X�g���N�^
//========================================
CField::CField(int nPriority) : CObject3D(nPriority)
{
}

//========================================
//�f�X�g���N�^
//========================================
CField::~CField()
{
}

//========================================
//�|���S������
//========================================
CField* CField::Create(void)
{
	//CPlayer�^�̃|�C���^
	CField* pField = new CField;;

	//������
	pField->Init();

	//�|�C���^��Ԃ�
	return pField;
}

//========================================
//������
//========================================
HRESULT CField::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	// �p���̏�����
	CObject3D::Init();

	//�e�N�X�`�����蓖��
	BindTexture(pTexture->Regist(FIELD_TEX));

	return S_OK;
}

//========================================
//�I��
//========================================
void CField::Uninit(void)
{
	// �p���̏�����
	CObject3D::Uninit();
}

//========================================
//�X�V
//========================================
void CField::Update(void)
{
	// �p���̏�����
	CObject3D::Update();
}

//========================================
//�`��
//========================================
void CField::Draw(void)
{
	//�`��
	CObject3D::Draw();
}
