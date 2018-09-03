#include "LogoImage.h"



LogoImage::LogoImage() {
	Init();
}


LogoImage::~LogoImage() {
}

void LogoImage::Init() {
	// �̹��� �ҷ�����
	LoadPNGImg(L"Resource\\LogoImage\\ModuMaptool.png");

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �ʱ� ��ǥ ����
	m_PosX = WND_WIDTH / 2;
	m_PosY = 100;

	_MovePosY = m_PosY;

	UpdateRect();
}

void LogoImage::Update() {
	BaseUpdate();

	// ���⿡ ���� �����̵��� ����
	// ���� �̵�
	if (_MoveUp) {
		if (m_PosY < 100)	_MoveUp = false;
		_MovePosY -= 0.2f;
	}
	// �Ʒ��� �̵�
	else {
		if (m_PosY > 140)	_MoveUp = true;
		_MovePosY += 0.2f;
	}

	// y ��ǥ�� ����
	m_PosY = _MovePosY;
	UpdateRect();
}

void LogoImage::Render(HDC hdc) {
	BaseRender(hdc);
}
