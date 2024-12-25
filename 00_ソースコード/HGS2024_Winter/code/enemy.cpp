//========================================
//
// �G�̏���[enemy.cpp]
// Author�F�X��x��
//
//========================================

#include "enemy.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "debugproc.h"
#include "motion.h"
#include "model.h"
#include "particle.h"
#include "player.h"
#include "game.h"
#include "useful.h"
#include "effect.h"
#include "bullet.h"
#include "useful.h"
#include "sound.h"
#include "fade.h"
#include "gauge.h"
#include "result.h"

//========================================
//���O���
//========================================
namespace
{
	const int LIFE = 20;				// �̗�
	const int ATTACKCOUNTER = 180;		// �U������܂ł̎���
	const int MAXDIRECTION = 8;			// �e���΂��ő����
	const int BULLETLIFE = 120;			// �e�̎���
	
	const float BULLETMOVE = 10.0f;		// �e�̈ړ���
	const float SPEED = 0.3f;			// ���x
	const float GRAVITY = 2.0f;			// �d��
	const float INERTIA = 0.1f;			// ����
	const float RADIUS = 200.0f;		// ���a
	const float NOCKBACK = 50.0f;		// �m�b�N�o�b�N�l
	const float GAUGE_SIZE = 50.0f;		// �Q�[�W�T�C�Y
	const float RESULT_HEIGHT = 200.0f;		// ���U���g�̍���

	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, -500.0f };	// �G�̏����ʒu
	const D3DXVECTOR3 GAUGE_POS = { 600.0f, 25.0f, 0.0f };	// �G�Q�[�W�̏����ʒu
}

//========================================
//�R���X�g���N�^
//========================================
CEnemy::CEnemy(int nPriority) : CCharacter(nPriority),
m_nLife		(0),			// �̗�
m_nCnt		(0),			// �J�E���g
m_fRadius	(0.0f),			// ���a
m_bWalk		(false),		// ����
m_bAttack	(false),		// �U��
m_eState	(STATE_NONE),	// ���
m_pGauge	(nullptr)		// �Q�[�W
{//�l���N���A
}

//========================================
//�f�X�g���N�^
//========================================
CEnemy::~CEnemy()
{
}

//========================================
// ����
//========================================
CEnemy* CEnemy::Create(std::string pfile)
{
	CEnemy* pEnemy = new CEnemy;

	pEnemy->Init(pfile);

	return pEnemy;
}

//========================================
// ������
//========================================
HRESULT CEnemy::Init(std::string pfile)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �L�����̏�����
	CCharacter::Init(pfile);

	// �ʒu�ݒ�
	SetPos(INITIAL_POS);

	// �����ݒ�
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �̗�
	m_nLife = LIFE;

	// ���a
	m_fRadius = RADIUS;

	return S_OK;
}

//========================================
// �I��
//========================================
void CEnemy::Uninit(void)
{
	// �I��
	CCharacter::Uninit();
}

//========================================
// �X�V
//========================================
void CEnemy::Update(void)
{
	// �ړI�̌���
	D3DXVECTOR3 DiffRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �X�V
	CCharacter::Update();

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �ړ��ʎ擾
	D3DXVECTOR3 move = GetMove();

	// �����擾
	D3DXVECTOR3 rot = GetRot();

	// �ړI�̌����擾
	D3DXVECTOR3 RotDest = GetRotDest();

	// �v���C���[���̎擾
	CPlayer* pPlayer = CPlayer::GetInstance();

	// �L�[�{�[�h�̏��擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	if (pPlayer != nullptr)
	{
		// �ʒu�擾
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();

		// �v���C���[�Ƃ̊p�x
		RotDest.y = atan2f(pos.x - posPlayer.x, pos.z - posPlayer.z);
	}

	// �v���C���[�����Ɉړ�
	move.x += sinf(rot.y + D3DX_PI) * SPEED;
	move.z += cosf(rot.y + D3DX_PI) * SPEED;

	// �ʒu���X�V
	pos += move;

	// �ړ��ʂ��X�V(����������)
	move.x += (0.0f - move.x) * INERTIA;
	move.z += (0.0f - move.z) * INERTIA;

	//�ړI�̌���
	DiffRot.y = RotDest.y - rot.y;

	// �����̐��K��
	USEFUL::NormalizeRotAngle(DiffRot.y);

	//Diff�ɕ␳�W����������
	rot.y += DiffRot.y * 0.1f;

	// �p�x�̐��K��
	USEFUL::NormalizeRotAngle(rot.y);

	// �d��
	move.y -= GRAVITY;

	if (pos.y <= 0.0f)
	{// �ʒu�ƈړ��ʂ̍X�V��~
		pos.y = 0.0f;
		move.y = 0.0f;
	}
	
	// �����ݒ�
	SetRot(rot);

	// �ړI�̌����ݒ�
	SetRotDest(RotDest);

	// ���[�V�����Ǘ�
	Motion();

	// ���Z��Ƃ̓����蔻��
	CollisionCircle();

#ifdef _DEBUG
	if (pInputKeyboard->GetPress(DIK_F4))
	{// �̗͌��Z
		Hit(LIFE);
	}
#endif

	// �f�o�b�O�\��
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();
	pDebugProc->Print("\n�G�̈ʒu�F%f�A%f�A%f\n", pos.x, pos.y, pos.z);
	pDebugProc->Print("�G�̌����F%f�A%f�A%f\n", rot.x, rot.y, rot.z);
	pDebugProc->Print("�G�̈ړ��ʁF%f�A%f�A%f\n", move.x, move.y, move.z);
	pDebugProc->Print("�G�̗̑́F%d\n", m_nLife);
	pDebugProc->Print("F4�œG�̗̑�0\n");
}

