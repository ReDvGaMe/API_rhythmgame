#pragma once
#include "defines.h"
class MusicInfo {
public:
	MusicInfo();
	virtual ~MusicInfo();


#pragma region Variable
private:
	int _MusicIndex;
	string _MusicTitle;
	LPCWSTR _AlbumImagePath;
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

