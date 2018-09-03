#pragma once
#include "defines.h"
class MusicInfo {
public:
	MusicInfo();
	virtual ~MusicInfo();


#pragma region Variable
private:
	// °î ¹øÈ£
	int _MusicIndex;

	// °î Á¦¸ñ
	wstring _MusicTitle;

	// ¾Ù¹ü ÀÚÄÏ °æ·Î
	LPCWSTR _AlbumImagePath;

	// °î ·¹º§
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

