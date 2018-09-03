#include "MainBackground.h"



MainBackground::MainBackground() {
	Init();
}


MainBackground::~MainBackground() {
}

void MainBackground::Init() {
	// 이미지 불러오기
	LoadBMPImg(L"Resource\\LogoImage\\backgroundImage.bmp", 0, 0);

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// 오브젝트 크기 설정
	SetObjectWH(WND_WIDTH * 1.2, WND_HEIGHT * 1.2);

	// 초기 좌표 설정
	m_PosX = WND_WIDTH / 2;
	m_PosY = WND_HEIGHT / 2;

	_MovePosX = m_PosX;

	UpdateRect();
}

void MainBackground::Update() {
	BaseUpdate();

	// 방향에 따라 움직이도록 설정
	// 오른쪽 이동
	if (_MoveRight) {
		if (m_PosX > 700)	_MoveRight = false;
		_MovePosX += 0.2f;
	}
	// 왼쪽 이동
	else {
		if (m_PosX < 500)	_MoveRight = true;
		_MovePosX -= 0.2f;
	}

	// x 좌표에 적용
	m_PosX = _MovePosX;
	UpdateRect();
}

void MainBackground::Render(HDC hdc) {
	BaseRender(hdc);
}