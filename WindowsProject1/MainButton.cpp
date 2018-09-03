#include "MainButton.h"



MainButton::MainButton() {
}

MainButton::MainButton(string type, int* value) {
	// 버튼 타입을 설정합니다.
	_ButtonType = type;

	_Value = value;

	Init();
}


MainButton::~MainButton() {
}

void MainButton::Init() {
	// 이미지를 불러옵니다.
	if (_ButtonType.compare("up") == 0)			// up 버튼을 불러옵니다.
		LoadPNGImg(L"Resource\\Button\\Btnup.png");
	else if (_ButtonType.compare("down") == 0)	// down 버튼을 불러옵니다 .
		LoadPNGImg(L"Resource\\Button\\Btndown.png");

	// 오브젝트 크기를 설정합니다
	SetObjectWH(22, 13);

	// 이미지에서 잘라올 크기를 설정합니다.
	SetCropSize(22, 13);

	// Hover 모드를 사용합니다.
	m_UseHover = true;
}

void MainButton::Update() {
	BaseUpdate();
	UpdateRect();

	// 클릭 되었다면
	if (CheckClick()) {
		// 값이 9 이상 올라가지 않도록 합니다.
		if (_ButtonType.compare("up") == 0) {
			if (*_Value < 9) (*_Value)++;
		}
		else if (_ButtonType.compare("down") == 0) {
			if (*_Value > 0) (*_Value)--;
		}
	}
}

void MainButton::Render(HDC hdc) {
	BaseRender(hdc);
}
