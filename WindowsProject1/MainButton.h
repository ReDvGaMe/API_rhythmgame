#pragma once
#include "Button.h"
class MainButton :
	public Button {
public:
	MainButton();
	MainButton(string type, int* value);
	virtual ~MainButton();

#pragma region Variable
private:
	// 버튼 타입을 설정합니다 (up, down)
	string _ButtonType = "up";

	// 설정한 int 변수에 대한 포인터
	int* _Value;

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

