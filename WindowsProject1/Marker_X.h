#pragma once
#include "GameObject.h"
class Marker_X :
	public GameObject {
public:
	Marker_X();
	virtual ~Marker_X();


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

