#pragma once
#include "defines.h"
class SoundManager
{
public:
	SoundManager();
	~SoundManager();


#pragma region Variable
private:
	FMOD_SYSTEM *	g_System;		// FMOD system ���� ����
	FMOD_CHANNEL *	ch[32];			// ä��(���ÿ� ����� ���� ���� ��ŭ �迭 ũ�� ����)
	FMOD_SOUND *	SoundFile[50];	// ���� ���� ������(����� ���� ������ŭ �迭 ũ�� ����)
	FMOD_BOOL		IsPause = false;
public:
#pragma endregion

#pragma region Method
private:
public:
	void Init();
	void Update();
	void Loading();
	void Play(int _SoundFile_Num, int _chNum);
	void Stop(int _chNum);
	void SetVol(int _chNum, float _vol);
	void Pause(int _chNum);
#pragma endregion
};