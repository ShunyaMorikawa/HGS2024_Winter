//========================================
//
// �v���C���[[player.cpp]
// Author�F�X��x��
//
//========================================

#include "player.h"
#include "input.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "camera.h"
#include "debugproc.h"
#include "game.h"
#include "particle.h"
#include "enemy.h"
#include "useful.h"
#include "gauge.h"
#include "main.h"
#include "model.h"
#include "motion.h"
#include "effect.h"
#include "object2D.h"
#include "object3D.h"
#include "sound.h"
#include "fade.h"
#include "texture.h"
#include "lockonMarker.h"
#include "resultplayer.h"
#include "result.h"

//========================================
// �萔��`
//========================================
namespace
{
	const int LIFE = 10;			// �̗�
	const int MOVE_INTERVAL = 10;	// �ړ��̃C���^�[�o��
	const int MAX_POS = 3;			// �ړ��̃C���^�[�o��

	const float NOCKBACK = 50.0f;	// �m�b�N�o�b�N�l
	const float SPEED = 4.0f;		// ���x
	const float INERTIA = 0.3f;		// ����
	const float RADIUS = 50.0f;		// ���a
	const float FIELD_LIMIT = 4000.0f;	// �t�B�[���h�̑傫��
	const float MARKERPOS = 200.0f;		// ���b�N�I���}�[�J�[�̈ʒu
	const float GAUGE_WIDTH = 50.0f;	// �Q�[�W�̕�
	const float GAUGE_HEIGHT = 50.0f;	// �Q�[�W�̍���
	const float COOLTIME = 2.0f;		// �U���̃N�[���^�C��
	const float SHADOW_SIZE = 50.0f;

	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, 500.0f };	// �v���C���[�����ʒu
	const D3DXVECTOR3 INITIAL_ROT = { 0.0f, 0.0f, 0.0f };	// �v���C���[��������	
	const D3DXVECTOR3 GAUGE_POS = { 50.0f, 600.0f, 0.0f };	// �Q�[�W�̈ʒu

	const D3DXVECTOR3 PLAYER_POS[MAX_POS] =
	{ 
		{ -200.0f, 0.0f, 400.0f },
		{ 0.0f, 0.0f, 400.0f },
		{ 200.0f, 0.0f, 400.0f },
	};// �v���C���[�̖ڕW�ʒu
}

//========================================
// �ÓI�����o�ϐ�
//========================================
CPlayer* CPlayer::m_pPlayer = nullptr;

//========================================
//�R���X�g���N�^
//========================================
CPlayer::CPlayer(int nPriority) : CCharacter(nPriority),
m_apNumModel	(0),			// ���f���̑���
m_nOldMotion	(0),			// �O��̃��[�V����
m_eState		(STATE_NONE),	// ���
m_fDeltaTime	(0.0f),			// �f���^�^�C��
m_nMoveCounter		(0),
m_pEffect		(nullptr),		// �G�t�F�N�g�̃|�C���^
m_pGauge		(nullptr),		// �Q�[�W�̃|�C���^
m_pMarker		(nullptr)		// ���b�N�I���}�[�J�[�\��
{//�l���N���A
	memset(&m_apModel[0], 0, sizeof(m_apModel));	//���f�����
}

//========================================
//�f�X�g���N�^
//========================================
CPlayer::~CPlayer()
{
}

//========================================
//�v���C���[�̐���
//========================================
CPlayer *CPlayer::Create(std::string pfile)
{
	if (m_pPlayer == nullptr)
	{
		//�v���C���[����
		m_pPlayer = new CPlayer;

		//������
		m_pPlayer->Init(pfile);
	}

	//�|�C���^��Ԃ�
	return m_pPlayer;
}

