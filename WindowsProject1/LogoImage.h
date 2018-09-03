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
	// 애니메이션을 제어하기 위한 변수
	// true 일 경우 위로로 이동
	bool _MoveUp = false;

	// m_PosY 값에 설정해줄 y 값
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

