#include "CameraUtil.h"



CameraUtil::CameraUtil() {
}


CameraUtil::~CameraUtil() {
}

CameraUtil * CameraUtil::GetCam() {
	static CameraUtil _Cam;
	return &_Cam;
}

int CameraUtil::GetPositionX() {
	return _PosX;
}

int CameraUtil::GetPositionY() {
	return _PosY;
}

void CameraUtil::SetPosition(POINT pos) {
	_PosX = pos.x;
	_PosY = pos.y;
}

void CameraUtil::AddPositionX(int posX) {
	_PosX += posX;
}

void CameraUtil::AddPositionY(int posY) {
	_PosY += posY;
}
