#include "Object.h"
#include "CameraUtil.h"



Object::Object() {
}


Object::~Object() {
}

void Object::UpdateRect() {
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
	m_Rect = {
		m_PosX - (m_Width / 2) + camPosX,
		m_PosY - (m_Height / 2) + camPosY,
		m_PosX + (m_Width / 2) + camPosX,
		m_PosY + (m_Height / 2) + camPosY
	};
}
