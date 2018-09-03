#pragma once
#include "defines.h"
class MusicInfo {
public:
	MusicInfo();
	virtual ~MusicInfo();


#pragma region Variable
private:
	// �� ��ȣ
	int _MusicIndex;

	// �� ����
	wstring _MusicTitle;

	// �ٹ� ���� ���
	LPCWSTR _AlbumImagePath;

	// �� ����
	int _MusicLevel;
public:
#pragma endregion

#pragma region Method
private:
public:
	int GetMusicIndex();
	int GetMusicLevel(); 
	LPCWSTR GetAlbumImagePath();
#pragma endregion
};

