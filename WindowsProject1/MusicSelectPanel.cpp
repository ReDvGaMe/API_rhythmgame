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

	// 오브젝트 크기 설정
	SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

	// 이미지에서 잘라올 크기 설정
	SetCropSize(m_Png->GetWidth(), m_Png->GetHeight());

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 초기 좌표 설정
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

	// 이미지를 띄울 것인지 체크
	if (!m_ShowImage)	return;

	// 만약 창 영역 안에 있지 않다면 그리지 않음
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
	// 카메라 좌표
	int camPosX = 0;
	int camPosY = 0;

	// 카메라를 사용하고 있다면
	if (m_UseCamPos) {
		camPosX = CameraUtil::GetCam()->GetPositionX();
		camPosY = CameraUtil::GetCam()->GetPositionY();
	}

	// 오브젝트 영역 동기화
	// (좌표를 오브젝트의 가운데로 설정합니다.)
	m_Rect[j][i] = {
		m_PosX[j] - (m_Width / 2) + camPosX,
		m_PosY[i] - (m_Height / 2) + camPosY,
		m_PosX[j] + (m_Width / 2) + camPosX,
		m_PosY[i] + (m_Height / 2) + camPosY
	};
}
