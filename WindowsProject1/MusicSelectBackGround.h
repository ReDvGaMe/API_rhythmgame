#pragma once
#include "GameObject.h"
class MusicSelectBackGround final :
	public GameObject
{
public:
	MusicSelectBackGround();
	virtual ~MusicSelectBackGround();


#pragma region Variable
private:
	bool _MoveUp = true;
	float _MovePosY = 0.0f;
public:
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
#pragma endregion
};

