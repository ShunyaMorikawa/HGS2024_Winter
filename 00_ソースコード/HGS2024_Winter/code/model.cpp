//========================================
//
//�@���f��[model.cpp]
//�@Author�F�X��x��
//
//========================================

#include "model.h"
#include "renderer.h"
#include "manager.h"

//========================================
//�R���X�g���N�^
//========================================
CModel::CModel() : 
m_pMesh		(nullptr),			// ���b�V��(���_���)�ւ̃|�C���^
m_pBuffMat	(nullptr),			// �}�e���A���ւ̃|�C���^
m_dwNumMat	(0),				// �}�e���A���̐�
m_pos		(0.0f, 0.0f, 0.0f),	// �ʒu
m_rot		(0.0f, 0.0f, 0.0f),	// ����
m_pParent	(nullptr)			// �e���f���ւ̃|�C���^
{
	m_pTexture.clear();			//���L�e�N�X�`��
}

//========================================
//�f�X�g���N�^
//========================================
CModel::~CModel()
{

}

//========================================
//���f������
//========================================
CModel *CModel::Create(const char *pFilename)
{
	//CModel�^�̃|�C���^
	CModel *pModel = nullptr;

	if (pModel == nullptr)
	{
		//�v���C���[����
		pModel = new CModel;

		//������
		pModel->Init(pFilename);
	}

	//�|�C���^��Ԃ�
	return pModel;
}

//========================================
//������
//========================================
HRESULT CModel::Init(const char *pFilename)
{
	//���[�J���ϐ��錾
	D3DXMATERIAL *pMat;

	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�ʒu�̐ݒ�
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�����̐ݒ�
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �K�w
	m_nType = CModel::TYPE_HIERARCHY;

	//X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(pFilename,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		nullptr,
		&m_pBuffMat,
		nullptr,
		&m_dwNumMat,
		&m_pMesh);

	//�}�e���A�����ɑ΂���|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntTex = 0; nCntTex < (int)m_dwNumMat; nCntTex++)
	{
		if (pMat[nCntTex].pTextureFilename != nullptr)
		{//�e�N�X�`���t�@�C���������݂���

			LPDIRECT3DTEXTURE9 pTex = nullptr;

			//�e�N�X�`���̓ǂݍ���
			D3DXCreateTextureFromFile(pDevice, pMat[nCntTex].pTextureFilename, &pTex);

			// �Ŋ��ɒǉ�
			m_pTexture.push_back(pTex);
		}
		else
		{// ���݂��Ȃ��Ƃ�
			m_pTexture.push_back(nullptr);
		}
	}

	//������Ԃ�
	return S_OK;
}

//========================================
//�I��
//========================================
void CModel::Uninit(void)
{
	//���b�V���̔j��
	if (m_pMesh != nullptr)
	{
		m_pMesh->Release();
		m_pMesh = nullptr;
	}

	//�}�e���A���̔j��
	if (m_pBuffMat != nullptr)
	{
		m_pBuffMat->Release();
		m_pBuffMat = nullptr;
	}

	for (int i = 0; i < (int)m_pTexture.size(); i++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[i] != nullptr)
		{
			m_pTexture[i]->Release();
			m_pTexture[i] = nullptr;
		}
	}

	// �S�N���A
	m_pTexture.clear();

}

//========================================
//�X�V
//========================================
void CModel::Update(void)
{

}

//========================================
//�`��
//========================================
void CModel::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;
	D3DXMATERIAL *pMat;
	D3DXMATRIX mtxParent;			//�e���f���̃}�g���b�N�X

	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	if (m_pParent != nullptr)
	{//�e�����݂���
		//�e���f���̃}�g���b�N�X���擾����
		mtxParent = m_pParent->GetMtxWorld();
	}
	else
	{//�e�����݂��Ȃ�
		if (m_nType == TYPE_HIERARCHY)
		{// �K�w���f�����K�w����Ȃ���
			//����(�ŐV)�̃}�g���b�N�X���擾����{ = �v���C���[�̃}�g���b�N�X}
			pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
		}
		else
		{
			D3DXMatrixIdentity(&mtxParent);
		}
	}

	//�e�̃}�g���b�N�X�Ɗ|�����킹��
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxParent);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{//�}�e���A���̐�����
		//�}�e���A���ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture[nCntMat]); //�e�N�X�`�����g�p���ĂȂ��Ƃ���nullptr

		//���f��(�p�[�c)�̕`��
		m_pMesh->DrawSubset(nCntMat);
	}

	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//========================================
//���_���
//========================================
void CModel::SetVertex(void)
{

}

//========================================
//�T�C�Y����
//========================================
void CModel::SetSize(float fWidht, float fHeight)
{

}
