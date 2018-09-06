#include "SoundManager.h"



SoundManager::SoundManager() {
	Init();
}


SoundManager::~SoundManager() {
	for (int i = 0; i < 50; i++) {
		FMOD_Sound_Release(SoundFile[i]);
	}
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void SoundManager::Init() {
	FMOD_System_Create(&g_System);	// g_System 객체 선언
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL); // FMOD system 초기화

	Loading();
	Play(0, 0);
}

void SoundManager::Update() {
	// 사운드는 게임 구조와 같이 계속 갱신을 해주어야함
	// 파일을 일정한 크기 단위로 매번 읽어 출력하는 스트리밍 방식을 사용하기 때문
	FMOD_System_Update(g_System);
}

void SoundManager::Loading() {
	// 사운드 객체는 사운드 파일과 1:1 대응
	FMOD_System_CreateSound(g_System, "./media//wave.mp3", FMOD_DEFAULT, 0, &SoundFile[0]);
	// FMOD_DEFAULT = FMOD_LOOP_OFF | FMOD_2D | FMOD_HARDWARE / 사운드 1번 출력, FMOD_LOOP_NORMAL을 이용하여 반복 출력 가능
}

void SoundManager::Play(int _SoundFile_Num, int _chNum) {
	// 사운드 객체를 통해 읽혀진 사운드는 채널을 통해 출력
	FMOD_System_PlaySound(g_System, SoundFile[_SoundFile_Num], 0, false, &ch[_chNum]);
}

void SoundManager::Stop(int _chNum) {
	// 채널을 통해 출력 중인 사운드를 정지
	FMOD_Channel_Stop(ch[_chNum]);
}

void SoundManager::SetVol(int _chNum, float _vol) {
	// 볼륨 범위 : 0.0f ~ 1.0f
	FMOD_Channel_SetVolume(ch[_chNum], _vol);
}

void SoundManager::Pause(int _chNum) {
	IsPause = !IsPause;
	FMOD_Channel_SetPaused(ch[_chNum], IsPause);
}
