//===============================================
//
// 2D�|���S��(object2D.cpp)
// Author ���c ����
//
//===============================================

//============================
// �C���N���[�h�t�@�C��
//============================
#include "press_enter.h"
#include "texture.h"

//============================
// �}�N����`
//============================
namespace
{
	const D3DXVECTOR3 DEF_SIZE_ENTER = D3DXVECTOR3(90.0f * 1.5f, 90.0f, 0.0f);				//�f�t�H���g�T�C�Y
}

//============================
// �O���錾
//============================
//class CPlayer;

//============================
// �ÓI�����o�ϐ��錾
//============================

//============================
// �R���X�g���N�^(�f�t�H)
//============================
CPress_Enter::CPress_Enter(int nPriority) : CObject2D(nPriority)
{
	m_nAlphaCnter = 0;						//PRESS ENTER�̓_�ŊԊu�̔���
	m_nTimeInterval = 0;					//PRESS ENTER�̓_�ŊԊu
	m_fAlphaColor = 0.0f;					//���_�J���[
}

//============================
// �f�X�g���N�^
//============================
CPress_Enter::~CPress_Enter()
{

}

//====================================
// 2D�|���S���̏���������(�f�t�H)
//====================================
HRESULT CPress_Enter::Init(void)
{
	m_nTimeInterval = 50;						//�_�ŊԊu������������
	m_fAlphaColor = 1.0f;
	m_nAlphaCnter = 0;

	CObject2D::Init();

	SetSize(DEF_SIZE_ENTER.x, DEF_SIZE_ENTER.y);

	return S_OK;
}

//====================================
// 2D�|���S���̏�����(�ʒu�I�o��)
//====================================
HRESULT CPress_Enter::Init(const D3DXVECTOR3 pos)
{
	CPress_Enter::Init();

	SetPos(pos);

	return S_OK;
}

//============================
// 2D�|���S���̏I������
//============================
void CPress_Enter::Uninit(void)
{
	CObject2D::Uninit();
}

//============================
// 2D�|���S���̍X�V����
//============================
void CPress_Enter::Update(void)
{
	CObject2D::Update();

	m_nAlphaCnter++;

	if (m_nAlphaCnter % m_nTimeInterval == 0)
	{//0.5�b��������

		m_nAlphaCnter = 0;
		D3DXCOLOR col = GetCol();

		if (col.a < 1.0f)
		{
			col.a = 1.0f;
			col.r = 1.0f;
			col.b = 1.0f;
			col.g = 1.0f;
		}
		else if (col.a >= 1.0f)
		{
			col.a = 0.0f;
			col.r = 0.0f;
			col.b = 0.0f;
			col.g = 0.0f;
		}

		m_fAlphaColor = col.a;
		SetCol(col);
	}
}

//============================
// 2D�|���S���̕`�揈��
//============================
void CPress_Enter::Draw(void)
{
	CObject2D::Draw();
}

//============================
// 2D�|���S���̐�������
//============================
CPress_Enter * CPress_Enter::Create(void)
{
	CPress_Enter *pEnter;

	//�I�u�W�F�N�g����
	pEnter = new CPress_Enter;

	//������
	pEnter->Init();

	//�e�N�X�`���t�^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	pEnter->BindTexture(pTexture->Regist("data\\TEXTURE\\PressEnter00.png"));

	return pEnter;
}

//============================
// 2D�|���S���̐�������
//============================
CPress_Enter * CPress_Enter::Create(const D3DXVECTOR3 pos)
{
	CPress_Enter *pEnter = new CPress_Enter;

	if (pEnter != nullptr)
	{
		pEnter->Init(pos);
	
		//�e�N�X�`���t�^
		CTexture* pTexture = CManager::GetInstance()->GetTexture();
		pEnter->BindTexture(pTexture->Regist("data\\TEXTURE\\PressEnter00.png"));
	}
	else
	{
		return nullptr;
	}

	return pEnter;
}
