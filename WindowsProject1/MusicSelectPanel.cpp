#include "MusicSelectPanel.h"
#include "GameManager.h"
#include "CameraUtil.h"



MusicSelectPanel::MusicSelectPanel() {
	Init();
}


MusicSelectPanel::~MusicSelectPanel() {
}

void MusicSelectPanel::Init() {
	LoadPNGImg(L"Resource\\LogoImage\\MusicSelectPanel.png");

	// ������Ʈ ũ�� ����
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// �̹������� �߶�� ũ�� ����
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// �ʱ� ��ǥ ����
			m_PosX[j] = 100 + (200 * j);
			m_PosY[i] = 300 + (200 * i);
			UpdateRect(i, j);
		}
	}
}

void MusicSelectPanel::Update() {
	BaseUpdate();
}

void MusicSelectPanel::Render(HDC hdc) {
	BaseRender(hdc);
}

void MusicSelectPanel::Render(HDC hdc, int i, int j) {
	if (!m_Active)	return;

	// �̹����� ��� ������ üũ
	if (!m_ShowImage)	return;

	// ���� â ���� �ȿ� ���� �ʴٸ� �׸��� ����
	RECT dest;
	if (!IntersectRect(&dest, &GameManager::GetGameManager()->GetWndRect(), &m_Rect[j][i]))	return;

	m_Png->DrawImage(
		hdc,
		m_Rect[j][i].left, m_Rect[j][i].top,
		m_Width, m_Height,
		(m_UseSprite) ? m_SpriteIndex * m_CropWidth : 0,
		(m_UseSprite) ? m_DrawYIndex * m_CropHeight : 0,
		m_CropWidth, m_CropHeight
	);
}

void MusicSelectPanel::UpdateRect(int i, int j) {
	// ī�޶� ��ǥ
	int camPosX = 0;
	int camPosY = 0;

	// ī�޶� ����ϰ� �ִٸ�
	if (m_UseCamPos) {
		camPosX = CameraUtil::GetCam()->GetPositionX();
		camPosY = CameraUtil::GetCam()->GetPositionY();
	}

	// ������Ʈ ���� ����ȭ
	// (��ǥ�� ������Ʈ�� ����� �����մϴ�.)
	m_Rect[j][i] = {
		m_PosX[j] - (m_Width / 2) + camPosX,
		m_PosY[i] - (m_Height / 2) + camPosY,
		m_PosX[j] + (m_Width / 2) + camPosX,
		m_PosY[i] + (m_Height / 2) + camPosY
	};
}
