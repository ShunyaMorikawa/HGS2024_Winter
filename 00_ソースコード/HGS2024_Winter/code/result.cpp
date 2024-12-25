//========================================
//
// ���U���g[result.h]
// Author�F�X��x��
//
//========================================

#include "result.h"
#include "texture.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "camera.h"
#include "field.h"
#include "mapobject.h"
#include "wall.h"
#include "useful.h"
#include "resultplayer.h"
#include "debugproc.h"
#include "score.h"

//========================================
// �萔��`
//========================================
namespace
{
	const std::string RESULT_PLAYER_TXT = "data\\FILE\\resultplayer.txt";	// �v���C���[���̃p�X
}

//========================================
// �ÓI�����o�ϐ�
//========================================
CResult* CResult::m_pResult = nullptr;

//=======================================
//�R���X�g���N�^
//=======================================
CResult::CResult()
{
	
}

//=======================================
//�f�X�g���N�^
//=======================================
CResult::~CResult()
{
}

//=======================================
//�V���O���g��
//=======================================
CResult* CResult::GetInstance()
{
	if (m_pResult == nullptr)
	{//�C���X�^���X����
		return m_pResult = new CResult;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pResult;
	}
}

//=======================================
//����
//=======================================
CResult* CResult::Create(void)
{
	if (m_pResult == nullptr)
	{
		//�C���X�^���X����
		m_pResult = new CResult;

		//������
		m_pResult->Init();
	}

	//�|�C���^��Ԃ�
	return m_pResult;
}

//=======================================
//������
//=======================================
HRESULT CResult::Init(void)
{
	// �J�����̏��擾
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �J�����̏�����
	pCamera->Init();

	// �t�B�[���h����
	CField::Create();

	// 4�����ɕǐ���
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, -Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	CWall::Create(D3DXVECTOR3(0.0f, Constance::WALL_POS_Y, Constance::WALL_POS), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI, 0.0f));
	CWall::Create(D3DXVECTOR3(Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, -D3DX_PI * 0.5f, 0.0f));
	CWall::Create(D3DXVECTOR3(-Constance::WALL_POS, Constance::WALL_POS_Y, 0.0f), D3DXVECTOR3(D3DX_PI * 0.5f, D3DX_PI * 0.5f, 0.0f));

	FILE* pFile;

	//�t�@�C���������ǂݍ���
	pFile = fopen("data\\RANKING\\ranking.bin", "rb");

	int nScore[6] = {};

	if (pFile != NULL)
	{//�J�����ꍇ
		fread(&nScore[0], sizeof(int), 6, pFile);
		fclose(pFile);
	}
	else
	{//�J���Ȃ������ꍇ

	 //�����L���O������
		for (int nCnt = 0; nCnt < 6; nCnt++)
		{
			nScore[nCnt] = 0;
		}
	}

	nScore[5] = CScore::GetScoreResult();

	int nMaxNumber, nTemp;
	//�~���}���\�[�g
	for (int nCnt1 = 1; nCnt1 < 6; nCnt1++)
	{
		nMaxNumber = nCnt1;

		while (nMaxNumber > 0 && nScore[nMaxNumber - 1] < nScore[nMaxNumber])
		{
			nTemp = nScore[nMaxNumber - 1];
			nScore[nMaxNumber - 1] = nScore[nMaxNumber];
			nScore[nMaxNumber] = nTemp;

			nMaxNumber--;
		}
	}

	//�t�@�C���������ǂݍ���
	pFile = fopen("data\\RANKING\\ranking.bin", "wb");

	if (pFile != NULL)
	{//�J�����ꍇ

		fwrite(&nScore[0], sizeof(int), 6, pFile);
		fclose(pFile);
	}
	else
	{//�J���Ȃ������ꍇ

	}

	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		m_pScore[nCnt] = CScore::Create(D3DXVECTOR3(800.0f, 101.0f * nCnt + 235.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);
		m_pScore[nCnt]->AddScore(nScore[nCnt]);
	}

	m_pScore[5] = CScore::Create(D3DXVECTOR3(800.0f, 70.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);
	m_pScore[5]->AddScore(CScore::GetScoreResult());

	pSound->PlaySound(CSound::SOUND_LABEL_BGM_RESULT);

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CResult::Uninit(void)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pResult != nullptr)
	{//���[�h�j��
		delete m_pResult;
		m_pResult = nullptr;
	}
}

//=======================================
//�X�V
//=======================================
void CResult::Update(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad�^�̃|�C���^
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �J�����̏��擾
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// ���U���g�J����
	pCamera->Result();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n���U���g\n");
}

//=======================================
//�`��
//=======================================
void CResult::Draw(void)
{
}
