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
	FMOD_System_Create(&g_System);	// g_System ��ü ����
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL); // FMOD system �ʱ�ȭ

	Loading();
	Play(0, 0);
}

void SoundManager::Update() {
	// ����� ���� ������ ���� ��� ������ ���־����
	// ������ ������ ũ�� ������ �Ź� �о� ����ϴ� ��Ʈ���� ����� ����ϱ� ����
	FMOD_System_Update(g_System);
}

void SoundManager::Loading() {
	// ���� ��ü�� ���� ���ϰ� 1:1 ����
	FMOD_System_CreateSound(g_System, "./media//wave.mp3", FMOD_DEFAULT, 0, &SoundFile[0]);
	// FMOD_DEFAULT = FMOD_LOOP_OFF | FMOD_2D | FMOD_HARDWARE / ���� 1�� ���, FMOD_LOOP_NORMAL�� �̿��Ͽ� �ݺ� ��� ����
}

void SoundManager::Play(int _SoundFile_Num, int _chNum) {
	// ���� ��ü�� ���� ������ ����� ä���� ���� ���
	FMOD_System_PlaySound(g_System, SoundFile[_SoundFile_Num], 0, false, &ch[_chNum]);
}

void SoundManager::Stop(int _chNum) {
	// ä���� ���� ��� ���� ���带 ����
	FMOD_Channel_Stop(ch[_chNum]);
}

void SoundManager::SetVol(int _chNum, float _vol) {
	// ���� ���� : 0.0f ~ 1.0f
	FMOD_Channel_SetVolume(ch[_chNum], _vol);
}

void SoundManager::Pause(int _chNum) {
	IsPause = !IsPause;
	FMOD_Channel_SetPaused(ch[_chNum], IsPause);
}
