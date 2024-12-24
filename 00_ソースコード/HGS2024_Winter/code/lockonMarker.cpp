//=======================================
//
// ���b�N���}�[�J�[[rockonMarker.cpp]
//Author : MORIKAWA SHUNYA
//
//=======================================

#include "lockonMarker.h"
#include "debugproc.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//===========================================
// �萔��`
//===========================================
namespace
{
	const float MARKER_SIZE = 90.0f;		// �}�[�J�[�̃T�C�Y
	const std::string TEXTURE = "data\\TEXTURE\\rockon_point2.png";	// �}�[�J�[�̃e�N�X�`��
}

//===========================================
//�R���X�g���N�^
//===========================================
CLockonMarker::CLockonMarker(int nPriority) : CBillboard(nPriority),
m_bAlpha	(false)		// ���Z����
{
}

//===========================================
//�f�X�g���N�^
//===========================================
CLockonMarker::~CLockonMarker()
{
}

//===========================================
//����
//===========================================
CLockonMarker* CLockonMarker::Create(bool alpha)
{
	//CLockonMarker�^�̃|�C���^
	CLockonMarker *pRockonMarker = nullptr;

	if (pRockonMarker == nullptr)
	{//nullptr�̎�
		//�C���X�^���X����
		pRockonMarker = new CLockonMarker;

		//������
		pRockonMarker->Init(alpha);
	}

	//�|�C���^��Ԃ�
	return pRockonMarker;
}

//===========================================
//����������
//===========================================
HRESULT CLockonMarker::Init(bool alpha)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	//������
	CBillboard::Init();

	// �T�C�Y�ݒ�
	SetSize(MARKER_SIZE, MARKER_SIZE);

	//�e�N�X�`�����蓖��
	BindTexture(pTexture->Regist(TEXTURE));

	m_bAlpha = alpha;

	//������Ԃ�
	return S_OK;
}

//===========================================
//�I������
//===========================================
void CLockonMarker::Uninit(void)
{
	//�I��
	CBillboard::Uninit();
}

//===========================================
//�X�V����
//===========================================
void CLockonMarker::Update(void)
{
	//�X�V
	CBillboard::Update();
}

//===========================================
//�`�揈��
//===========================================
void CLockonMarker::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	if (m_bAlpha == true)
	{// ���u�����f�B���O�����Z�����ɐݒ�
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}

	//�A���t�@�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//Z�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	//�`��
	CBillboard::Draw();

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�A���t�@�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//z�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}
