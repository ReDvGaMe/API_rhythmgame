#pragma once
#include "Marker.h"
class MarkerManager :
	public Marker {
public:
	MarkerManager();
	virtual ~MarkerManager();


#pragma region Variable
private:
	bool _IsActiveMarker = false;
	
public:
	// 마커 리스트 추가
	list<Marker*> _Marker;
	list<Marker*>::iterator _MarkerIter;

	// 마커를 출력할 좌표
	const int MarkerPosXArr[4] = { 100, 300, 500, 700 };
	const int MarkerPosYArr[4] = { 300, 500, 700, 900 };
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;

	// 마커를 추가하는 메소드
	void MakeMarker(string MarkerType, int PosX, int PosY);
#pragma endregion
};

