//=======================================
//
//�J����[camera.cpp]
//Author : MORIKAWA SHUNYA
//
//=======================================

#include "camera.h"   
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "debugproc.h"
#include "useful.h"

//=======================================
// �萔��`
//=======================================
namespace
{
	const float CAMERA_POS_Y = 200.0f;		// �J������Y���W�̏����ʒu
	const float CAMERA_POS_Z = -850.0f;	// �J������Z���W�̏����ʒu
	const float CAMERA_DISTANCE = 400.0f;	// �J�����Ƃ̋���
	const float CAMERA_SPEED = 1.5f;		// �J�����̈ړ����x
	const float CMAERA_INERTIA = 0.2f;		// �J�����̊���
	const float CAMERA_R_DISTANCE = 25.0f;	// �����_�̋���
	const float CAMERA_V_MOVE = 0.03f;		// ���_�̈ړ����x
	const float CAMERA_R_INERTIA = 0.2f;	// �����_�̊���
	const float CAMERA_V_INERTIA = 0.2f;	// ���_�̊���
	const float CAMERA_DISTANCE_TITLE = 300.0f;	// �J����
	const float VIEWING = 100.0f;	// ����p
	const float TITLE_DISTANCE = 300.0f;	// �^�C�g����ʂ̃J�����Ƃ̋���
	const float RESULT_DISTANCE = 400.0f;	// ���U���g��ʂ̃J�����Ƃ̋���
}

//=======================================
//�R���X�g���N�^
//=======================================
CCamera::CCamera() : 
m_posV		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// ���_
m_posR		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �����_
m_vecU		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// ������x�N�g��
m_rot		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// ����
m_move		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �ړ���
m_VDest		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �ړI�̎��_
m_RDest		(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �ړI�̒����_
m_fDistance	(0.0f)								// ����
{
}

//=======================================
//�f�X�g���N�^
//=======================================
CCamera::~CCamera()
{

}

//=======================================
//�J�����̏���������
//=======================================
HRESULT CCamera::Init(void)
{
	//���_
	m_posV = D3DXVECTOR3(0.0f, CAMERA_POS_Y, CAMERA_POS_Z);

	//�����_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//������x�N�g��
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//����
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ړI�̎��_�E�����_
	m_VDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_RDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�v���C���[�ƃJ�����̋���
	m_fDistance = CAMERA_DISTANCE;

	// ���_�E�����_
	m_posV.x = m_posR.x + sinf(m_rot.y) * m_fDistance;
	m_posV.z = m_posR.z + cosf(m_rot.y) * m_fDistance;

	//������Ԃ�
	return S_OK;
}

//=======================================
//�J�����̏I������
//=======================================
void CCamera::Uninit(void)
{

}

//=======================================
//�J�����̍X�V����
//=======================================
void CCamera::Update(void)
{	
	//CDebugProc�^�|�C���^
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDebugProc();

	//���_�̈ړ�
	CameraMoveV();

	// ���Z��Ƃ̔���
	CollisionArena();

#ifdef _DEBUG
	//�f�o�b�O�\��
	pDebugProc->Print("\n���_�̈ʒu�F%f�A%f�A%f\n", m_posV.x, m_posV.y, m_posV.z);
	pDebugProc->Print("�����_�̈ʒu�F%f�A%f�A%f\n", m_posR.x, m_posR.y, m_posR.z);
	pDebugProc->Print("�J�����̌����F%f�A%f�A%f\n", m_rot.x, m_rot.y, m_rot.z);
#endif

}

//=======================================
//�J�����̐ݒ菈��
//=======================================
void CCamera::SetCamera(void)
{
	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬[�������e]
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,		//�v���W�F�N�V�����}�g���b�N�X
								D3DXToRadian(VIEWING),	//����p
								(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,		//�A�X�y�N�g��
								10.0f,		//Z�l�̍ŏ��l
								400000.0f);	//Z�l�̍ő�l(�`�拗��)

	////�v���W�F�N�V�����}�g���b�N�X��ݒ�[���s���e]
	//D3DXMatrixOrthoLH(&m_mtxProjection,		//�v���W�F�N�V�����}�g���b�N�X
	//					SCREEN_WIDTH,	//��ʂ̕�
	//					SCREEN_HEIGHT,	//��ʂ̍���
	//					10.0f,		//Z�l�̍ŏ��l
	//					1000.0f);	//Z�l�̍ő�l

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
						&m_posV,	//���_
						&m_posR,	//�����_
						&m_vecU);	//������x�N�g��

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//=======================================
//�����_�̈ړ�
//=======================================
void CCamera::CameraMoveV(void)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard *pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾
	CInputPad *pInputPad = nullptr; 
	pInputPad = CManager::GetInstance()->GetInputPad();

	//C�L�[�������ꂽ
	if (pInputKeyboard->GetPress(DIK_C) == true
		|| pInputPad->GetRStickXPress(CInputPad::BUTTON_R_STICK, 0) > 0)
	{
		m_rot.y += CAMERA_V_MOVE;

		//�p�x�̐��K��
		m_rot.y = RotNor(m_rot.y);
	}
	//Z�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_Z) == true
			 || pInputPad->GetRStickXPress(CInputPad::BUTTON_R_STICK, 0) < 0)
	{
		m_rot.y -= CAMERA_V_MOVE;

		//�p�x�̐��K��
		m_rot.y = RotNor(m_rot.y);
	}

	//�ʒu���X�V
	m_posV += m_move;
	m_posR += m_move;

	//�ړ��ʂ��X�V(����������)
	m_move.x += (0.0f - m_move.x) * CMAERA_INERTIA;
	m_move.y += (0.0f - m_move.y) * CMAERA_INERTIA;
	m_move.z += (0.0f - m_move.z) * CMAERA_INERTIA;
}

