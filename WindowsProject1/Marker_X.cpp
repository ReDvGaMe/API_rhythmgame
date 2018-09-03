#include "Marker_X.h"



Marker_X::Marker_X() {
	Init();
}


Marker_X::~Marker_X() {
}

void Marker_X::Init() {
	// �̹��� �ҷ�����
	LoadBMPImg(L"Resource\\NoteImage\\marker_x.bmp", 0, 0);

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// ������Ʈ ũ�� ����
	SetObjectWH(180, 180);
	SetCropSize(100, 100);				// �̹������� �߶�� ũ�� ����

	m_UseSprite = true;		// ��������Ʈ �̹��� ���
	SetSpriteIndex(0, 4);	// ��������Ʈ ����, �� �ε��� ����
	SetSpriteIndex(1);		// ��������Ʈ�� �׸��� �����ϴ� Y�ε����� ����
	SetSpriteDelay(100);	// ��������Ʈ ������ ����

	// �ʱ� ��ǥ ����
	m_PosX = 400;
	m_PosY = 380;
	UpdateRect();
}

void Marker_X::Update() {
	BaseUpdate();
}

void Marker_X::Render(HDC hdc) {
	BaseRender(hdc);
}
