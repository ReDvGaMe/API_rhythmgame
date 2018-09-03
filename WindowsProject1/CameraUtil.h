#pragma once
#include "defines.h"

class CameraUtil {
public:
	CameraUtil();
	~CameraUtil();
#pragma region Variable
private:
	// 카메라 위치
	int _PosX = 0;
	int _PosY = 0;
public:
#pragma endregion


#pragma region Method
private:
public:
	// 카메라 싱글톤
	static CameraUtil* GetCam();

	// 현재 카메라의 위치를 가져옴
	int GetPositionX();
	int GetPositionY();

	// 카메라의 위치를 설정함
	void SetPosition(POINT pos);

	// 카메라의 위치에 어떠한 값을 증가
	void AddPositionX(int posX);
	void AddPositionY(int posY);
#pragma endregion
};

