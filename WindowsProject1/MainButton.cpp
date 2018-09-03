#include "MainButton.h"



MainButton::MainButton() {
}

MainButton::MainButton(string type, int* value) {
	// ��ư Ÿ���� �����մϴ�.
	_ButtonType = type;

	_Value = value;

	Init();
}


MainButton::~MainButton() {
}

void MainButton::Init() {
	// �̹����� �ҷ��ɴϴ�.
	if (_ButtonType.compare("up") == 0)			// up ��ư�� �ҷ��ɴϴ�.
		LoadPNGImg(L"Resource\\Button\\Btnup.png");
	else if (_ButtonType.compare("down") == 0)	// down ��ư�� �ҷ��ɴϴ� .
		LoadPNGImg(L"Resource\\Button\\Btndown.png");

	// ������Ʈ ũ�⸦ �����մϴ�
	SetObjectWH(22, 13);

	// �̹������� �߶�� ũ�⸦ �����մϴ�.
	SetCropSize(22, 13);

	// Hover ��带 ����մϴ�.
	m_UseHover = true;
}

void MainButton::Update() {
	BaseUpdate();
	UpdateRect();

	// Ŭ�� �Ǿ��ٸ�
	if (CheckClick()) {
		// ���� 9 �̻� �ö��� �ʵ��� �մϴ�.
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
