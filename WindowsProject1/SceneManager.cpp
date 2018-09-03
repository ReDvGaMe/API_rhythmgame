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
	// ���� ���
	RegisterScene("FirstScene", new FirstScene());
	RegisterScene("MapToolScene", new MapToolScene());
	RegisterScene("MusicSelectScene", new MusicSelectScene());
	RegisterScene("GameScene", new GameScene());

	// ���� ����
	ChangeScene("FirstScene");
}

void SceneManager::RegisterScene(string sceneName, Scene * scene) {
	// ���� Ű ���� ����ų�, scene�� NULL �� �̶�� �߰����� ����
	if (sceneName.compare("") == 0 || scene == NULL)	return;

	// �׷��� �ʴٸ� ���� �߰�
	_SceneList.insert(make_pair(sceneName, scene));
}

void SceneManager::ChangeScene(string sceneName) {
	// �ش� �� Ű���� ã�� ���ߴٸ� �������� ����
	if (_SceneList.find(sceneName) == _SceneList.end())	return;

	// ���� ���� OnDisable() �� ȣ��
	// (�� �� ���� ���� ������ ȣ��)
	if (_PlayScene != NULL)	_PlayScene->OnDisable();

	// �׷��� �ʴٸ� ���� ����
	_PlayScene = _SceneList.find(sceneName)->second;

	// ����� ���� OnEnable() �� ȣ��
	_PlayScene->OnEnable();
}

void SceneManager::Update() {
	// _PlayScene �� NULL �� �ƴ� ���� ����
	if (_PlayScene == NULL)	return;

	_PlayScene->Update();
}

void SceneManager::Render(HDC hdc) {
	// _PlayScene �� NULL �� �ƴ� ���� ����
	if (_PlayScene == NULL)	return;

	_PlayScene->Render(hdc);
}
