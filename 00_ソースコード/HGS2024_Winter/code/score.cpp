//========================================
//
//�V���[�e�B���O�A�N�V����[score.cpp]
//Author�F�X��x��
//
//========================================
#include "score.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "debugproc.h"

//========================================
// �萔��`
//========================================
namespace
{
	const float SCORE_POS_X = 640.0f;
	const float SCORE_POS_Y = 320.0f;

	const std::string SCORE_TEXTURE = "data\\texture\\number.png";		//�e�N�X�`���ւ̃p�X
}

//========================================
//�ÓI�����o�ϐ�
//========================================
CNumber* CScore::m_apNumber[] = {};

//========================================
//�R���X�g���N�^
//========================================
CScore::CScore()
{
	m_Score = 0;			//�X�R�A�̒l
	m_nPatternAnim = 0;		//�X�R�A�p�^�[��No,

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		m_apNumber[nCnt] = nullptr;		//CNumber�̔z��
	}
}

//========================================
//�f�X�g���N�^
//========================================
CScore::~CScore()
{

}

//========================================
//�X�R�A����
//========================================
CScore* CScore::Create(const D3DXVECTOR3& pos)
{
	//CEnemy�^�̃|�C���^
	CScore* pScore = nullptr;

	if (pScore == nullptr)
	{//pScore��nullptr�̎�
		//�X�R�A�̐���
		pScore = new CScore;

		//������
		pScore->Init();

		//�X�R�A�̏����l
		pScore->SetScore(0);
	}

	//�|�C���^��Ԃ�
	return pScore;
}

//========================================
//������
//========================================
HRESULT CScore::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	D3DXVECTOR3 pos = GetPos();

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		if (m_apNumber[nCnt] == nullptr)
		{//nullptr�̎�
			//�X�R�A�̐���
			m_apNumber[nCnt] = CNumber::Create();

			if (m_apNumber[nCnt] != nullptr)
			{
				//�e�N�X�`���ݒ�
				m_apNumber[nCnt]->BindTexture(pTexture->Regist(SCORE_TEXTURE));

				//�X�R�A�̃T�C�Y
				m_apNumber[nCnt]->SetSize(60.0f, 60.0f);

				D3DXVECTOR3 posNum = pos;

				//�����̊Ԋu
				posNum.x += nCnt * 60.0f;

				//�ʒu�̐ݒ�
				m_apNumber[nCnt]->SetPos(D3DXVECTOR3(posNum.x - 70.0f, 35.0f, 0.0f));
			}
		}
	}

	//�X�R�A�̒l
	m_Score = 0;

	//������Ԃ�
	return S_OK;
}

//========================================
//�I��
//========================================
void CScore::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		if (m_apNumber[nCnt] != nullptr)
		{//nullptr����Ȃ���
			m_apNumber[nCnt]->Uninit();
			m_apNumber[nCnt] = nullptr;
		}
	}

	//�������g�̔j��
	CObject::Release();
}

//========================================
//�X�V
//========================================
void CScore::Update(void)
{
}

//========================================
//�`��
//========================================
void CScore::Draw(void)
{
}

//========================================
//�X�R�A�ݒ�
//========================================
void CScore::SetScore(int nScore)
{
	m_Score = nScore;

	int aTexU[MAX_SCORE];  //�e���̐������i�[

	aTexU[0] = m_Score % 100000000 / 10000000;
	aTexU[1] = m_Score % 10000000 / 1000000;
	aTexU[2] = m_Score % 1000000 / 100000;
	aTexU[3] = m_Score % 100000 / 10000;
	aTexU[4] = m_Score % 10000 / 1000;
	aTexU[5] = m_Score % 1000 / 100;
	aTexU[6] = m_Score % 100 / 10;
	aTexU[7] = m_Score % 10 / 1;

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{//��������
		m_apNumber[nCnt]->SetVertexAnim(10, aTexU[nCnt]);
	}
}
