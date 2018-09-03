#include "MainPanel.h"



MainPanel::MainPanel() {
	Init();
}


MainPanel::~MainPanel() {
}

void MainPanel::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\Panel2.png");

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// �ʱ� ��ǥ ����
	m_PosX = WND_WIDTH / 2 - 7;
	m_PosY = WND_HEIGHT / 10 * 7 + 35;
	UpdateRect();
}

void MainPanel::Update() {
	BaseUpdate();
}

void MainPanel::Render(HDC hdc) {
	BaseRender(hdc);
}
