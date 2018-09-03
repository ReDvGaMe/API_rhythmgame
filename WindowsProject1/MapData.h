#pragma once
#include "defines.h"

class MapData {
public:
	MapData();
	~MapData();

#pragma region Variable
private:

public:
	// 맵 가로 세로 크기
	int m_MapWidth = 0, m_MapHeight = 0;

	// 맵 타일 아이템 배열
	int** m_TileMap;

	// 충돌 타일 배열
	int** m_CollMap;

#pragma endregion


#pragma region Method
private:

public:
	static MapData* GetMapData();

	// 해당 멤버 함수를 호출하여 맵 배열을 동적할당
	void InitArray();

	// 맵을 저장
	void SaveMap();

#pragma endregion
};

