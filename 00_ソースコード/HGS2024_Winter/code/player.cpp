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
	const int NORMAL_ATTACK = 1;	// �ʏ�U���̃_���[�W
	const int MEDIUM_ATTACK = 2;	// ���U���̃_���[�W
	const int STRONG_ATTACK = 3;	// ���U���̃_���[�W

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
m_nLife			(0),			// �̗�
m_nOldMotion	(0),			// �O��̃��[�V����
m_WalkCounter	(0),			// ���s���G�t�F�N�g�o���p�̃J�E���^�[
m_eState		(STATE_NONE),	// ���
m_fRadius		(0.0f),			// ���a
m_fCoolDown		(0.0f),			// �N�[���_�E���^�C�}�[
m_fDeltaTime	(0.0f),			// �f���^�^�C��
m_bJump			(false),		// �W�����v�t���O
m_bMove			(false),		// �ړ�
m_bWait			(false),		// �ҋ@
m_bMowingdown	(false),		// �U��
m_bCutdown		(false),		// �؂艺��
m_bStrongAttack	(false),		// ���U��
m_IsLock		(false),		// ���b�N�I��
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

	// ���s���̃J�E���^�[
	m_WalkCounter = 0;

	// �̗�
	m_nLife = LIFE;

	// ���a
	m_fRadius = RADIUS;

	// �Q�[�W����
	m_pGauge = CGauge::Create(m_nLife);

	// �ʒu�ݒ�
	m_pGauge->SetPos(GAUGE_POS);

	// �T�C�Y�ݒ�
	m_pGauge->SetSize(GAUGE_WIDTH, GAUGE_HEIGHT);

	// �N�[���_�E���^�C�}�[
	m_fCoolDown = 0.0f;

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

	// �Q�[�W�ɑ̗͐ݒ�
	m_pGauge->SetLife(m_nLife);

	if (m_nLife <= 0)
	{
		// ����
		CObject2D* pObje2D = CObject2D::Create();

		// �ʒu�ݒ�
		pObje2D->SetPos(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		// �T�C�Y�ݒ�
		pObje2D->SetSize(SCREEN_WIDTH, 200.0f);

		// �s�k�e�N�X�`��
		pObje2D->BindTexture(pTexture->Regist("data\\texture\\lose.png"));

		// �T�E���h�Đ�
		pSound->PlaySoundA(CSound::SOUND_LABEL_BGM_LOSE);

		// �I��
		Uninit();
	}

	if (pInputKeyboard->GetTrigger(DIK_R) ||
		pInputPad->GetTrigger(CInputPad::BUTTON_PUSHING_R, 0))
	{
		m_IsLock = m_IsLock ? false : true;

		if (m_IsLock)
		{// ���b�N�I��
			if (m_pMarker == nullptr)
			{// �}�[�J�[����
				m_pMarker = CLockonMarker::Create(true);
			}
		}
		else
		{
			if (m_pMarker != nullptr)
			{// �}�[�J�[�폜
				m_pMarker->Uninit();
				m_pMarker = nullptr;
			}
		}
	}

	// �G�Ƃ̔���
	CollisionEnemy(pos);

	// ���b�N�I��
	LockOn();

	// �f�o�b�O�\���̏��擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// �f�o�b�O�\��
	pDebugProc->Print("\n�v���C���[�̈ʒu�F%f�A%f�A%f\n", pos.x, pos.y, pos.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f�A%f�A%f\n", move.x, move.y, move.z);
	pDebugProc->Print("�v���C���[�̌����F%f�A%f�A%f\n", rot.x, rot.y, rot.z);
	pDebugProc->Print("�v���C���[�̗̑́F%d\n", m_nLife);
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
	// ���[�V��������
	m_bMove = false;

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
		|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) < 0)
	{//A�������ꂽ
		if (pInputKeyboard->GetPress(DIK_W) == true
			|| pInputPad->GetLStickYPress(CInputPad::BUTTON_L_STICK, 0) > 0)
		{//����
			m_bMove = true;

			move.x += sinf(Camrot.y + D3DX_PI * 0.75f) * fSpeed;
			move.z += cosf(Camrot.y + D3DX_PI * 0.75f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y - D3DX_PI * 0.25f;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true
			|| pInputPad->GetLStickYPress(CInputPad::BUTTON_L_STICK, 0) < 0)
		{//����
			m_bMove = true;

			move.x += sinf(Camrot.y + D3DX_PI * 0.25f) * fSpeed;
			move.z += cosf(Camrot.y + D3DX_PI * 0.25f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y - D3DX_PI * 0.75f;
		}
		else
		{//��
			m_bMove = true;

			move.x += sinf(Camrot.y + D3DX_PI * 0.5f) * fSpeed;
			move.z += cosf(Camrot.y + D3DX_PI * 0.5f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y - D3DX_PI * 0.5f;
		}
	}
	else if (pInputKeyboard->GetPress(DIK_D) == true
		|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) > 0)
	{//D�������ꂽ
		if (pInputKeyboard->GetPress(DIK_W) == true
			|| pInputPad->GetLStickYPress(CInputPad::BUTTON_L_STICK, 0) > 0)
		{//�E��
			m_bMove = true;

			move.x += sinf(Camrot.y + -D3DX_PI * 0.75f) * fSpeed;
			move.z += cosf(Camrot.y + -D3DX_PI * 0.75f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y + D3DX_PI * 0.25f;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true
			|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) > 0)
		{//�E��
			m_bMove = true;

			move.x += sinf(Camrot.y + -D3DX_PI * 0.25f) * fSpeed;
			move.z += cosf(Camrot.y + -D3DX_PI * 0.25f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y + D3DX_PI * 0.75f;
		}
		else
		{//�E
			m_bMove = true;

			move.x += sinf(Camrot.y + -D3DX_PI * 0.5f) * fSpeed;
			move.z += cosf(Camrot.y + -D3DX_PI * 0.5f) * fSpeed;

			//�ړ������Ƀ��f����������
			RotDest.y = Camrot.y + D3DX_PI * 0.5f;
		}
	}
	else if (pInputKeyboard->GetPress(DIK_W) == true
		|| pInputPad->GetLStickYPress(CInputPad::BUTTON_L_STICK, 0) > 0)
	{//W�������ꂽ
		m_bMove = true;

		move.x += sinf(Camrot.y + D3DX_PI) * fSpeed;
		move.z += cosf(Camrot.y + D3DX_PI) * fSpeed;

		//�ړ������Ƀ��f����������
		RotDest.y = Camrot.y;
	}
	else if (pInputKeyboard->GetPress(DIK_S) == true
		|| pInputPad->GetLStickYPress(CInputPad::BUTTON_L_STICK, 0) < 0)
	{//S�������ꂽ
		m_bMove = true;

		move.x += sinf(Camrot.y + D3DX_PI * 0.0f) * fSpeed;
		move.z += cosf(Camrot.y + D3DX_PI * 0.0f) * fSpeed;

		//�ړ������Ƀ��f����������
		RotDest.y = Camrot.y + D3DX_PI;
	}

	if (m_bMove)
	{//�ʒu���X�V
		pos += move;

		//�ړ��ʂ��X�V(����������)
		move.x += (0.0f - move.x) * INERTIA;
		move.z += (0.0f - move.z) * INERTIA;

		m_WalkCounter = (m_WalkCounter + 1) % 20;

		if (m_WalkCounter == 0)
		{
			// �p�[�e�B�N������
			Myparticle::Create(Myparticle::TYPE_WALK, pos);

			// �T�E���h�Đ�
			CSound* pSound = CManager::GetInstance()->GetSound();
			pSound->PlaySoundA(CSound::SOUND_LABEL_SE_WALK);
		}
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

	// �U��
	Attack();

	// ���[�V����
	Motion();

	// �t�B�[���h�Ƃ̔���
	CollisionField();

	// ���Z��Ƃ̓����蔻��
	CollisionArena();
}

//========================================
// �U��
//========================================
void CPlayer::Attack()
{
	// ����܂ł̎���
	DWORD previous = timeGetTime();

	// ���ݎ��Ԏ擾
	DWORD Time = timeGetTime();

	// �b���v�Z
	//m_fDeltaTime = Time - previous;
	//previous = Time;

	if (m_fCoolDown > 0.0f)
	{// �N�[���^�C�������炷
		m_fCoolDown;

		if (m_fCoolDown < 0.0f)
		{// �^�C�}�[���Z�b�g
			m_fCoolDown = 0.0f;
		}
	}

	// �L�[�{�[�h�̏��擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_SPACE) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_X, 0) == true)
	{// �؂肨�낵
		m_bCutdown = true;

		m_bMove = false;

		// �G�Ƃ̓����蔻��
		CollisionEnemy(NORMAL_ATTACK);
	}

	if (pInputKeyboard->GetTrigger(DIK_E) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_Y, 0) == true)
	{// ���ガ
		m_bMowingdown = true;

		m_bMove = false;

		// �G�Ƃ̓����蔻��
		CollisionEnemy(MEDIUM_ATTACK);
	}

	if (pInputKeyboard->GetTrigger(DIK_Q) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_RB, 0) == true)
	{// ���U��
		m_bStrongAttack = true;

		m_bMove = false;

		// �G�Ƃ̓����蔻��
		CollisionEnemy(STRONG_ATTACK);
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

	if (m_bMove)
	{// �������[�V����
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_WALK);
	}

	else if (m_bCutdown)
	{// �؂艺�낵���[�V����
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_CUTDOWN);

		m_bCutdown = false;
	}
	else if (m_bMowingdown)
	{// �ガ����
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_MOWINGDOWN);

		m_bMowingdown = false;
	}
	else if (m_bStrongAttack)
	{// ���U��
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_STRONGATTACK);

		m_bStrongAttack = false;
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
// �G�ƃv���C���[�̓����蔻��
//========================================
void CPlayer::CollisionEnemy(int nDamage)
{
	// �v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxTrans;

	// ����̈ʒu
	D3DXMATRIX posWeapon;

	// ���[�V�������擾
	CMotion* pMotion = GetMotion();

	// ���f���̃I�t�Z�b�g�擾
	CModel* pModelOffset = pMotion->GetModel(13);

	// ���f���̃}�g���b�N�X�擾
	D3DXMATRIX MtxModel = pModelOffset->GetMtxWorld();

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, 0.0f, 150.0f, 0.0f);
	D3DXMatrixMultiply(&posWeapon, &mtxTrans, &MtxModel);

	// �}�g���b�N�X�̈ʒu
	D3DXVECTOR3 pos = D3DXVECTOR3(posWeapon._41, posWeapon._42, posWeapon._43);