//========================================
// ������
//========================================
HRESULT CPlayer::Init(std::string pfile)
{
	D3DXVECTOR3 pos = GetPos();

	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �L�����̏�����
	CCharacter::Init(pfile);

	// �v���C���[��Ԃ̏�����
	m_eState = STATE_NORMAL;

	// �ʒu�ݒ�
	SetPos(INITIAL_POS);

	// �����ݒ�
	SetRot(INITIAL_ROT);

	return S_OK;
}

//========================================
//�I��
//========================================
void CPlayer::Uninit(void)
{
	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �T�E���h��~
	pSound->Stop();

	if (m_pGauge != nullptr)
	{// �Q�[�W���g�p����Ă����ꍇ
		m_pGauge->Uninit();
		m_pGauge = nullptr;
	}

	// �I��
	CCharacter::Uninit();
	m_pPlayer = nullptr;
}

//========================================
//�X�V
//========================================
void CPlayer::Update(void)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//�e�N�X�`���̏��擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �T�E���h���擾
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �ړ��ʎ擾
	D3DXVECTOR3 move = GetMove();

	// �����擾
	D3DXVECTOR3 rot = GetRot();

	// �v���C���[�s��
	Act(SPEED);

#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_F3))
	{// �̗͌��Z
		Hit(LIFE);
	}
#endif

	if (pInputKeyboard->GetTrigger(DIK_R) ||
		pInputPad->GetTrigger(CInputPad::BUTTON_PUSHING_R, 0))
	{

	}

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n�v���C���[�̈ʒu�F%f�A%f�A%f\n", pos.x, pos.y, pos.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f�A%f�A%f\n", move.x, move.y, move.z);
	pDebugProc->Print("�v���C���[�̌����F%f�A%f�A%f\n", rot.x, rot.y, rot.z);
	pDebugProc->Print("�v���C���[�̏�ԁF%d\n", m_eState);
	pDebugProc->Print("���ԁF%f\n", m_fDeltaTime);
}

//========================================
//�`��
//========================================
void CPlayer::Draw(void)
{
	// �`��
	CCharacter::Draw();
}

//========================================
// �s��
//========================================
void CPlayer::Act(float fSpeed)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//CCamera�^�̃|�C���^
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// �J�����̌����擾
	D3DXVECTOR3 Camrot = pCamera->GetRot();

	// �ړI�̌���
	D3DXVECTOR3 DiffRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �ړ��ʎ擾
	D3DXVECTOR3 move = GetMove();

	// �����擾
	D3DXVECTOR3 rot = GetRot();

	// �ړI�̌����擾
	D3DXVECTOR3 RotDest = GetRotDest();

	if (pInputKeyboard->GetPress(DIK_A) == true
		|| pInputPad->GetPress(CInputPad::BUTTON_LEFT, 0) == true
		|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) < 0)
	{//A�������ꂽ

		m_nMoveCounter++;

		if (m_nMoveCounter > MOVE_INTERVAL)
		{
			m_nMoveCounter = 0;

			m_nPosCounter++;
		}
	}
	else if (pInputKeyboard->GetPress(DIK_D) == true
		|| pInputPad->GetPress(CInputPad::BUTTON_RIGHT, 0) == true
		|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) > 0)
	{//D�������ꂽ

		m_nMoveCounter++;

		if (m_nMoveCounter > MOVE_INTERVAL)
		{
			m_nMoveCounter = 0;

			m_nPosCounter += 2;
		}
	}
	else
	{
		m_nMoveCounter = 9;
	}

	{//�ʒu���X�V
		pos = PLAYER_POS[m_nPosCounter % MAX_POS];

		//�ړ��ʂ��X�V(����������)
		move.x += (0.0f - move.x) * INERTIA;
		move.z += (0.0f - move.z) * INERTIA;
	}

	//�ړI�̌���
	DiffRot.y = RotDest.y - rot.y;

	// �����̐��K��
	USEFUL::NormalizeRotAngle(DiffRot.y);

	//Diff�ɕ␳�W����������
	rot.y += DiffRot.y * 0.1f;

	// �p�x�̐��K��
	USEFUL::NormalizeRotAngle(rot.y);

	// �ʒu�ݒ�
	SetPos(pos);

	// �ړ��ʐݒ�
	SetMove(move);

	// �����ݒ�
	SetRot(rot);

	// �ړI�̌����ݒ�
	SetRotDest(RotDest);

	// ���[�V����
	Motion();

	// �t�B�[���h�Ƃ̔���
	CollisionField();
}

