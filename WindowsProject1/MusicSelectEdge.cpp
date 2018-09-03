#include "MusicSelectEdge.h"



MusicSelectEdge::MusicSelectEdge() {
	Init();
}


MusicSelectEdge::~MusicSelectEdge() {
}

void MusicSelectEdge::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\MusicSelectEdge.png");

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// 초기 좌표 설정
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
