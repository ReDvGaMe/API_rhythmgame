#include "MarkerManager.h"



MarkerManager::MarkerManager() {
	Init();
}


MarkerManager::~MarkerManager() {
	// ��Ŀ �Ŵ��� �Ҹ� �� �����ִ� ��Ŀ�� �޸𸮸� ����
	_MarkerIter = _Marker.begin();
	for (_MarkerIter; _MarkerIter != _Marker.end(); _MarkerIter++) {
		delete *_MarkerIter;
		*_MarkerIter = NULL;
	}
}

void MarkerManager::Init() {
}

void MarkerManager::Update() {
	BaseUpdate();
	// ���� ���� ���� �� ��Ŀ�� ��������Ʈ�� ����Ǿ����� �޸𸮸� ����
	_MarkerIter = _Marker.begin();

	// ��Ŀ�� ���� �Ǿ��� ��츸 ����
	if (_MarkerIter != _Marker.end()) {
		_IsActiveMarker = true;
		if ((*_MarkerIter)->GetEndMarkerSprite()) {
			delete *_MarkerIter;
			*_MarkerIter = NULL;
			_Marker.pop_front();
		}
	}
	else
		_IsActiveMarker = false;

	if (_IsActiveMarker) {
		for (_MarkerIter = _Marker.begin(); _MarkerIter != _Marker.end(); _MarkerIter++)
			(*_MarkerIter)->Update();
	}
}

void MarkerManager::Render(HDC hdc) {
	BaseRender(hdc);
	// ��Ŀ�� ���� �Ǿ��� ��� ��Ŀ�� ����
	if (_IsActiveMarker) {
		for (_MarkerIter = _Marker.begin(); _MarkerIter != _Marker.end(); _MarkerIter++)
			(*_MarkerIter)->Render(hdc);
	}
}

void MarkerManager::MakeMarker(string MarkerType, int PosX, int PosY) {
	// ����Ʈ �ڿ� ��Ŀ�� �������� ����
	_Marker.push_back(new Marker(MarkerType, PosX, PosY));
}
