#pragma once

#include "defines.h"

class WindowProc {
public:
	WindowProc();
	~WindowProc();

	// �߻��� �޽����� ó���� �� �Լ�
	// �� ������ �߻��� ��� �޽����� ���� ó���� ���ֵ��� ��
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

