#pragma once
#include "GameObject.h"
class Marker :
	public GameObject {
public:
	Marker();
	virtual ~Marker();

	Marker(string MarkerType, int PosX, int PosY);


#pragma region Variable
private:
public:
	// 이미지 사이즈
	int _ObjSize = 200;

	// 자를 사이즈
	int _CropSize = 100;

	// 이미지 경로
	LPCWSTR _ImagePath;

	// 스프라이트를 모두 출력했는지 검사
	bool _EndMarkerSprite = false;
#pragma endregion

#pragma region Method
private:
	// 마커 좌표 설정
	void SetMarkerPos(int PosX, int PosY);

	// 이미지 경로 설정
	void SetImagePath(LPCWSTR imagepath);
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;

	bool GetEndMarkerSprite();
#pragma endregion
};