#ifdef _DEBUG
	// �G�t�F�N�g����
	CEffect::Create(pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), 100.0f, 1, true, CEffect::TYPE::TYPE_NORMAL);
#endif

	// �v���C���[�̔��a
	float fRadius = RADIUS;

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	if (pEnemy != nullptr)
	{
		// �ʒu�擾
		D3DXVECTOR3 posEnemy = pEnemy->GetPos();

		// �ړ��ʎ擾
		D3DXVECTOR3 moveEnemy = pEnemy->GetMove();

		// ���a
		float radiusEnemy = pEnemy->GetRadius();

#ifdef _DEBUG
	CEffect::Create(posEnemy, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), radiusEnemy, 1, true, CEffect::TYPE::TYPE_NORMAL);
#endif
		// �x�N�g�������߂�
		D3DXVECTOR3 vec = posEnemy - pos;

		// �x�N�g�����
		float fLength = D3DXVec3Length(&vec);

		// ���G����
		int Invincible = 0;

		if (fLength <= radiusEnemy + fRadius)
		{// �q�b�g
			pEnemy->Hit(nDamage);

			// �m�b�N�o�b�N
			NockBack();

			// �T�E���h���擾
			CSound* pSound = CManager::GetInstance()->GetSound();

			// �T�E���h�Đ�
			pSound->PlaySoundA(CSound::SOUND_LABEL_SE_ENEMYHIT);
		}
	}
}

