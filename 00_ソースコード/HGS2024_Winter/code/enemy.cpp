//========================================
//
// 敵の処理[enemy.cpp]
// Author：森川駿弥
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
#include "enemy_manager.h"

//========================================
//名前空間
//========================================
namespace
{
	const int LIFE = 20;				// 体力
	const int ATTACKCOUNTER = 180;		// 攻撃するまでの時間
	const int MAXDIRECTION = 8;			// 弾を飛ばす最大方向
	const int BULLETLIFE = 120;			// 弾の寿命
	
	const float BULLETMOVE = 10.0f;		// 弾の移動量
	const float SPEED = 0.3f;			// 速度
	const float GRAVITY = 2.0f;			// 重力
	const float INERTIA = 0.1f;			// 慣性
	const float RADIUS = 200.0f;		// 半径
	const float NOCKBACK = 50.0f;		// ノックバック値
	const float GAUGE_SIZE = 50.0f;		// ゲージサイズ
	const float RESULT_HEIGHT = 200.0f;		// リザルトの高さ

	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, -500.0f };	// 敵の初期位置
	const D3DXVECTOR3 GAUGE_POS = { 600.0f, 25.0f, 0.0f };	// 敵ゲージの初期位置
	const D3DXVECTOR3 GET_POS = { -1000.0f, 0.0f, 300.0f };	// プレゼント受け取った後の位置
	const D3DXVECTOR3 LANE_OFFSET = { 0.0f, 0.0f, -300.0f };	// プレゼント受け取った後の位置

	const D3DXVECTOR3 LANE_POS[3] =
	{
		{ -200.0f, 0.0f, 200.0f },
		{ 0.0f, 0.0f, 200.0f },
		{ 200.0f, 0.0f, 200.0f },
	};// プレイヤーの目標位置
}

//========================================
//コンストラクタ
//========================================
CEnemy::CEnemy(int nPriority) : CCharacter(nPriority),
m_nNumPresent(0),			// カウント
m_nNumLane(0),			// カウント
m_nCntWait(0),
m_eState	(STATE_NONE)	// 状態
{//値をクリア
	m_pParent = nullptr;
	m_pChild = nullptr;
}

//========================================
//デストラクタ
//========================================
CEnemy::~CEnemy()
{
}

//========================================
// 生成
//========================================
CEnemy* CEnemy::Create(std::string pfile)
{
	CEnemy* pEnemy = new CEnemy;

	pEnemy->Init(pfile);

	return pEnemy;
}

//========================================
// 初期化
//========================================
HRESULT CEnemy::Init(std::string pfile)
{
	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// キャラの初期化
	CCharacter::Init(pfile);

	// 位置設定
	SetPos(INITIAL_POS);

	// 向き設定
	SetRot(D3DXVECTOR3(0.0f, 3.14f, 0.0f));

	m_nNumPresent = rand() % 3;

	return S_OK;
}

//========================================
// 終了
//========================================
void CEnemy::Uninit(void)
{
	// 終了
	CCharacter::Uninit();
}

//========================================
// 更新
//========================================
void CEnemy::Update(void)
{
	// 目的の向き
	D3DXVECTOR3 DiffRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// 更新
	CCharacter::Update();

	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	// 移動量取得
	D3DXVECTOR3 move = GetMove();

	// 向き取得
	D3DXVECTOR3 rot = GetRot();

	// 目的の向き取得
	D3DXVECTOR3 RotDest = GetRotDest();

	// プレイヤー情報の取得
	CPlayer* pPlayer = CPlayer::GetInstance();

	// キーボードの情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	if (pPlayer != nullptr)
	{
		// 位置取得
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();

		// プレイヤーとの角度
		RotDest.y = atan2f(pos.x - posPlayer.x, pos.z - posPlayer.z);
	}

	// プレイヤー方向に移動
	move.x += sinf(rot.y + D3DX_PI) * SPEED;
	move.z += cosf(rot.y + D3DX_PI) * SPEED;

	// 位置を更新

	if (bGet)
	{
		pos += (GET_POS - pos) * 0.05f;
	}
	else if (m_pParent != nullptr)
	{
		pos += (m_pParent->GetPos() + LANE_OFFSET - pos) * 0.05f;
	}
	else
	{
		pos += (LANE_POS[m_nNumLane] - pos) * 0.05f;
	}

	D3DXVECTOR3 vecLane = LANE_POS[m_nNumLane] - pos;
	if (D3DXVec3Length(&vecLane) < 150.0f) 
	{
		m_nCntWait++;

		if (m_nCntWait > 300)
		{
			Hit(3);
		}
	}

	// 移動量を更新(減衰させる)
	move.x += (0.0f - move.x) * INERTIA;
	move.z += (0.0f - move.z) * INERTIA;

	//目的の向き
	DiffRot.y = RotDest.y - rot.y;

	// 向きの正規化
	USEFUL::NormalizeRotAngle(DiffRot.y);

	//Diffに補正係数をかける
	rot.y += DiffRot.y * 0.1f;

	// 角度の正規化
	USEFUL::NormalizeRotAngle(rot.y);

	// 重力
	move.y -= GRAVITY;

	if (pos.y <= 0.0f)
	{// 位置と移動量の更新停止
		pos.y = 0.0f;
		move.y = 0.0f;
	}

	// 向き設定
	SetPos(pos);
	
	// 向き設定
	SetRot(rot);

	// 目的の向き設定
	SetRotDest(RotDest);

	// モーション管理
	Motion();

	// 闘技場との当たり判定
	CollisionCircle();

#ifdef _DEBUG
	if (pInputKeyboard->GetPress(DIK_F4))
	{// 体力減算
		Hit(LIFE);
	}
#endif

	// デバッグ表示
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();
	pDebugProc->Print("\n敵の位置：%f、%f、%f\n", pos.x, pos.y, pos.z);
	/*pDebugProc->Print("敵の向き：%f、%f、%f\n", rot.x, rot.y, rot.z);
	pDebugProc->Print("敵の移動量：%f、%f、%f\n", move.x, move.y, move.z);
	pDebugProc->Print("F4で敵の体力0\n");*/

	D3DXVECTOR3 vecEnemy = GET_POS - pos;
	if (D3DXVec3Length(&vecEnemy) < 10.0f)
	{
		Uninit();
	}
}

