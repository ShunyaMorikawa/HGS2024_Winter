//=====================================
//
// score�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _TIMER_H_
#define _TIMER_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------
#define MAX_PLACE (5)			//���d�X�N���[���p�w�i�̍ő吔

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CNumber;
class CObject;
class CTimer : public CObject
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CTimer(int nPriority);				//�f�t�H���g
	virtual ~CTimer();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	void SetWidth(float fWidth) { m_fWidth = fWidth; }
	float GetWidth(void) { return m_fWidth; }
	void SetHeight(float fHeight) { m_fHeight = fHeight; }
	float GetHeight(void) { return m_fHeight; }

	void AddScore(int nScore) { m_nScore += nScore; }
	void SetScore(int nScore) { m_nScore = nScore; }
	int GetScore(void) { return m_nScore; }

	int GetTimer(void) { return m_nTimer; }

	void SetStart(bool bStart) { m_bStart = bStart; }

	//�ÓI�����o�֐�
	static CTimer* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	static int GetScoreResult(void) { return m_nScoreResult; }
	static void SetScoreResult(int score) { m_nScoreResult = score; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	CNumber* m_apObject2D[MAX_PLACE];
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	float m_fWidth;
	float m_fHeight;
	float m_fHue;
	int m_nScore;

	int m_nTimer;
	int m_nTimeCounter;

	bool m_bStart;

	//�ÓI�����o�ϐ�
	static int m_nScoreResult;
};

#endif // !_SCORE_H_