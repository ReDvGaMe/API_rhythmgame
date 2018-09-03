#include "MusicSelectEdge.h"



MusicSelectEdge::MusicSelectEdge() {
	Init();
}


MusicSelectEdge::~MusicSelectEdge() {
}

void MusicSelectEdge::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\MusicSelectEdge.png");

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// �ʱ� ��ǥ ����
	m_PosX = 100;
	m_PosY = 300;
	UpdateRect();
}

void MusicSelectEdge::Update() {
	BaseUpdate();
}

void MusicSelectEdge::Render(HDC hdc) {
	BaseRender(hdc);
}

void MusicSelectEdge::UpdateEdgePos(int MusicNo) {
	int indexY = MusicNo / 4;
	int indexX = MusicNo - (indexY * 4);
	m_PosX = 100 + (195 * indexX);
	m_PosY = 300 + (190 * indexY);
	UpdateRect();
}
