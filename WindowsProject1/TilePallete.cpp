#include "TilePallete.h"
#include "MouseUtil.h"



TilePallete::TilePallete() {
	Init();
}


TilePallete::~TilePallete() {
}

void TilePallete::Init() {
	LoadPNGImg(L"Resource\\TileImage\\MapTile.png");

	// UI이므로 카메라 좌표의 영향을 받지 않도록 함
	m_UseCamPos = false;

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth() * 2, m_Png->GetHeight() * 2);

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	UpdateRect();

	_ShowPosX = WND_WIDTH - 140;
	_HidePosX = WND_WIDTH + 140;

	// 초기 좌표 설정
	m_PosX = _ShowPosX;
	m_PosY = WND_HEIGHT - 325;

	UpdateRect();
}

void TilePallete::Update() {
	// 마우스 왼쪽버튼 클릭
	if (GetAsyncKeyState(VK_LBUTTON))	SelectItem();

	// 타일 지우개 선택			/ Q KEY
	if (GetAsyncKeyState(0x51))	m_SelectTile = -1;

	// 충돌 타일을 찍도록 설정	/ C KEY
	if (GetAsyncKeyState(0x43) & 0x0001)	m_SelectCollTile = !m_SelectCollTile;

	OpenPallete();

	BaseUpdate();

	Log("선택 타일", m_SelectTile);
}

void TilePallete::Render(HDC hdc) {
	BaseRender(hdc);
}

void TilePallete::OpenPallete() {
	// 0x45 = VK_KEYCODE : E KEY
	if (GetAsyncKeyState(0x45) & 0x0001)	m_UsePallete = !m_UsePallete;

	// 애니메이션
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

	// 배열 범위 초과 예외처리
	if (indexX < 0 || indexX > 3 ||
		indexY < 0 || indexY > 8 ||
		!windowActive || !m_UsePallete)	return;

	m_SelectTile = indexX + (indexY * 4);
}
