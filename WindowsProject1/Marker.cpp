#include "Marker.h"



Marker::Marker() {
	Init();
}


Marker::~Marker() {
}

Marker::Marker(LPCWSTR imagepath, int PosX, int PosY) {
	SetImagePath(imagepath);
	SetMarkerPos(PosX, PosY);
	Init();
}

void Marker::Init() {
	// �̹��� �ҷ�����
	LoadBMPImg(_ImagePath, 0, 0);

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// ������Ʈ ũ�� ����
	SetObjectWH(180, 180);
	SetCropSize(_CropSize, _CropSize);	// �̹������� �߶�� ũ�� ����

	m_UseSprite = true;		// ��������Ʈ �̹��� ���
	SetSpriteIndex(0, 4);	// ��������Ʈ ����, �� �ε��� ����
	SetSpriteYIndex(0, 4);	// ��������Ʈ�� �׸��� �����ϴ� Y�ε����� ����
	SetSpriteDelay(100);	// ��������Ʈ ������ ����

	// �ʱ� ��ǥ ����
	/*m_PosX = m_PosX;
	m_PosY = m_PosY;*/
	UpdateRect();
}

void Marker::Update() {
	BaseUpdate();
}

void Marker::Render(HDC hdc) {
	BaseRender(hdc);
}

void Marker::SetMarkerPos(int PosX, int PosY) {
	m_PosX = PosX;
	m_PosY = PosY;
}

void Marker::SetImagePath(LPCWSTR imagepath) {
	_ImagePath = imagepath;
}
