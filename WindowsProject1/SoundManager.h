#pragma once
#include "defines.h"
class SoundManager
{
public:
	SoundManager();
	~SoundManager();


#pragma region Variable
private:
	FMOD_SYSTEM *	g_System;		// FMOD system 변수 선언
	FMOD_CHANNEL *	ch[32];			// 채널(동시에 출력할 사운드 개수 만큼 배열 크기 선언)
	FMOD_SOUND *	SoundFile[50];	// 사운드 음원 포인터(출력할 사운드 개수만큼 배열 크기 선언)
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