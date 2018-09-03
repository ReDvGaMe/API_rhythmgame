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
	// ��ư Ÿ���� �����մϴ� (up, down)
	string _ButtonType = "up";

	// ������ int ������ ���� ������
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

