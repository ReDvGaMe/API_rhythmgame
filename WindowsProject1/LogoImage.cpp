#include "LogoImage.h"



LogoImage::LogoImage() {
	Init();
}


LogoImage::~LogoImage() {
}

void LogoImage::Init() {
	// 이미지 불러오기
	LoadPNGImg(L"Resource\\LogoImage\\ModuMaptool.png");

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 초기 좌표 설정
	m_PosX = WND_WIDTH / 2;
	m_PosY = 100;

	_MovePosY = m_PosY;

	UpdateRect();
}

void LogoImage::Update() {
	BaseUpdate();

	// 방향에 따라 움직이도록 설정
	// 위쪽 이동
	if (_MoveUp) {
		if (m_PosY < 100)	_MoveUp = false;
		_MovePosY -= 0.2f;
	}
	// 아래쪽 이동
	else {
		if (m_PosY > 140)	_MoveUp = true;
		_MovePosY += 0.2f;
	}

	// y 좌표에 적용
	m_PosY = _MovePosY;
	UpdateRect();
}

void LogoImage::Render(HDC hdc) {
	BaseRender(hdc);
}
