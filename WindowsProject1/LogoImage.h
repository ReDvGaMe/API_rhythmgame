#pragma once
#include "GameObject.h"
class LogoImage final :
	public GameObject
{
public:
	LogoImage();
	virtual ~LogoImage();


#pragma region Variable
private:
	// �ִϸ��̼��� �����ϱ� ���� ����
	// true �� ��� ���η� �̵�
	bool _MoveUp = false;

	// m_PosY ���� �������� y ��
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

