//========================================
//
//シューティングアクション[score.h]
//Author：森川駿弥
//
//========================================
#ifndef _SCORE_H_
#define _SCORE_H_
#include "main.h"
#include "number.h"

//========================================
//マクロ定義
//========================================
#define MAX_SCORE	(8)		//スコアの桁数

//========================================
//スコアクラス
//========================================
class CScore : public CObject
{
public:
	CScore();	//コンストラクタ
	~CScore();	//デストラクタ

	//メンバ関数
	static CScore* Create();	//敵生成

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetScore(int nScore);
	void AddScore(int nScore) { SetScore(m_Score + nScore); }
	int GetScore(void) { return m_Score; }

private:
	//メンバ変数
	static CNumber* m_apNumber[MAX_SCORE];		//CNumberの配列
	int m_Score;		//スコアの値
	int m_nIdxTexture;		//テクスチャの番号
	int m_nPatternAnim;		//スコアパターンNo,
};

#endif