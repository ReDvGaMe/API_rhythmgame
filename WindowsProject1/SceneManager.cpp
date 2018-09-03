#include "SceneManager.h"



SceneManager::SceneManager() {
	Init();
}


SceneManager::~SceneManager() {
	for (auto it = _SceneList.begin(); it != _SceneList.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
}

void SceneManager::Init() {
	// 씬을 등록
	RegisterScene("FirstScene", new FirstScene());
	RegisterScene("MapToolScene", new MapToolScene());
	RegisterScene("MusicSelectScene", new MusicSelectScene());
	RegisterScene("GameScene", new GameScene());

	// 씬을 설정
	ChangeScene("FirstScene");
}

void SceneManager::RegisterScene(string sceneName, Scene * scene) {
	// 만약 키 값이 비었거나, scene이 NULL 값 이라면 추가하지 않음
	if (sceneName.compare("") == 0 || scene == NULL)	return;

	// 그렇지 않다면 씬을 추가
	_SceneList.insert(make_pair(sceneName, scene));
}

void SceneManager::ChangeScene(string sceneName) {
	// 해당 씬 키값을 찾지 못했다면 실행하지 않음
	if (_SceneList.find(sceneName) == _SceneList.end())	return;

	// 현재 씬의 OnDisable() 을 호출
	// (이 전 씬이 있을 때에만 호출)
	if (_PlayScene != NULL)	_PlayScene->OnDisable();

	// 그렇지 않다면 씬을 변경
	_PlayScene = _SceneList.find(sceneName)->second;

	// 변경된 씬의 OnEnable() 을 호출
	_PlayScene->OnEnable();
}

void SceneManager::Update() {
	// _PlayScene 가 NULL 이 아닐 때만 실행
	if (_PlayScene == NULL)	return;

	_PlayScene->Update();
}

void SceneManager::Render(HDC hdc) {
	// _PlayScene 가 NULL 이 아닐 때만 실행
	if (_PlayScene == NULL)	return;

	_PlayScene->Render(hdc);
}
