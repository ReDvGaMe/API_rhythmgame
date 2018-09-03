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
	// ��ư�� ����
	// (0: normal / 1: hover / 2:pressed)
	int _ButtonState = 0;

	// ��ư�� �����ִ��� üũ
	bool _IsPressed = false;

	// ��ư�� Ŭ���Ǿ����� üũ
	bool _IsClicked = false;
public:
	// ��ư�� Hover�Ӽ��� ����� ������ ����
	bool m_UseHover = false;
#pragma endregion

#pragma region Method
private:
	// ��ư �̹��� BMP ����
	void BMPRender(HDC hdc);
	// ��ư �̹��� PNG ����
	void PNGRender(HDC hdc);

	// �ڸ��� ������ Y��ġ�� ��ȯ
	int StartCropY();
public:
	// ��ư�� ���¸� üũ
	int CheckState();

	// ��ư�� Ŭ���Ǿ����� üũ
	bool CheckClick();

	// Update�� Render���� �� ȣ�����־����
	virtual void BaseUpdate() override;
	virtual void BaseRender(HDC hdc) override;
#pragma endregion
};

