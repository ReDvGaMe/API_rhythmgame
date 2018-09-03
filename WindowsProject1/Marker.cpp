#include "Marker.h"



Marker::Marker() {
	Init();
}


Marker::~Marker() {
}

Marker::Marker(string MarkerType, int PosX, int PosY) {
	if (!MarkerType.compare("Z"))
		SetImagePath(L"Resource\\NoteImage\\marker_z.bmp");
	else if (!MarkerType.compare("X"))
		SetImagePath(L"Resource\\NoteImage\\marker_x.bmp");
	else
		return;
	
	SetMarkerPos(PosX, PosY);

	Init();
}

void Marker::Init() {
	// 이미지 불러오기
	LoadBMPImg(_ImagePath, 0, 0);

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// 오브젝트 크기 설정
	SetObjectWH(200, 200);
	SetCropSize(_CropSize, _CropSize);	// 이미지에서 잘라올 크기 설정

	m_UseSprite = true;		// 스프라이트 이미지 사용
	SetSpriteIndex(0, 4);	// 스프라이트 시작, 끝 인덱스 설정
	SetSpriteYIndex(0, 4);	// 스프라이트를 그리기 시작하는 Y인덱스를 설정
	SetSpriteDelay(100);	// 스프라이트 딜레이 설정

	UpdateRect();
}

void Marker::Update() {
	BaseUpdate();

	if (m_DrawYIndex == 4 && m_SpriteIndex == 4)
		_EndMarkerSprite = true;
}

void Marker::Render(HDC hdc) {
	BaseRender(hdc);
}

void Marker::SetMarkerPos(int PosX, int PosY) {
	m_PosX = PosX;
	m_PosY = PosY;
}

void Marker::SetImagePath(LPCWSTR imagepath) {
	_ImagePath = imagepath;
}

bool Marker::GetEndMarkerSprite() {
	return _EndMarkerSprite;
}
