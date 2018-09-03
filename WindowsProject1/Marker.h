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
	int _CropSize = 100;
	LPCWSTR _ImagePath;
	bool _EndMarkerSprite = false;
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;

	void SetMarkerPos(int PosX, int PosY);
	void SetImagePath(LPCWSTR imagepath);
	bool GetEndMarkerSprite();
#pragma endregion
};

