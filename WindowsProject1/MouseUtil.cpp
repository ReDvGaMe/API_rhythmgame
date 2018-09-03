#include "MouseUtil.h"
#include "GameManager.h"



MouseUtil::MouseUtil() {
}


MouseUtil::~MouseUtil() {
}

POINT MouseUtil::GetWindowMousePosition() {
	POINT mouse;
	GetCursorPos(&mouse);
	return mouse;
}

POINT MouseUtil::GetClientMousePosition() {
	POINT mouse;
	GetCursorPos(&mouse);		// ȭ��� ���콺 ��ǥ ��������
	// Ŭ���̾�Ʈ �������� ��ȯ
	ScreenToClient(GameManager::GetGameManager()->GetWnd(), &mouse);
	return mouse;
}