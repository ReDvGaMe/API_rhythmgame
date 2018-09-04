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
	// ��Ŀ ����Ʈ �߰�
	list<Marker*> _Marker;
	list<Marker*>::iterator _MarkerIter;

	// ��Ŀ�� ����� ��ǥ
	const int MarkerPosXArr[4] = { 100, 300, 500, 700 };
	const int MarkerPosYArr[4] = { 300, 500, 700, 900 };
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;

	// ��Ŀ�� �߰��ϴ� �޼ҵ�
	void MakeMarker(string MarkerType, int PosX, int PosY);
#pragma endregion
};

