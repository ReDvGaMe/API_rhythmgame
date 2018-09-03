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

