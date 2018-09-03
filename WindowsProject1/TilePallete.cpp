#include "TilePallete.h"
#include "MouseUtil.h"



TilePallete::TilePallete() {
	Init();
}


TilePallete::~TilePallete() {
}

void TilePallete::Init() {
	LoadPNGImg(L"Resource\\TileImage\\MapTile.png");

	// UI�̹Ƿ� ī�޶� ��ǥ�� ������ ���� �ʵ��� ��
	m_UseCamPos = false;

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth() * 2, m_Png->GetHeight() * 2);

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	UpdateRect();

	_ShowPosX = WND_WIDTH - 140;
	_HidePosX = WND_WIDTH + 140;

	// �ʱ� ��ǥ ����
	m_PosX = _ShowPosX;
	m_PosY = WND_HEIGHT - 325;

	UpdateRect();
}

void TilePallete::Update() {
	// ���콺 ���ʹ�ư Ŭ��
	if (GetAsyncKeyState(VK_LBUTTON))	SelectItem();

	// Ÿ�� ���찳 ����			/ Q KEY
	if (GetAsyncKeyState(0x51))	m_SelectTile = -1;

	// �浹 Ÿ���� �ﵵ�� ����	/ C KEY
	if (GetAsyncKeyState(0x43) & 0x0001)	m_SelectCollTile = !m_SelectCollTile;

	OpenPallete();

	BaseUpdate();

	Log("���� Ÿ��", m_SelectTile);
}

void TilePallete::Render(HDC hdc) {
	BaseRender(hdc);
}

void TilePallete::OpenPallete() {
	// 0x45 = VK_KEYCODE : E KEY
	if (GetAsyncKeyState(0x45) & 0x0001)	m_UsePallete = !m_UsePallete;

	// �ִϸ��̼�
	if (m_UsePallete) {
		if (m_PosX != _ShowPosX)	m_PosX -= 2;
		if (m_PosX <  _ShowPosX)	m_PosX = _ShowPosX;
	}
	else {
		if (m_PosX != _HidePosX)	m_PosX += 2;
		if (m_PosX >  _HidePosX)	m_PosX = _HidePosX;
	}

	UpdateRect();
}

void TilePallete::SelectItem() {
	int indexX = (MouseUtil::GetClientMousePosition().x - m_Rect.left) / 64;
	int indexY = (MouseUtil::GetClientMousePosition().y - m_Rect.top ) / 64;

	// �迭 ���� �ʰ� ����ó��
	if (indexX < 0 || indexX > 3 ||
		indexY < 0 || indexY > 8 ||
		!windowActive || !m_UsePallete)	return;

	m_SelectTile = indexX + (indexY * 4);
}
