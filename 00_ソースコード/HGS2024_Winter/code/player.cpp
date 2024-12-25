//========================================
//
// プレイヤー[player.cpp]
// Author：森川駿弥
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
// 定数定義
//========================================
namespace
{
	const int LIFE = 10;			// 体力
	const int MOVE_INTERVAL = 10;	// 移動のインターバル
	const int MAX_POS = 3;			// 移動のインターバル

	const float NOCKBACK = 50.0f;	// ノックバック値
	const float SPEED = 4.0f;		// 速度
	const float INERTIA = 0.3f;		// 慣性
	const float RADIUS = 50.0f;		// 半径
	const float FIELD_LIMIT = 4000.0f;	// フィールドの大きさ
	const float MARKERPOS = 200.0f;		// ロックオンマーカーの位置
	const float GAUGE_WIDTH = 50.0f;	// ゲージの幅
	const float GAUGE_HEIGHT = 50.0f;	// ゲージの高さ
	const float COOLTIME = 2.0f;		// 攻撃のクールタイム
	const float SHADOW_SIZE = 50.0f;

	const D3DXVECTOR3 INITIAL_POS = { 0.0f, 0.0f, 500.0f };	// プレイヤー初期位置
	const D3DXVECTOR3 INITIAL_ROT = { 0.0f, 0.0f, 0.0f };	// プレイヤー初期向き	
	const D3DXVECTOR3 GAUGE_POS = { 50.0f, 600.0f, 0.0f };	// ゲージの位置

	const D3DXVECTOR3 PLAYER_POS[MAX_POS] =
	{ 
		{ -200.0f, 0.0f, 400.0f },
		{ 0.0f, 0.0f, 400.0f },
		{ 200.0f, 0.0f, 400.0f },
	};// プレイヤーの目標位置
}

//========================================
// 静的メンバ変数
//========================================
CPlayer* CPlayer::m_pPlayer = nullptr;

//========================================
//コンストラクタ
//========================================
CPlayer::CPlayer(int nPriority) : CCharacter(nPriority),
m_apNumModel	(0),			// モデルの総数
m_nOldMotion	(0),			// 前回のモーション
m_eState		(STATE_NONE),	// 状態
m_fDeltaTime	(0.0f),			// デルタタイム
m_nMoveCounter		(0),
m_pEffect		(nullptr),		// エフェクトのポインタ
m_pGauge		(nullptr),		// ゲージのポインタ
m_pMarker		(nullptr)		// ロックオンマーカー表示
{//値をクリア
	memset(&m_apModel[0], 0, sizeof(m_apModel));	//モデル情報
}

//========================================
//デストラクタ
//========================================
CPlayer::~CPlayer()
{
}

//========================================
//プレイヤーの生成
//========================================
CPlayer *CPlayer::Create(std::string pfile)
{
	if (m_pPlayer == nullptr)
	{
		//プレイヤー生成
		m_pPlayer = new CPlayer;

		//初期化
		m_pPlayer->Init(pfile);
	}

	//ポインタを返す
	return m_pPlayer;
}

//========================================
// 初期化
//========================================
HRESULT CPlayer::Init(std::string pfile)
{
	D3DXVECTOR3 pos = GetPos();

	//テクスチャのポインタ
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// キャラの初期化
	CCharacter::Init(pfile);

	// プレイヤー状態の初期化
	m_eState = STATE_NORMAL;

	// 位置設定
	SetPos(INITIAL_POS);

	// 向き設定
	SetRot(INITIAL_ROT);

	return S_OK;
}

//========================================
//終了
//========================================
void CPlayer::Uninit(void)
{
	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// サウンド停止
	pSound->Stop();

	if (m_pGauge != nullptr)
	{// ゲージが使用されていた場合
		m_pGauge->Uninit();
		m_pGauge = nullptr;
	}

	// 終了
	CCharacter::Uninit();
	m_pPlayer = nullptr;
}

//========================================
//更新
//========================================
void CPlayer::Update(void)
{
	// キーボードの情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// コントローラーの情報取得	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//テクスチャの情報取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// サウンド情報取得
	CSound* pSound = CManager::GetInstance()->GetSound();

	// 敵の情報取得
	CEnemy* pEnemy = CEnemy::GetInstance();

	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	// 移動量取得
	D3DXVECTOR3 move = GetMove();

	// 向き取得
	D3DXVECTOR3 rot = GetRot();

	// プレイヤー行動
	Act(SPEED);

#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_F3))
	{// 体力減算
		Hit(LIFE);
	}
#endif

	if (pInputKeyboard->GetTrigger(DIK_R) ||
		pInputPad->GetTrigger(CInputPad::BUTTON_PUSHING_R, 0))
	{

	}

	// デバッグ表示の情報取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDebugProc();

	// デバッグ表示
	pDebugProc->Print("\nプレイヤーの位置：%f、%f、%f\n", pos.x, pos.y, pos.z);
	pDebugProc->Print("プレイヤーの移動量：%f、%f、%f\n", move.x, move.y, move.z);
	pDebugProc->Print("プレイヤーの向き：%f、%f、%f\n", rot.x, rot.y, rot.z);
	pDebugProc->Print("プレイヤーの状態：%d\n", m_eState);
	pDebugProc->Print("時間：%f\n", m_fDeltaTime);
}

