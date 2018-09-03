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
	// 사용할 씬을 가지고 있을 map
	map<string, Scene*>	_SceneList;

	// 플레이중인 씬을 가지고 있을 참조 변수
	Scene*				_PlayScene;
public:
#pragma endregion

#pragma region Method
private:
	// 맨 처음 한 번만 실행시킬 멤버 함수
	void	Init();
public:
	// 사용할 씬을 등록하는 함수
	void	RegisterScene(string sceneName, Scene* scene);

	// 씬을 변경하는 멤버 함수
	void	ChangeScene(string sceneName);

	// 현재 씬의 Update를 호출하는 멤버 함수
	void	Update();
	// 현재 씬의 Render를 호출하는 멤버 함수
	void	Render(HDC hdc);
#pragma endregion
};

