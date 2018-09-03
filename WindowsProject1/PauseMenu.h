#pragma once
#include "GameObject.h"
class PauseMenu final :
	public GameObject {
public:
	PauseMenu();
	virtual ~PauseMenu();


#pragma region Variable
private:
public:
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()					override;
	virtual void Update()			override;
	virtual void Render(HDC hdc) override;
#pragma endregion
};

