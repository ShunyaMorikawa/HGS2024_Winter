//=======================================
//
//�J����[camera.h]
//Author�@:�@MORIKAWA SHUNYA
//
//=======================================

#ifndef _CAMERA_H_     //���̃}�N����`����`����Ă��Ȃ�������
#define _CAMERA_H_     //2�A�C���N���[�h�h�~�̃}�N�����`����

#include "main.h"

//=======================================
//�J�����N���X
//=======================================
class CCamera
{
public:
	CCamera();		//�R���X�g���N�^
	~CCamera();		//�f�X�g���N�^

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void SetCamera(void);
	void CameraMoveV(void);
	float RotNor(float RotN);
	void following(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot);
	void Title();
	void Result();
	void CollisionArena();

	// �����E���_�E�����_�E������x�N�g���̎擾
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	D3DXVECTOR3 GetPosV(void) { return m_posV; }
	D3DXVECTOR3 GetPosR(void) { return m_posR; }
	D3DXVECTOR3 GetVecU() { return m_vecU; }

private:
	//�����o�ϐ�
	D3DXMATRIX m_mtxProjection;		//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX m_mtxView;			//�r���[�}�g���b�N�X

	D3DXVECTOR3 m_posV;		//���_
	D3DXVECTOR3 m_posR;		//�����_
	D3DXVECTOR3 m_vecU;		//������x�N�g��
	D3DXVECTOR3 m_rot;		//����
	D3DXVECTOR3 m_move;		//�ړ���
	D3DXVECTOR3 m_VDest;	//�ړI�̎��_
	D3DXVECTOR3 m_RDest;	//�ړI�̒����_
	float m_fDistance;		//����
};

#endif
