#pragma once
#include "GameObject.h"
class Marker :
	public GameObject {
public:
	Marker();
	virtual ~Marker();
	Marker(LPCWSTR imagepath, int PosX, int PosY);


#pragma region Variable
private:
public:
	int _CropSize = 100;
	LPCWSTR _ImagePath;
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;

	void SetMarkerPos(int Posx, int Posy);
	void SetImagePath(LPCWSTR imagepath);
#pragma endregion
};

