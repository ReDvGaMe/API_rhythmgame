#include "PauseMenu.h"



PauseMenu::PauseMenu() {
	Init();
}


PauseMenu::~PauseMenu() {
}

void PauseMenu::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\PauseMenu.png");

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// �ʱ� ��ǥ ����
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
