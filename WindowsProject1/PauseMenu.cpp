#include "PauseMenu.h"



PauseMenu::PauseMenu() {
	Init();
}


PauseMenu::~PauseMenu() {
}

void PauseMenu::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\PauseMenu.png");

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// 초기 좌표 설정
	m_PosX = WND_WIDTH / 2;
	m_PosY = WND_HEIGHT / 2;
	UpdateRect();
}

void PauseMenu::Update() {
	BaseUpdate();
}

void PauseMenu::Render(HDC hdc) {
	BaseRender(hdc);
}
