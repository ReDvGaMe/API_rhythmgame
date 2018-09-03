#include "MusicInfoPanel.h"



MusicInfoPanel::MusicInfoPanel() {
	Init();
}


MusicInfoPanel::~MusicInfoPanel() {
}

void MusicInfoPanel::Init() {
	// �̹��� �ҷ�����
	LoadPNGImg	(L"Resource\\LogoImage\\MusicInfoPanel.png");

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// �ʱ� ��ǥ ����
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
