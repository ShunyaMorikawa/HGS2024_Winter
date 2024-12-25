//===============================================
//
// enter促し(press_enter.cpp)
// Author 髙田 佳依
//
//===============================================
#ifndef _PRESS_ENTER_H_		//このマクロ定義がされてなかったら
#define _PRESS_ENTER_H_		//二重インクルード防止のマクロを定義する

//=========================
// インクルードファイル
//=========================
#include "manager.h"
#include "object2D.h"

//=========================
// マクロ定義
//=========================


//=========================
// 前方宣言
//=========================

//=========================
// オブジェクト2Dクラス
//=========================
class CPress_Enter : public CObject2D
{
public:

	//=========================
	// タイプ列挙型
	//=========================
	enum UPDATE_TYPE
	{
		UPDATE_TYPE_NONE = 0,
		UPDATE_TYPE_ANIM,
		UPDATE_TYPE_MAX
	};

	CPress_Enter(int nPriority = 5);		//コンストラクタ
	~CPress_Enter();		//デストラクタ

	HRESULT Init(void);							//初期化(デフォ)
	HRESULT Init(const D3DXVECTOR3 pos);		//初期化(オバロ)
	void Uninit(void);							//終了
	void Update(void);							//更新
	void Draw(void);							//描画

	static CPress_Enter* Create(void);		//生成
	static CPress_Enter *Create(const D3DXVECTOR3 pos);		//生成

	void SetInterval(int nCtr) { m_nTimeInterval = nCtr; }
	int SetInterval() { return m_nTimeInterval; }

protected:

private:
	int m_nAlphaCnter;						//PRESS ENTERの点滅間隔の判定
	int m_nTimeInterval;					//PRESS ENTERの点滅間隔
	float m_fAlphaColor;					//頂点カラーa
};

#endif