//========================================
//
//�v���R���p�C��[precompile.h]
//Author�F�X��x��
//
//========================================

//========================================
// ���O�C���N���[�h
//========================================

#ifndef PRECOMPILE_H__
#define PRECOMPILE_H__

#include <windows.h>
#define  DIRECTINPUT_VERSION (0x0800)   //�r���h���̌x���Ώ��p�}�N��
#include "d3dx9.h"		//�`�揈���ɕK�v
#include "xaudio2.h"	//�T�E���h�����ɕK�v
#include "dinput.h"		//���͏����ɕK�v
#include "Xinput.h"
#include "time.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <vector>
#include <assert.h>
#include "useful.h"

#ifdef _DEBUG
//#define CHECK_MEM_LEAK
#endif // _DEBUG

//���i�g�p�֎~
#ifdef CHECK_MEM_LEAK
#define new new ( NORMALBLOCK , FILE , __LINE )
#endif // CHECK_MEM_LEAK

#endif // _PRECOMPILE_H_