//=====================================
//
// 
// Author:������
//
//=====================================
#include "number.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CNumber::CNumber(int nPriority = 6) : CObject2D(nPriority)
{
	m_nNumber = 0;
}

CNumber::~CNumber()
{
}

//=====================================
// ��������
//=====================================
CNumber* CNumber::Create(void)
{
	CNumber* pObjectNumber;

	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//2D�I�u�W�F�N�g�̐���
	pObjectNumber = new CNumber();

	if (pObjectNumber != NULL)
	{
		//������
		if (FAILED(pObjectNumber->Init()))
		{
			pObjectNumber->Release();
		}

		pObjectNumber->BindTexture(pTexture->Regist("data\\TEXTURE\\number01.png"));
	}

	return pObjectNumber;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CNumber::Init(void)
{
	CObject2D::Init();

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CNumber::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CNumber::Update(void)
{
	SetVertexAnim(10, m_nNumber);

	//CObject2D::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CNumber::Draw(void)
{
	CObject2D::Draw();
}