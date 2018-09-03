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
	// 애니메이션을 제어하기 위한 변수
	// true 일 경우 오른쪽으로 이동
	bool _MoveRight = true;

	// m_PosX 값에 설정해줄 x 값
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

