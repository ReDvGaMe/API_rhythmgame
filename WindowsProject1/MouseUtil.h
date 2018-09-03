#pragma once
#include "defines.h"

class MouseUtil {
public:
	MouseUtil();
	~MouseUtil();

#pragma region Variable
private:

public:


#pragma endregion


#pragma region Method
private:

public:
	// 모니터 화면을 기준으로 마우스의 좌표값을 받아옴
	static POINT GetWindowMousePosition();

	// 클라인트 화면을 기준으로 마우스의 좌표값을 받아옴
	static POINT GetClientMousePosition();


#pragma endregion
};