//========================================
// �v���[���g����
//========================================
void CPlayer::Present()
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_K) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) < 0)
	{//A�������ꂽ
		
	}
	else if (pInputKeyboard->GetTrigger(DIK_L) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_B, 0) < 0)
	{//D�������ꂽ

	}
	else if (pInputKeyboard->GetTrigger(DIK_J) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_X, 0) < 0)
	{//D�������ꂽ

	}
	else if (pInputKeyboard->GetTrigger(DIK_I) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_Y, 0) < 0)
	{//D�������ꂽ

	}
}

//========================================
// ���[�V�����Ǘ�
//========================================
void CPlayer::Motion()
{
	// ���[�V�������擾
	CMotion* pMotion = GetMotion();
	if (pMotion == nullptr)
	{
		return;
	}

	if (true)
	{// �������[�V����
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_WALK);
	}
	else
	{// �ҋ@���[�V����
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_NEUTRAL);
	}

	if (pMotion != nullptr)
	{// ���[�V�����X�V
		pMotion->Update();
	}
}

//========================================
// �q�b�g����
//========================================
void CPlayer::Hit(int nLife)
{
	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �p�[�e�B�N������
	Myparticle::Create(Myparticle::TYPE_DEATH, pos);
}

//========================================
// �t�B�[���h�O�ɍs���Ȃ��悤
//========================================
void CPlayer::CollisionField()
{
	// �ʒu�E�ړ��ʎ擾
	D3DXVECTOR3 posPlayer = GetPos();
	D3DXVECTOR3 movePlayer = GetMove();

	if (posPlayer.x > FIELD_LIMIT)
	{
		posPlayer.x = FIELD_LIMIT;
		movePlayer.x = 0.0f;
	}
	else if (posPlayer.x < -FIELD_LIMIT)
	{
		posPlayer.x = -FIELD_LIMIT;
		movePlayer.x = 0.0f;

	}
	if (posPlayer.z > FIELD_LIMIT)
	{
		posPlayer.z = FIELD_LIMIT;
		movePlayer.z = 0.0f;
	}
	else if (posPlayer.z < -FIELD_LIMIT)
	{
		posPlayer.z = -FIELD_LIMIT;
		movePlayer.z = 0.0f;
	}

	// �ʒu�E�ړ��ʐݒ�
	SetPos(posPlayer);
	SetMove(movePlayer);
}

//========================================
// ���Z��Ƃ̔���
//========================================
void CPlayer::CollisionArena()
{
	// �v���C���[�ʒu�E�x�N�g��
	D3DXVECTOR3 posPlayer = GetPos();
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &posPlayer);

	if (USEFUL::CollisionCircle(posPlayer, Constance::ARENA_SIZE))
	{// ���Z��ɓ���������
		posPlayer = vec * Constance::ARENA_SIZE;
	}

	// �ʒu�ݒ�
	SetPos(posPlayer);
}

//========================================
// �G�̕��Ɍ���
//========================================
void CPlayer::DestRot()
{
	// �J�����̏��擾
	CCamera* pCampera = CManager::GetInstance()->GetCamera();

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	// �v���C���[�E�G�̈ʒu
	D3DXVECTOR3 posPlayer = GetPos();
	D3DXVECTOR3 posEnemy = pEnemy->GetPos();

	// �v���C���[�Ƃ̊p�x
	float RotDest = atan2f(posPlayer.x - posEnemy.x, posPlayer.z - posEnemy.z);
}
