#include "MainBackground.h"



MainBackground::MainBackground() {
	Init();
}


MainBackground::~MainBackground() {
}

void MainBackground::Init() {
	// �̹��� �ҷ�����
	LoadBMPImg(L"Resource\\LogoImage\\backgroundImage.bmp", 0, 0);

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// ������Ʈ ũ�� ����
	SetObjectWH(WND_WIDTH * 1.2, WND_HEIGHT * 1.2);

	// �ʱ� ��ǥ ����
	m_PosX = WND_WIDTH / 2;
	m_PosY = WND_HEIGHT / 2;

	_MovePosX = m_PosX;

	UpdateRect();
}

void MainBackground::Update() {
	BaseUpdate();

	// ���⿡ ���� �����̵��� ����
	// ������ �̵�
	if (_MoveRight) {
		if (m_PosX > 700)	_MoveRight = false;
		_MovePosX += 0.2f;
	}
	// ���� �̵�
	else {
		if (m_PosX < 500)	_MoveRight = true;
		_MovePosX -= 0.2f;
	}

	// x ��ǥ�� ����
	m_PosX = _MovePosX;
	UpdateRect();
}

void MainBackground::Render(HDC hdc) {
	BaseRender(hdc);
}