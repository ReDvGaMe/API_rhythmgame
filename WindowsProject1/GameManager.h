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
	// BASE Ŭ���� WndManager�� ���� �����Լ� Update()�� ����
	virtual void	Update()		override;
	// BASE Ŭ���� WndManager�� ���� �����Լ� Render()�� ����
	virtual void	Render(HDC hdc)	override;
public:
	// GameManager �̱��濡 �����ϱ� ���� ��� �Լ�
	static GameManager*		GetGameManager();

	// SceneManager�� ������ �� ����� �Լ�
	SceneManager* GetSceneManager();

#pragma endregion
};

