#pragma once
#include "WndManager.h"
#include "SceneManager.h"


class GameManager final :
	public WndManager {
public:
	GameManager();
	virtual ~GameManager();


#pragma region Variable
private:
	SceneManager *			_SceneManager;
public:
#pragma endregion

#pragma region Method
private:
	// BASE 클래스 WndManager의 순수 가상함수 Update()를 구현
	virtual void	Update()		override;
	// BASE 클래스 WndManager의 순수 가상함수 Render()를 구현
	virtual void	Render(HDC hdc)	override;
public:
	// GameManager 싱글톤에 접근하기 위한 멤버 함수
	static GameManager*		GetGameManager();

	// SceneManager에 접근할 때 사용할 함수
	SceneManager* GetSceneManager();

#pragma endregion
};

