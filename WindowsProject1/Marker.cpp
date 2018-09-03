#include "Marker.h"



Marker::Marker() {
	Init();
}


Marker::~Marker() {
}

Marker::Marker(string MarkerType, int PosX, int PosY) {
	if (!MarkerType.compare("Z"))
		SetImagePath(L"Resource\\NoteImage\\marker_z.bmp");
	else if (!MarkerType.compare("X"))
		SetImagePath(L"Resource\\NoteImage\\marker_x.bmp");
	else
		return;
	
	SetMarkerPos(PosX, PosY);

	Init();
}

void Marker::Init() {
	// �̹��� �ҷ�����
	LoadBMPImg(_ImagePath, 0, 0);

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

	// ������Ʈ ũ�� ����
	SetObjectWH(200, 200);
	SetCropSize(_CropSize, _CropSize);	// �̹������� �߶�� ũ�� ����

	m_UseSprite = true;		// ��������Ʈ �̹��� ���
	SetSpriteIndex(0, 4);	// ��������Ʈ ����, �� �ε��� ����
	SetSpriteYIndex(0, 4);	// ��������Ʈ�� �׸��� �����ϴ� Y�ε����� ����
	SetSpriteDelay(100);	// ��������Ʈ ������ ����

	UpdateRect();
}

void Marker::Update() {
	BaseUpdate();

	if (m_DrawYIndex == 4 && m_SpriteIndex == 4)
		_EndMarkerSprite = true;
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

bool Marker::GetEndMarkerSprite() {
	return _EndMarkerSprite;
}
