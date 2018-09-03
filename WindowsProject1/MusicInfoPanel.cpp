#include "MusicInfoPanel.h"



MusicInfoPanel::MusicInfoPanel() {
	Init();
}


MusicInfoPanel::~MusicInfoPanel() {
}

void MusicInfoPanel::Init() {
	// 이미지 불러오기
	LoadPNGImg	(L"Resource\\LogoImage\\MusicInfoPanel.png");

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// 초기 좌표 설정
	m_PosX = WND_WIDTH / 2;
	m_PosY = 100;
	
	UpdateRect();
}

void MusicInfoPanel::Update() {
	BaseUpdate();
}

void MusicInfoPanel::Render(HDC hdc) {
	BaseRender(hdc);
}
