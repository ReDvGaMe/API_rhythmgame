#pragma once
#include "GameObject.h"
class Marker_Z :
	public GameObject {
public:
	Marker_Z();
	virtual ~Marker_Z();


#pragma region Variable
private:
public:
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()					override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
#pragma endregion
};

