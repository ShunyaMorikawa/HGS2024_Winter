//=======================================
//
// �֗��֐��A�֗��萔[useful.h]
// Author:�X��x��
//
//=======================================

#ifndef _USEFUL_H_     //���̃}�N����`����`����Ă��Ȃ�������
#define _USEFUL_H_     //2�A�C���N���[�h�h�~�̃}�N�����`����


//=======================================
// �֐���`
//=======================================
namespace USEFUL
{// �֗��֐�

	// �����Ɗp�x�̐��K��
	void NormalizeRotAngle(float& fRotAngle);

	// �~�̔���
	inline bool CollisionCircle(D3DXVECTOR3 pos, float fSize)
	{
		D3DXVECTOR3 vec;
		D3DXVec3Normalize(&vec, &pos);

		//�Ίp���̒���(���A�c)
		float fLength = sqrtf(pos.x * pos.x + pos.z * pos.z);

		if (fLength >= fSize)
		{// �T�C�Y��������
			return true;
		}

		return false;
	}
}

//=======================================
// �萔��`
//=======================================
namespace Constance
{// �֗��萔
	const float ARENA_SIZE = 2250.0f;	// ���Z��̃T�C�Y
	const float WALL_POS = 4000.0f;		// ��
	const float WALL_POS_Y = 2000.0f;	// ��

	const std::string PLAYER_TXT = "data//FILE//player.txt";	// �v���C���[���p�X
	const std::string ENEMY_TXT = "data//FILE//enemy.txt";		// �G�l�~�[���p�X
	const std::string TUTORIAL_ENEMY_TXT = "data//FILE//tutorialenemy.txt";		// �G�l�~�[���p�X

	const std::string OTAKU_TXT[3] =
	{
		"data//FILE//motion_otaku00.txt",
		"data//FILE//motion_otaku01.txt",
		"data//FILE//motion_otaku02.txt",
	};
}

#endif
