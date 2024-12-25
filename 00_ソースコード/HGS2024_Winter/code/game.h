//========================================
//
//ゲーム内処理[game.h]
//Author：森川駿弥
//
//========================================

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "manager.h"

//========================================
//前方宣言
//========================================
class CObjectX;
class CObject2D;
class CObject3D;
class CLight;
class CPlayer;
class CIdxMeshField;
class CField;
class CEnemy;
class CFade;
class CGauge;
class CWall;
class CMapObject;
class CEnemyManager;
class CScore;
class CTimer;

//========================================
// 定数定義
//========================================
namespace
{
	const int ITEM_MAX = 256;	// アイテムの最大数
}

//========================================
//ゲームクラス
//========================================
class CGame : public CScene
{
public:
	// 状態
	enum STATE
	{// プレイヤーの状態
		STATE_WAIT = 0,
		STATE_START,
		STATE_GAME,
		STATE_FINISH,
		STATE_MAX
	};

	CGame();	//コンストラクタ
	~CGame();	//デストラクタ

	//メンバ関数
	static CGame *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void PauseState(bool bPauseState) { m_bPause = bPauseState; }	//ポーズ状態かどうか

	CScore* GetScore() { return m_pScore; }
	STATE GetState() { return m_state; }

	static CGame* GetInstance();		// ゲームマネージャーの情報
	
private:
	static CGame *m_pGame;		// ゲームマネージャーのポインタ

	int m_nTransition;			// カウンター

	bool m_bPause;				// ポーズ状態のON/OFF

	CObjectX *m_pObjectX;		// Xファイルオブジェクトのポインタ
	CIdxMeshField *m_pIdxMesh;	// メッシュフィールドのポインタ
	CFade* m_pFade;				// フェードのポインタ
	CObject2D* m_pObj2D;		// オブジェクト2Dのポインタ
	CEnemyManager* m_pEnemyManager;	// 敵マネージャーのポインタ
	CScore* m_pScore;
	CTimer* m_pTime;
	
	STATE m_state;
};

#endif
