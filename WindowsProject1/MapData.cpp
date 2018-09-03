#include "MapData.h"
#include <fstream>



MapData::MapData() {
}


MapData::~MapData() {
	if (m_TileMap == NULL)	return;

	// 이차원 배열 메모리 해제
	for (int i = 0; i < m_MapHeight; i++) {
		if (m_TileMap[i] != NULL) {
			delete[] m_TileMap[i];
			delete[] m_CollMap[i];
			m_TileMap[i] = NULL;
			m_CollMap[i] = NULL;
		}
	}

	// 일차원 배열 메모리 해제
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
	// 맵 세로 개수만큼 일차월배열을 동적할당
	m_TileMap = new int*[m_MapHeight];
	m_CollMap = new int*[m_MapHeight];

	// 맵 가로 개수만큼 이차원 배열을 동적할당
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
	// 맵 저장 텍스트 파일에 입력할 문자열
	string saveData = "";

	// 맵 크기를 문자열로 변환하여 저장할 변수
	string mapWHSize = "";

	// 맵 배열 인덱스를 문자열로 변환하여 저장할 변수
	string mapData = "";

	// 충돌 타일 맵 배열 인덱스를 문자열로 변환하여 저장할 변수
	string collData = "";

	// 맵 배열 크기를 저장
	mapWHSize.append(to_string(m_MapWidth));
	mapWHSize.append(" ");
	mapWHSize.append(to_string(m_MapHeight));
	mapWHSize.append("\n");

	// 문자열에 맵 인덱스를 저장
	for (int i = 0; i < m_MapHeight; i++) {
		for (int j = 0; j < m_MapWidth; j++) {
			// 타일 맵을 저장
			mapData.append(to_string(m_TileMap[i][j]));
			mapData.append(" ");

			// 충돌 맵 저장
			collData.append(to_string(m_CollMap[i][j]));
			collData.append(" ");
		}

		// 개행
		mapData.append("\n");
		collData.append("\n");
	}

	// 텍스트 문자열에 입력할 내용을 저장
	saveData.append(mapWHSize);
	saveData.append(mapData);
	saveData.append(collData);

	// 파일 생성
	// 파일 내용을 모두 삭제하고 열거나 생성
	ofstream ofs("mapData.txt", ofstream::trunc);

	// 파일에 입력
	ofs << saveData;

	Log("MapSave", "맵 타일 저장완료!");

	// 열었던 파일을 닫음
	ofs.close();
}