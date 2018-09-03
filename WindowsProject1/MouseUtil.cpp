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
	GetCursorPos(&mouse);		// 화면상 마우스 좌표 가져오기
	// 클라이언트 기준으로 변환
	ScreenToClient(GameManager::GetGameManager()->GetWnd(), &mouse);
	return mouse;
}