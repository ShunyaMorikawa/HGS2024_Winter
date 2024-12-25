//=====================================
//
// number�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "main.h"
#include "object2D.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

// �O���錾----------------------------
class CTexture;

//�N���X��`---------------------------
class CNumber : public CObject2D
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CNumber(int nPriority);				//�f�t�H���g
	~CNumber();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetNumber(void) { return m_nNumber; }
	void SetNumber(int nNumber) { m_nNumber = nNumber; }

	//�ÓI�����o�֐�
	static CNumber* Create(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�

	//�ÓI�����o�ϐ�
	int m_nNumber;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_NUMBER_H_