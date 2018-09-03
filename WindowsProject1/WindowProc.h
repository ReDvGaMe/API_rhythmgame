#pragma once

#include "defines.h"

class WindowProc {
public:
	WindowProc();
	~WindowProc();

	// 발생한 메시지를 처리해 줄 함수
	// 이 곳에서 발생한 모든 메시지에 대한 처리를 해주도록 함
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

