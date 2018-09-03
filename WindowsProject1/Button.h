#pragma once
#include "GameObject.h"
class Button abstract :
	public GameObject
{
public:
	Button();
	virtual ~Button();


#pragma region Variable
private:
	// 버튼의 상태
	// (0: normal / 1: hover / 2:pressed)
	int _ButtonState = 0;

	// 버튼이 눌려있는지 체크
	bool _IsPressed = false;

	// 버튼이 클릭되었는지 체크
	bool _IsClicked = false;
public:
	// 버튼의 Hover속성을 사용할 것인지 지정
	bool m_UseHover = false;
#pragma endregion

#pragma region Method
private:
	// 버튼 이미지 BMP 렌더
	void BMPRender(HDC hdc);
	// 버튼 이미지 PNG 렌더
	void PNGRender(HDC hdc);

	// 자르기 시작할 Y위치를 반환
	int StartCropY();
public:
	// 버튼의 상태를 체크
	int CheckState();

	// 버튼이 클릭되었는지 체크
	bool CheckClick();

	// Update와 Render에서 꼭 호출해주어야함
	virtual void BaseUpdate() override;
	virtual void BaseRender(HDC hdc) override;
#pragma endregion
};

