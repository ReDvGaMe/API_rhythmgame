#include "MarkerManager.h"



MarkerManager::MarkerManager() {
	Init();
}


MarkerManager::~MarkerManager() {
	// 마커 매니저 소멸 시 남아있는 마커의 메모리를 해제
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
	// 가장 먼저 생성 된 마커의 스프라이트가 종료되었으면 메모리를 해제
	_MarkerIter = _Marker.begin();

	// 마커가 생성 되었을 경우만 실행
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
	// 마커가 생성 되었을 경우 마커를 렌더
	if (_IsActiveMarker) {
		for (_MarkerIter = _Marker.begin(); _MarkerIter != _Marker.end(); _MarkerIter++)
			(*_MarkerIter)->Render(hdc);
	}
}

void MarkerManager::MakeMarker(string MarkerType, int PosX, int PosY) {
	// 리스트 뒤에 마커를 동적으로 생성
	_Marker.push_back(new Marker(MarkerType, PosX, PosY));
}
