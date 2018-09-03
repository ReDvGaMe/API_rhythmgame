#include "MusicInfo.h"



MusicInfo::MusicInfo() {
}


MusicInfo::~MusicInfo() {
}

int MusicInfo::GetMusicIndex() {
	return _MusicIndex;
}

int MusicInfo::GetMusicLevel() {
	return _MusicLevel;
}

LPCWSTR MusicInfo::GetAlbumImagePath() {
	return _AlbumImagePath;
}
