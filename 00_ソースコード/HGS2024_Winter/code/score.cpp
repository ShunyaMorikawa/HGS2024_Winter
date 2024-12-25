//=====================================
//
// 
// Author:������
//
//=====================================
#include "score.h"
#include "renderer.h"
#include "manager.h"
#include "object2D.h"
#include "number.h"
#include "useful.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
int CScore::m_nScoreResult = 0;
int CScore::m_nScore = 0;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CScore::CScore(int nPriority = 6) : CObject(nPriority)
{
	m_nScore = 0;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fWidth = 0.0f;
	m_fHeight = 0.0f;
	m_fHue = 0.0f;
	m_nScore = 0;
}

CScore::~CScore()
{
}

//=====================================
// ��������
//=====================================
CScore* CScore::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	CScore* pScore;

	//2D�I�u�W�F�N�g�̐���
	pScore = new CScore();

	if (pScore != NULL)
	{
		pScore->Set(pos, rot, fWidth, fHeight);

		//������
		if (FAILED(pScore->Init()))
		{
			pScore->Release();
		}
	}

	return pScore;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CScore::Init(void)
{
	for (int nCnt = 0; nCnt < MAX_PLACE; nCnt++)
	{
		m_apObject2D[nCnt] = CNumber::Create();

		if (m_apObject2D[nCnt] != NULL)
		{
			if (FAILED(m_apObject2D[nCnt]->Init()))
			{
				return E_FAIL;
			}

			m_apObject2D[nCnt]->SetPos(D3DXVECTOR3(m_pos.x - (m_fWidth + 5.0f) * nCnt, m_pos.y, 0.0f));
			m_apObject2D[nCnt]->SetRot(m_rot);
			m_apObject2D[nCnt]->SetSize(m_fWidth, m_fHeight);
			m_apObject2D[nCnt]->SetNumber(0);
		}
	}

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CScore::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_PLACE; nCnt++)
	{
		if (m_apObject2D[nCnt] != NULL)
		{
			m_apObject2D[nCnt]->Uninit();
		}
	}

	Release();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CScore::Update(void)
{
	m_posOld = m_pos;

	if (m_nScore < 0)
	{
		m_nScore = 0;
	}

	for (int nCnt = 0; nCnt < MAX_PLACE; nCnt++)
	{
		if (m_apObject2D[nCnt] != NULL)
		{
			D3DXVECTOR2* texPos = NULL;
			m_apObject2D[nCnt]->SetNumber(m_nScore % (int)pow(10, nCnt + 1) / (int)pow(10, nCnt));

			m_apObject2D[nCnt]->Update();
		}
	}
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CScore::Draw(void)
{

}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void CScore::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	m_pos = pos;
	m_rot = rot;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
}
