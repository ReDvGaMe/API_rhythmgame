#pragma once
#include "FirstScene.h"
#include "MapToolScene.h"
#include "MusicSelectScene.h"
#include "GameScene.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();


#pragma region Variable
private:
	// ����� ���� ������ ���� map
	map<string, Scene*>	_SceneList;

	// �÷������� ���� ������ ���� ���� ����
	Scene*				_PlayScene;
public:
#pragma endregion

#pragma region Method
private:
	// �� ó�� �� ���� �����ų ��� �Լ�
	void	Init();
public:
	// ����� ���� ����ϴ� �Լ�
	void	RegisterScene(string sceneName, Scene* scene);

	// ���� �����ϴ� ��� �Լ�
	void	ChangeScene(string sceneName);

	// ���� ���� Update�� ȣ���ϴ� ��� �Լ�
	void	Update();
	// ���� ���� Render�� ȣ���ϴ� ��� �Լ�
	void	Render(HDC hdc);
#pragma endregion
};

