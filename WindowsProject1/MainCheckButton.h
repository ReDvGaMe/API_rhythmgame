#pragma once
#include "Button.h"
class MainCheckButton :
	public Button {
public:
	MainCheckButton();
	virtual ~MainCheckButton();

#pragma region Variable
private:

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

