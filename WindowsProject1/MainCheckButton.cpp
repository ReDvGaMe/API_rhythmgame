#include "MainCheckButton.h"



MainCheckButton::MainCheckButton() {
	Init();
}


MainCheckButton::~MainCheckButton() {
}

void MainCheckButton::Init() {

	// 이미지를 불러옵니다.
	LoadPNGImg(L"Resource\\Button\\Btncheck.png");

	// 오브젝트 크기를 설정합니다.
	SetObjectWH(96 * 3, 47 * 3);

	// 이미지에서 잘라올 크기를 설정합니다.
	SetCropSize(96, 47);

	// Hover 모드를 사용합니다.
	m_UseHover = true;

	m_PosX = 880;
	m_PosY = 400;
	UpdateRect();
}

void MainCheckButton::Update() {
	BaseUpdate();
}

void MainCheckButton::Render(HDC hdc) {
	BaseRender(hdc);
}
