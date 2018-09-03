#include "MusicSelectBackGround.h"



MusicSelectBackGround::MusicSelectBackGround() {
	Init();
}


MusicSelectBackGround::~MusicSelectBackGround() {
}

void MusicSelectBackGround::Init() {
	// 이미지 불러오기
	LoadBMPImg(L"Resource\\LogoImage\\musicselectbackgroundimage3.bmp", 0, 0);

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// 오브젝트 크기 설정
	SetObjectWH(WND_WIDTH, WND_HEIGHT * 1.2);

	// 초기 좌표 설정
	m_PosX = WND_WIDTH / 2;
	m_PosY = WND_HEIGHT / 2;

	_MovePosY = m_PosY;

	UpdateRect();
}

void MusicSelectBackGround::Update() {
	BaseUpdate();
	if (_MoveUp) {
		if (m_PosY > 580)	_MoveUp = false;
		_MovePosY += 0.5f;
	}
	else {
		if (m_PosY < 400)	_MoveUp = true;
		_MovePosY -= 0.5f;
	}
	m_PosY = _MovePosY;
	UpdateRect();
}

void MusicSelectBackGround::Render(HDC hdc) {
	BaseRender(hdc);
}
