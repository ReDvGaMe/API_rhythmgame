#pragma once
#include "defines.h"

class CameraUtil {
public:
	CameraUtil();
	~CameraUtil();
#pragma region Variable
private:
	// ī�޶� ��ġ
	int _PosX = 0;
	int _PosY = 0;
public:
#pragma endregion


#pragma region Method
private:
public:
	// ī�޶� �̱���
	static CameraUtil* GetCam();

	// ���� ī�޶��� ��ġ�� ������
	int GetPositionX();
	int GetPositionY();

	// ī�޶��� ��ġ�� ������
	void SetPosition(POINT pos);

	// ī�޶��� ��ġ�� ��� ���� ����
	void AddPositionX(int posX);
	void AddPositionY(int posY);
#pragma endregion
};

