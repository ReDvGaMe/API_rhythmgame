#pragma once
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();


#pragma region Variable
private:
public:
#pragma endregion

#pragma region Method
private:
public:
	virtual void	OnEnable()			override;
	virtual void	OnDisable()			override;
	virtual void	Init()				override;
	virtual void	Update()			override;
	virtual void	Render(HDC hdc)		override;
#pragma endregion
};

