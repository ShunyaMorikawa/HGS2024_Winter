//========================================
//
//���f��[model.h]
//Author�F�X��x��
//
//========================================

#ifndef _MODEL_H_
#define _MODEL_H_

#include "main.h"
#include "object.h"

//=======================================
//���f���N���X
//=======================================
class CModel
{
public:
	enum HIERARCHY
	{// �K�w�����Ă邩
		TYPE_HIERARCHY = 0,
		TYPE_NOT_HIERARCHY,
		TYPE_MAX
	};

	CModel();		//�R���X�g���N�^
	~CModel();		//�f�X�g���N�^

	//�����o�֐�
	HRESULT Init(const char *pFilename);		//������
	void Uninit(void);		//�I��
	void Update(void);		//�X�V
	void Draw(void);		//�`��

	static CModel *Create(const char *pFilename);	//�I�u�W�F�N�g����

	// �}�e���A���̎擾
	LPD3DXBUFFER GetBuffMat() { return m_pBuffMat; }

	// �e���f���̐ݒ�
	void SetParent(CModel* pModel) { m_pParent = pModel; }

	// ���[���h�}�g���b�N�X�̎擾
	D3DXMATRIX GetMtxWorld(void) { return m_mtxWorld; }	

	// �ʒu�ݒ�E�擾
	void SetPos(const D3DXVECTOR3& pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	// ����
	void SetRot(const D3DXVECTOR3& rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	// �ʒu
	void SetPosition(const D3DXVECTOR3& pos) { m_setPos = pos; }
	D3DXVECTOR3 GetPosition(void) { return m_setPos; }

	// ���[�V�������̌����̐ݒ�Ǝ擾
	void SetRotate(const D3DXVECTOR3& rot) { m_setRot = rot; }
	D3DXVECTOR3 GetRotate(void) { return m_setRot; }

	// �ԍ��ݒ�
	void SetIndex(CModel* pModel) { m_pParent = pModel; }

	// �K�w�ݒ�
	void SetType(HIERARCHY type) { m_nType = type; }

	void SetVertex(void);
	void SetSize(float fWidht, float fHeight);

private:
	//�����o�ϐ�
	HIERARCHY m_nType;				// �K�w���邩�Ȃ���

	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;	//���L�e�N�X�`��
	D3DXMATRIX m_mtxWorld;			//���[���h�}�g���b�N�X
	LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat;		//�}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;				//�}�e���A���̐�
	D3DXVECTOR3 m_pos;				//�ʒu
	D3DXVECTOR3 m_rot;				//����
	CModel *m_pParent;				//�e���f���ւ̃|�C���^

	D3DXVECTOR3 m_setPos;			// ���[�V�������̃��f���̈ʒu
	D3DXVECTOR3 m_setRot;			// ���[�V�������̃��f���̌���
};

#endif