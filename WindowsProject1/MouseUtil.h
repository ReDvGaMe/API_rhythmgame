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
	// ����� ȭ���� �������� ���콺�� ��ǥ���� �޾ƿ�
	static POINT GetWindowMousePosition();

	// Ŭ����Ʈ ȭ���� �������� ���콺�� ��ǥ���� �޾ƿ�
	static POINT GetClientMousePosition();


#pragma endregion
};