//========================================
// �`��
//========================================
void CEnemy::Draw(void)
{
	// �`��
	CCharacter::Draw();
}

//========================================
// �q�b�g����
//========================================
void CEnemy::Hit(int nLife)
{
	//CInputKeyboard���擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad���擾
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//�e�N�X�`���̏��擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �̗͌��炷
	m_nLife -= nLife;

	if (m_pGauge != nullptr)
	{
		// �Q�[�W�ɑ̗͐ݒ�
		m_pGauge->SetLife(m_nLife);
	}

	if (m_nLife <= 0)
	{
		// �p�[�e�B�N������
		Myparticle::Create(Myparticle::TYPE_DEATH, pos);

		// ����
		CObject2D* pObje2D = CObject2D::Create();

		// �ʒu�ݒ�
		pObje2D->SetPos(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 00.0f));

		// �T�C�Y�ݒ�
		pObje2D->SetSize(1280.0f, 200.0f);

		// �����e�N�X�`��
		pObje2D->BindTexture(pTexture->Regist("data\\texture\\win.png"));

		// �I��
		Uninit();
	}
}

//========================================
// �m�b�N�o�b�N
//========================================
void CEnemy::NockBack()
{
	// �G�̏��擾
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer != nullptr)
	{
		// �ʒu�擾
		D3DXVECTOR3 posEnemy = GetPos();

		// �v���C���[�̈ʒu�ƈړ���
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();
		D3DXVECTOR3 movePlayer = pPlayer->GetMove();

		// ��΂����p�x
		float angle = atan2f(posEnemy.x - posEnemy.x, posPlayer.z - posEnemy.z);

		// �ʒu�X�V
		movePlayer.x = sinf(angle) * -NOCKBACK;
		movePlayer.z = cosf(angle) * -NOCKBACK;
		movePlayer.y = NOCKBACK * 0.5f;

		// �ړ��ʐݒ�
		pPlayer->SetMove(movePlayer);
	}
}

//========================================
// ���[�V�����Ǘ�
//========================================
void CEnemy::Motion()
{
	// ���[�V�������擾
	CMotion* pMotion = GetMotion();
	if (pMotion == nullptr)
	{
		return;
	}

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	// �ړ��ʎ擾
	D3DXVECTOR3 move = GetMove();

	if (m_bWalk)
	{// �������[�V����
		pMotion->Set(CMotion::ENEMY_MOTIONTYPE_WALK);
	}
	else if (m_bAttack)
	{// �؂艺�낵���[�V����
		pMotion->Set(CMotion::ENEMY_MOTIONTYPE_ATTACK);

		m_bWalk = false;

		move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		if (pMotion->IsFinish() && m_bAttack == true)
		{// ���[�V�����I��
			m_bAttack = false;
		}
	}
	else
	{
		pMotion->Set(CMotion::ENEMY_MOTIONTYPE_WALK);
	}

	if (pMotion != nullptr)
	{// ���[�V�����X�V
		pMotion->Update();
	}

	// �ړ��ʐݒ�
	SetMove(move);
}

//========================================
// �v���C���[�Ƃ̓����蔻��
//========================================
void CEnemy::CollisionPlayer(int nDamage)
{
	// �v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxTrans;

	// ����̈ʒu
	D3DXMATRIX posWeapon;

	// ���[�V�������擾
	CMotion* pMotion = GetMotion();

	// ���f���̃I�t�Z�b�g�擾
	CModel* pModelOffset = pMotion->GetModel(13);

	// ���f���̃}�g���b�N�X
	D3DXMATRIX MtxModel = pModelOffset->GetMtxWorld();

	// �ʒu�擾
	D3DXVECTOR3 posEnemy = GetPos();

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, 0.0f, 150.0f, 0.0f);
	D3DXMatrixMultiply(&posWeapon, &mtxTrans, &MtxModel);

	// �}�g���b�N�X�̈ʒu
	D3DXVECTOR3 pos = D3DXVECTOR3(posWeapon._41, posWeapon._42, posWeapon._43);

#ifdef _DEBUG
	// �G�t�F�N�g����
	CEffect::Create(pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), 100.0f, 10, true, CEffect::TYPE::TYPE_NORMAL);
	CEffect::Create(posEnemy, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), 25.0f, 10, true, CEffect::TYPE::TYPE_NORMAL);
#endif

	// �v���C���[�̔��a
	float fRadius = RADIUS;

	// �G�̏��擾
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer != nullptr)
	{
		// �v���C���[�̈ʒu�E�ړ��ʁE���a�E��Ԏ擾
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();
		D3DXVECTOR3 movePlayer = pPlayer->GetMove();
		int statePlayer = pPlayer->GetState();

		// �x�N�g�������߂�
		D3DXVECTOR3 vec = posEnemy - pos;

		// �x�N�g�����
		float fLength = D3DXVec3Length(&vec);

		if (statePlayer == CPlayer::STATE_DAMAGE)
		{// �_���[�W��Ԃ̎�
			int nCnt = 0;
		}
	}
}

//========================================
// ���Z��Ƃ̓����蔻��
//========================================
void CEnemy::CollisionCircle()
{
	// �v���C���[�ʒu
	D3DXVECTOR3 posEnemy = GetPos();
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &posEnemy);

	if (USEFUL::CollisionCircle(posEnemy, Constance::ARENA_SIZE))
	{// ���Z��ɓ���������
		posEnemy = vec * Constance::ARENA_SIZE;
	}

	// �ʒu�ݒ�
	SetPos(posEnemy);
}
