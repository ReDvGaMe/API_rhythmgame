#include "MainCheckButton.h"



MainCheckButton::MainCheckButton() {
	Init();
}


MainCheckButton::~MainCheckButton() {
}

void MainCheckButton::Init() {

	// �̹����� �ҷ��ɴϴ�.
	LoadPNGImg(L"Resource\\Button\\Btncheck.png");

	// ������Ʈ ũ�⸦ �����մϴ�.
	SetObjectWH(96 * 3, 47 * 3);

	// �̹������� �߶�� ũ�⸦ �����մϴ�.
	SetCropSize(96, 47);

	// Hover ��带 ����մϴ�.
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
