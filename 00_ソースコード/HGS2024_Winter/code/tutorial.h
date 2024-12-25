//========================================
//
//チュートリアル[tutorial.h]
//Author：森川駿弥
//
//========================================

#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "main.h"
#include "manager.h"

//========================================
//前方宣言
//========================================
class CObjectX;
class CObject3D;
class CLight;
class CPlayer;
class CIdxMeshField;
class CField;
class CFade;
class CGauge;
class CObject2D;
class CMapObject;

//========================================
//チュートリアルクラス
//========================================
class CTutorial : public CScene
{
public:
	CTutorial();	//コンストラクタ
	~CTutorial();	//デストラクタ

	static CTutorial* GetInstance();

	//メンバ関数
	static CTutorial *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static CTutorial* m_pTutorial;		// チュートリアルのポインタ

	bool m_bEnd;				// チュートリアル終了かどうか

	CObject2D* m_pObj2D;		// オブジェクト2Dのポインタ

	CFade* m_pFade;				// フェードのポインタ
};

#endif
