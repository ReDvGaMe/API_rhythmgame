#include "Marker_X.h"



Marker_X::Marker_X() {
	Init();
}


Marker_X::~Marker_X() {
}

void Marker_X::Init() {
	// 이미지 불러오기
	LoadBMPImg(L"Resource\\NoteImage\\marker_x.bmp", 0, 0);

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// 오브젝트 크기 설정
	SetObjectWH(180, 180);
	SetCropSize(100, 100);				// 이미지에서 잘라올 크기 설정

	m_UseSprite = true;		// 스프라이트 이미지 사용
	SetSpriteIndex(0, 4);	// 스프라이트 시작, 끝 인덱스 설정
	SetSpriteIndex(1);		// 스프라이트를 그리기 시작하는 Y인덱스를 설정
	SetSpriteDelay(100);	// 스프라이트 딜레이 설정

	// 초기 좌표 설정
	m_PosX = 400;
	m_PosY = 380;
	UpdateRect();
}

void Marker_X::Update() {
	BaseUpdate();
}

void Marker_X::Render(HDC hdc) {
	BaseRender(hdc);
}