//========================================
//描画
//========================================
void CPlayer::Draw(void)
{
	// 描画
	CCharacter::Draw();
}

//========================================
// 行動
//========================================
void CPlayer::Act(float fSpeed)
{
	// キーボードの情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// コントローラーの情報取得	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	//CCamera型のポインタ
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	// カメラの向き取得
	D3DXVECTOR3 Camrot = pCamera->GetRot();

	// 目的の向き
	D3DXVECTOR3 DiffRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	// 移動量取得
	D3DXVECTOR3 move = GetMove();

	// 向き取得
	D3DXVECTOR3 rot = GetRot();

	// 目的の向き取得
	D3DXVECTOR3 RotDest = GetRotDest();

	if (pInputKeyboard->GetPress(DIK_A) == true
		|| pInputPad->GetPress(CInputPad::BUTTON_LEFT, 0) == true
		|| pInputPad->GetLStickXPress(CInputPad::BUTTON_L_STICK, 0) < 0)
	{//Aが押された

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
	{//Dが押された

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

	{//位置を更新
		pos = PLAYER_POS[m_nPosCounter % MAX_POS];

		//移動量を更新(減衰させる)
		move.x += (0.0f - move.x) * INERTIA;
		move.z += (0.0f - move.z) * INERTIA;
	}

	//目的の向き
	DiffRot.y = RotDest.y - rot.y;

	// 向きの正規化
	USEFUL::NormalizeRotAngle(DiffRot.y);

	//Diffに補正係数をかける
	rot.y += DiffRot.y * 0.1f;

	// 角度の正規化
	USEFUL::NormalizeRotAngle(rot.y);

	// 位置設定
	SetPos(pos);

	// 移動量設定
	SetMove(move);

	// 向き設定
	SetRot(rot);

	// 目的の向き設定
	SetRotDest(RotDest);

	// モーション
	Motion();

	// フィールドとの判定
	CollisionField();
}

//========================================
// プレゼント処理
//========================================
void CPlayer::Present()
{
	// キーボードの情報取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// コントローラーの情報取得	
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_K) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) < 0)
	{//Aが押された
		
	}
	else if (pInputKeyboard->GetTrigger(DIK_L) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_B, 0) < 0)
	{//Dが押された

	}
	else if (pInputKeyboard->GetTrigger(DIK_J) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_X, 0) < 0)
	{//Dが押された

	}
	else if (pInputKeyboard->GetTrigger(DIK_I) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_Y, 0) < 0)
	{//Dが押された

	}
}

//========================================
// モーション管理
//========================================
void CPlayer::Motion()
{
	// モーション情報取得
	CMotion* pMotion = GetMotion();
	if (pMotion == nullptr)
	{
		return;
	}

	if (true)
	{// 歩きモーション
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_WALK);
	}
	else
	{// 待機モーション
		pMotion->Set(CMotion::PLAYER_MOTIONTYPE_NEUTRAL);
	}

	if (pMotion != nullptr)
	{// モーション更新
		pMotion->Update();
	}
}

//========================================
// ヒット処理
//========================================
void CPlayer::Hit(int nLife)
{
	// 位置取得
	D3DXVECTOR3 pos = GetPos();

	// パーティクル生成
	Myparticle::Create(Myparticle::TYPE_DEATH, pos);
}

//========================================
// フィールド外に行かないよう
//========================================
void CPlayer::CollisionField()
{
	// 位置・移動量取得
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

	// 位置・移動量設定
	SetPos(posPlayer);
	SetMove(movePlayer);
}

//========================================
// 闘技場との判定
//========================================
void CPlayer::CollisionArena()
{
	// プレイヤー位置・ベクトル
	D3DXVECTOR3 posPlayer = GetPos();
	D3DXVECTOR3 vec;
	D3DXVec3Normalize(&vec, &posPlayer);

	if (USEFUL::CollisionCircle(posPlayer, Constance::ARENA_SIZE))
	{// 闘技場に当たったら
		posPlayer = vec * Constance::ARENA_SIZE;
	}

	// 位置設定
	SetPos(posPlayer);
}

//========================================
// 敵の方に向く
//========================================
void CPlayer::DestRot()
{
	// カメラの情報取得
	CCamera* pCampera = CManager::GetInstance()->GetCamera();

	// 敵の情報取得
	CEnemy* pEnemy = CEnemy::GetInstance();

	// プレイヤー・敵の位置
	D3DXVECTOR3 posPlayer = GetPos();
	D3DXVECTOR3 posEnemy = pEnemy->GetPos();

	// プレイヤーとの角度
	float RotDest = atan2f(posPlayer.x - posEnemy.x, posPlayer.z - posEnemy.z);
}
