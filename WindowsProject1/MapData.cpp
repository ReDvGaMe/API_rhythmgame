#include "MapData.h"
#include <fstream>



MapData::MapData() {
}


MapData::~MapData() {
	if (m_TileMap == NULL)	return;

	// ������ �迭 �޸� ����
	for (int i = 0; i < m_MapHeight; i++) {
		if (m_TileMap[i] != NULL) {
			delete[] m_TileMap[i];
			delete[] m_CollMap[i];
			m_TileMap[i] = NULL;
			m_CollMap[i] = NULL;
		}
	}

	// ������ �迭 �޸� ����
	delete[] m_TileMap;
	delete[] m_CollMap;
	m_TileMap = NULL;
	m_CollMap = NULL;
}

MapData * MapData::GetMapData() {
	static MapData _MapData;
	return &_MapData;
}

void MapData::InitArray() {
	// �� ���� ������ŭ �������迭�� �����Ҵ�
	m_TileMap = new int*[m_MapHeight];
	m_CollMap = new int*[m_MapHeight];

	// �� ���� ������ŭ ������ �迭�� �����Ҵ�
	for (int i = 0; i < m_MapHeight; i++) {
		m_TileMap[i] = new int[m_MapWidth];
		m_CollMap[i] = new int[m_MapWidth];

		for (int j = 0; j < m_MapWidth; j++) {
			m_TileMap[i][j] = -1;
			m_CollMap[i][j] = 0;
		}
	}
}

void MapData::SaveMap() {
	// �� ���� �ؽ�Ʈ ���Ͽ� �Է��� ���ڿ�
	string saveData = "";

	// �� ũ�⸦ ���ڿ��� ��ȯ�Ͽ� ������ ����
	string mapWHSize = "";

	// �� �迭 �ε����� ���ڿ��� ��ȯ�Ͽ� ������ ����
	string mapData = "";

	// �浹 Ÿ�� �� �迭 �ε����� ���ڿ��� ��ȯ�Ͽ� ������ ����
	string collData = "";

	// �� �迭 ũ�⸦ ����
	mapWHSize.append(to_string(m_MapWidth));
	mapWHSize.append(" ");
	mapWHSize.append(to_string(m_MapHeight));
	mapWHSize.append("\n");

	// ���ڿ��� �� �ε����� ����
	for (int i = 0; i < m_MapHeight; i++) {
		for (int j = 0; j < m_MapWidth; j++) {
			// Ÿ�� ���� ����
			mapData.append(to_string(m_TileMap[i][j]));
			mapData.append(" ");

			// �浹 �� ����
			collData.append(to_string(m_CollMap[i][j]));
			collData.append(" ");
		}

		// ����
		mapData.append("\n");
		collData.append("\n");
	}

	// �ؽ�Ʈ ���ڿ��� �Է��� ������ ����
	saveData.append(mapWHSize);
	saveData.append(mapData);
	saveData.append(collData);

	// ���� ����
	// ���� ������ ��� �����ϰ� ���ų� ����
	ofstream ofs("mapData.txt", ofstream::trunc);

	// ���Ͽ� �Է�
	ofs << saveData;

	Log("MapSave", "�� Ÿ�� ����Ϸ�!");

	// ������ ������ ����
	ofs.close();
}