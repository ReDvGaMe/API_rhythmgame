#pragma once
#include "defines.h"

class MapData {
public:
	MapData();
	~MapData();

#pragma region Variable
private:

public:
	// �� ���� ���� ũ��
	int m_MapWidth = 0, m_MapHeight = 0;

	// �� Ÿ�� ������ �迭
	int** m_TileMap;

	// �浹 Ÿ�� �迭
	int** m_CollMap;

#pragma endregion


#pragma region Method
private:

public:
	static MapData* GetMapData();

	// �ش� ��� �Լ��� ȣ���Ͽ� �� �迭�� �����Ҵ�
	void InitArray();

	// ���� ����
	void SaveMap();

#pragma endregion
};

