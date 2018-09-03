#include "MainPanel.h"



MainPanel::MainPanel() {
	Init();
}


MainPanel::~MainPanel() {
}

void MainPanel::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\Panel2.png");

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// 초기 좌표 설정
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
