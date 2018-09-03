#include "Object.h"
#include "CameraUtil.h"



Object::Object() {
}


Object::~Object() {
}

void Object::UpdateRect() {
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
	m_Rect = {
		m_PosX - (m_Width / 2) + camPosX,
		m_PosY - (m_Height / 2) + camPosY,
		m_PosX + (m_Width / 2) + camPosX,
		m_PosY + (m_Height / 2) + camPosY
	};
}