//=======================================
//rot�̐��K��
//=======================================
float CCamera::RotNor(float RotN)
{
	//3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (RotN > D3DX_PI)
	{
		RotN -= D3DX_PI * 2;
	}

	//-3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (RotN < -D3DX_PI)
	{
		RotN += D3DX_PI * 2;
	}

	return RotN;
}

//=======================================
//�J�����Ǐ]
//=======================================
void CCamera::following(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot)
{
	//�����_
	D3DXVECTOR3 Diff;

	//���_
	D3DXVECTOR3 VDiff;

	m_rot.y = rot.y;

	//�����_
	m_RDest = D3DXVECTOR3(
		pos.x + -sinf(rot.y) 
		* CAMERA_R_DISTANCE,
		pos.y, 
		pos.z + -cosf(rot.y) * 25.0f);

	m_VDest.x = m_RDest.x + sinf(m_rot.y) * m_fDistance;
	m_VDest.z = m_RDest.z + cosf(m_rot.y) * m_fDistance;

	//�����_
	Diff = D3DXVECTOR3(m_RDest.x - m_posR.x, 
		0.0f, 
		m_RDest.z - m_posR.z);

	//�����_�̊���
	m_posR += Diff * CAMERA_R_INERTIA;

	//���_
	VDiff = D3DXVECTOR3(m_VDest.x - m_posV.x, 
		0.0f,
		m_VDest.z - m_posV.z);

	//���_�̊���
	m_posV += VDiff * CAMERA_V_INERTIA;
}

//=======================================
// �^�C�g���p�J����
//=======================================
void CCamera::Title()
{
	m_rot.y += 0.005f;

	//3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}

	//-3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}

	// ����
	m_fDistance = TITLE_DISTANCE;

	// ���_
	m_posV.x = m_posR.x + sinf(m_rot.y) * m_fDistance;
	m_posV.z = m_posR.z + cosf(m_rot.y) * m_fDistance;
}

//=======================================
// ���U���g�p�J����
//=======================================
void CCamera::Result()
{
	// ����
	m_fDistance = RESULT_DISTANCE;

	// ���_
	m_posV.x = m_posR.x + sinf(m_rot.y) * m_fDistance;
	m_posV.z = m_posR.z + cosf(m_rot.y) * m_fDistance;
}

//=======================================
// ���Z��Ƃ̔���
//=======================================
void CCamera::CollisionArena()
{
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &m_posV);

	if (USEFUL::CollisionCircle(m_posV, Constance::ARENA_SIZE))
	{// ���Z��ɓ���������
		m_posV.x = vec.x * Constance::ARENA_SIZE;
		m_posV.z = vec.z * Constance::ARENA_SIZE;
	}
}
