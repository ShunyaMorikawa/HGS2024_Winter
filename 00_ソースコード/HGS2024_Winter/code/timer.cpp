//=====================================
//
// 
// Author:������
//
//=====================================
#include "timer.h"
#include "renderer.h"
#include "manager.h"
#include "object2D.h"
#include "number.h"
#include "useful.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
int CTimer::m_nScoreResult = 0;

//=====================================
// �萔��`
//=====================================
namespace
{
	const int TIME_LIMIT = 3600;

	const int TIME_DIGIT = 3;
}

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CTimer::CTimer(int nPriority = 6) : CObject(nPriority)
{
	m_nScore = 0;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fWidth = 0.0f;
	m_fHeight = 0.0f;
	m_fHue = 0.0f;
	m_nScore = 0;
	m_nTimer = 0;
}

CTimer::~CTimer()
{
}

//=====================================
// ��������
//=====================================
CTimer* CTimer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	CTimer* pScore;

	//2D�I�u�W�F�N�g�̐���
	pScore = new CTimer();

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
HRESULT CTimer::Init(void)
{
	m_nTimer = TIME_LIMIT;

	m_nScore = 60;

	m_nTimeCounter = 0;

	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
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
void CTimer::Uninit(void)
{
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
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
void CTimer::Update(void)
{
	--m_nTimer;
	++m_nTimeCounter;

	if (m_nTimer < 0)
	{
		m_nTimer = 0;
	}

	if (m_nTimeCounter > 60)
	{
		AddScore(-1);

		m_nTimeCounter = 0;
	}

	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		if (m_apObject2D[nCnt] != NULL)
		{
			D3DXVECTOR2* texPos = NULL;
			m_apObject2D[nCnt]->SetNumber(m_nScore % (int)pow(10, nCnt + 1) / (int)pow(10, nCnt));

			m_apObject2D[nCnt]->Update();
		}
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("�Q�[������ : %d\n", m_nTimer);

}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CTimer::Draw(void)
{

}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void CTimer::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	m_pos = pos;
	m_rot = rot;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
}
