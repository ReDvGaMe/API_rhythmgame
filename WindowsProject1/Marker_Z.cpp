#include "Marker_Z.h"



Marker_Z::Marker_Z() {
	Init();
}


Marker_Z::~Marker_Z() {
}

void Marker_Z::Init() {
	// �̹��� �ҷ�����
	LoadBMPImg(L"Resource\\NoteImage\\marker_z.bmp", 0, 0);

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
	m_PosX = 180;
	m_PosY = 380;
	UpdateRect();
}

void Marker_Z::Update() {
	BaseUpdate();
}

void Marker_Z::Render(HDC hdc) {
	BaseRender(hdc);
}