//========================================
// 描画
//========================================
void CEnemy::Draw(void)
{
	// 描画
	CCharacter::Draw();
}

//========================================
// ヒット処理
//========================================
void CEnemy::Hit(int nPresent)
{
	//CInputKeyboard情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad情報取得
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//テクスチャの情報取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	D3DXVECTOR3 vecLane = LANE_POS[m_nNumLane] - pos;
	if (D3DXVec3Length(&vecLane) > 150.0f) { return; }

	bGet = true;

	if (m_nNumPresent == nPresent)
	{
		
	}
	else
	{

	}

	if (m_pChild != nullptr)
	{
		m_pChild->SetParent(nullptr);
	}
	
	CEnemyManager::GetInstance()->GetListEnemy(m_nNumLane)->remove(this);
}

//========================================
// ノックバック
//========================================
void CEnemy::NockBack()
{
	// 敵の情報取得
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer != nullptr)
	{
		// 位置取得
		D3DXVECTOR3 posEnemy = GetPos();

		// プレイヤーの位置と移動量
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();
		D3DXVECTOR3 movePlayer = pPlayer->GetMove();

		// 飛ばされる角度
		float angle = atan2f(posEnemy.x - posEnemy.x, posPlayer.z - posEnemy.z);

		// 位置更新
		movePlayer.x = sinf(angle) * -NOCKBACK;
		movePlayer.z = cosf(angle) * -NOCKBACK;
		movePlayer.y = NOCKBACK * 0.5f;

		// 移動量設定
		pPlayer->SetMove(movePlayer);
	}
}

//========================================
// モーション管理
//========================================
void CEnemy::Motion()
{
	// モーション情報取得
	CMotion* pMotion = GetMotion();
	if (pMotion == nullptr)
	{
		return;
	}

	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	// 移動量取得
	D3DXVECTOR3 move = GetMove();

	if (true)
	{// 歩きモーション
		pMotion->Set(CMotion::ENEMY_MOTIONTYPE_WALK);
	}
	else
	{
		pMotion->Set(CMotion::ENEMY_MOTIONTYPE_WALK);
	}

	if (pMotion != nullptr)
	{// モーション更新
		pMotion->Update();
	}

	// 移動量設定
	SetMove(move);
}

//========================================
// プレイヤーとの当たり判定
//========================================
void CEnemy::CollisionPlayer(int nDamage)
{
	// 計算用マトリックス
	D3DXMATRIX mtxTrans;

	// 武器の位置
	D3DXMATRIX posWeapon;

	// モーション情報取得
	CMotion* pMotion = GetMotion();

	// モデルのオフセット取得
	CModel* pModelOffset = pMotion->GetModel(13);

	// モデルのマトリックス
	D3DXMATRIX MtxModel = pModelOffset->GetMtxWorld();

	// 位置取得
	D3DXVECTOR3 posEnemy = GetPos();

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, 0.0f, 150.0f, 0.0f);
	D3DXMatrixMultiply(&posWeapon, &mtxTrans, &MtxModel);

	// マトリックスの位置
	D3DXVECTOR3 pos = D3DXVECTOR3(posWeapon._41, posWeapon._42, posWeapon._43);

#ifdef _DEBUG
	// エフェクト生成
	CEffect::Create(pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), 100.0f, 10, true, CEffect::TYPE::TYPE_NORMAL);
	CEffect::Create(posEnemy, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), 25.0f, 10, true, CEffect::TYPE::TYPE_NORMAL);
#endif

	// プレイヤーの半径
	float fRadius = RADIUS;

	// 敵の情報取得
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer != nullptr)
	{
		// プレイヤーの位置・移動量・半径・状態取得
		D3DXVECTOR3 posPlayer = pPlayer->GetPos();
		D3DXVECTOR3 movePlayer = pPlayer->GetMove();
		int statePlayer = pPlayer->GetState();

		// ベクトルを求める
		D3DXVECTOR3 vec = posEnemy - pos;

		// ベクトル代入
		float fLength = D3DXVec3Length(&vec);

		if (statePlayer == CPlayer::STATE_DAMAGE)
		{// ダメージ状態の時
			int nCnt = 0;
		}
	}
}

//========================================
// 闘技場との当たり判定
//========================================
void CEnemy::CollisionCircle()
{
	// プレイヤー位置
	D3DXVECTOR3 posEnemy = GetPos();
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &posEnemy);

	if (USEFUL::CollisionCircle(posEnemy, Constance::ARENA_SIZE))
	{// 闘技場に当たったら
		posEnemy = vec * Constance::ARENA_SIZE;
	}

	// 位置設定
	SetPos(posEnemy);
}
