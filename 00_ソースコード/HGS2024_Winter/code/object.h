//========================================
//
//�I�u�W�F�N�g�Ǘ�[object.h]
//Author�F�X��x��
//
//========================================

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "main.h"

//========================================
// �萔��`
//========================================
namespace
{
	const int MAX_OBJ = 256;	// �I�u�W�F�N�g�̍ő吔
	const int NUM_PRIORITY = 8;	// �D�揇�ʂ̑���
}

//========================================
//�I�u�W�F�N�g�N���X
//========================================
class CObject
{
public: 
	CObject(int nPriority = 3);				//�R���X�g���N�^
	virtual ~CObject();		//�f�X�g���N�^

	//�������z�֐�
	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	//�����o�֐�
	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);
	static void DeleteAll(void);

	// �ʒu�̐ݒ�Ǝ擾
	void SetPos(const D3DXVECTOR3& pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	// �ړ��ʂ̐ݒ�Ǝ擾
	void SetMove(const D3DXVECTOR3& move) { m_move = move; }
	D3DXVECTOR3 GetMove() { return m_move; }

	// �����̐ݒ�Ǝ擾
	void SetRot(const D3DXVECTOR3& rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	
	void Delete(void);
	void BindTexture(int pTexture);		//�e�N�X�`�����蓖��

	void SetDrawFrag(bool bDraw);		// �`�悷�邩���Ȃ���

	// ���[���h�}�g���b�N�X�̐ݒ�Ǝ擾
	void SetmtxWorld(const D3DXMATRIX& mtxWorld) { m_mtxWorld = mtxWorld; }
	D3DXMATRIX GetmtxWorld() { return m_mtxWorld; }

	// ���b�V���̒��_���Ɛݒ�Ǝ擾
	void SetMesh(const LPD3DXMESH& pMesh) { m_pMesh = pMesh; }
	LPD3DXMESH GetMesh() { return m_pMesh; }

	// �}�e���A���̎擾�Ɛݒ�
	void SetBuffMat(const LPD3DXBUFFER& pBuffMat) { m_pBuffMat = pBuffMat; }
	LPD3DXBUFFER GetBuffMat() { return m_pBuffMat; }

	// �}�e���A���̐ݒ�Ǝ擾
	void SetdwNumMat(DWORD dwNumMat) {m_dwNumMat = dwNumMat;}
	DWORD GetdwNumMat() { return m_dwNumMat; }

protected:
	void Release(void);

private:
	// �����o�ϐ�
	static int m_nNumAll;		// �I�u�W�F�N�g����
	static CObject *m_pTop[NUM_PRIORITY];		//�擪
	static CObject *m_pCurrent[NUM_PRIORITY];	//�Ō��

	int m_nID;				// �������g��ID
	int m_nIdxTexture;		// �e�N�X�`���̔ԍ�
	int m_nPriority;		// �D�揇�ʂ̈ʒu

	bool m_bRelease;		// �I���t���O
	bool m_bDrawFrag;		// �`�悷�邩���Ȃ���

	D3DXMATRIX m_mtxWorld;			//���[���h�}�g���b�N�X
	LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat;		//�}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;				//�}�e���A���̐�

	D3DXVECTOR3 m_vtxMin, m_vtxMax;	//���f���̍ő�A�ŏ��l
	D3DXVECTOR3 m_pos;		// �ʒu
	D3DXVECTOR3 m_rot;		// ����
	D3DXVECTOR3 m_move;		// �ړ���

	CObject *m_pNext;		//��
	CObject *m_pPrev;		//�O��
};

#endif
