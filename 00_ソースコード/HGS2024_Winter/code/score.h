//========================================
//
//�V���[�e�B���O�A�N�V����[score.h]
//Author�F�X��x��
//
//========================================
#ifndef _SCORE_H_
#define _SCORE_H_
#include "main.h"
#include "number.h"

//========================================
//�}�N����`
//========================================
#define MAX_SCORE	(8)		//�X�R�A�̌���

//========================================
//�X�R�A�N���X
//========================================
class CScore : public CObject
{
public:
	CScore();	//�R���X�g���N�^
	~CScore();	//�f�X�g���N�^

	//�����o�֐�
	static CScore* Create();	//�G����

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetScore(int nScore);
	void AddScore(int nScore) { SetScore(m_Score + nScore); }
	int GetScore(void) { return m_Score; }

private:
	//�����o�ϐ�
	static CNumber* m_apNumber[MAX_SCORE];		//CNumber�̔z��
	int m_Score;		//�X�R�A�̒l
	int m_nIdxTexture;		//�e�N�X�`���̔ԍ�
	int m_nPatternAnim;		//�X�R�A�p�^�[��No,
};

#endif