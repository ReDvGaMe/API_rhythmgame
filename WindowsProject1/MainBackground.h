#pragma once
#include "GameObject.h"
class MainBackground final :
	public GameObject
{
public:
	MainBackground();
	virtual ~MainBackground();


#pragma region Variable
private:
	// �ִϸ��̼��� �����ϱ� ���� ����
	// true �� ��� ���������� �̵�
	bool _MoveRight = true;

	// m_PosX ���� �������� x ��
	float _MovePosX = 0.0f;
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