//========================================
// �m�b�N�o�b�N
//========================================
void CPlayer::NockBack()
{
	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	// �ʒu�擾
	D3DXVECTOR3 posPlayer = GetPos();

	if (pEnemy != nullptr)
	{
		// �G�̈ʒu�ƈړ���
		D3DXVECTOR3 posEnemy = pEnemy->GetPos();
		D3DXVECTOR3 moveEnemy = pEnemy->GetMove();

		// ��΂�������
		float angle = atan2f(posPlayer.x - posEnemy.x, posPlayer.z - posEnemy.z);

		// �ʒu�X�V
		moveEnemy.x = sinf(angle) * -NOCKBACK;
		moveEnemy.z = cosf(angle) * -NOCKBACK;
		moveEnemy.y = NOCKBACK * 0.5f;

		// �ړ��ʐݒ�
		pEnemy->SetMove(moveEnemy);
	}
}

//========================================
// �q�b�g����
//========================================
void CPlayer::Hit(int nLife)
{
	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �̗͌��炷
	m_nLife -= nLife;

	// �Q�[�W�ɑ̗͐ݒ�
	m_pGauge->SetLife(m_nLife);

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
// �G�Ƃ̔���
//========================================
void CPlayer::CollisionEnemy(const D3DXVECTOR3& pos)
{
	// ����
	float fLength;

	// �v���C���[�̔��a�擾
	float fRadius = GetRadius();

	// �v���C���[�ʒu
	D3DXVECTOR3 posPlayer = GetPos();

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	if (pEnemy == nullptr)
	{
		return;
	}

	// �G�̈ʒu
	D3DXVECTOR3 posEnemy = pEnemy->GetPos();

	// �G�̔��a
	float radiusEnemy = pEnemy->GetRadius();

	// �x�N�g�������߂�
	D3DXVECTOR3 vec = posEnemy - pos;

	//�x�N�g�����
	fLength = D3DXVec3Length(&vec);

	if (fLength <= radiusEnemy + fRadius)
	{// �G�ɓ�������
		// �ʒu�ݒ�
		SetPos(posEnemy);

		SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		// �f�o�b�O�\��
		CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();
		pDebugProc->Print("\n�v���C���[�Ɠ���������");
	}
}

//========================================
// ���b�N�I��
//========================================
void CPlayer::LockOn()
{
	// �J�����̏��擾
	CCamera* pCampera = CManager::GetInstance()->GetCamera();

	// �G�̏��擾
	CEnemy* pEnemy = CEnemy::GetInstance();

	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pCampera == nullptr)
	{
		return;
	}

	if (pEnemy == nullptr)
	{
		// �v���C���[�ɃJ������Ǐ]������
		D3DXVECTOR3 rot = pCampera->GetRot();
		pCampera->following(GetPos(), D3DXVECTOR3(0.0f, rot.y, 0.0f));

		if (m_pMarker != nullptr)
		{// �}�[�J�[�폜
			m_pMarker->Uninit();
			m_pMarker = nullptr;
		}

		return;
	}

	// �G�̕�������
	DestRot();
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

	if (m_IsLock)
	{// �G�̕����Ɍ���
		pCampera->following(posPlayer, D3DXVECTOR3(0.0f, RotDest, 0.0f));

		// �}�[�J�[�̈ʒu�ݒ�
		D3DXVECTOR3 setpos = posEnemy;
		setpos.y += MARKERPOS;
		m_pMarker->SetPos(setpos);
	}
	else
	{// �Ǐ]
		D3DXVECTOR3 rot = pCampera->GetRot();
		pCampera->following(posPlayer, D3DXVECTOR3(0.0f, rot.y, 0.0f));
	}
}
