#include "MusicSelectScene.h"
#include "GameManager.h"



MusicSelectScene::MusicSelectScene() {
	Init();
}


MusicSelectScene::~MusicSelectScene() {
	OnDisable();
}

void MusicSelectScene::KeyInput() {
	if (!windowActive)	return;

	GameManager* gameManager = GameManager::GetGameManager();

	if (_IsPause) {
		if (GetAsyncKeyState(VK_UP) & 0x0001 || GetAsyncKeyState(0x57) & 0x0001) {
			switch (m_PauseMenu) {
			case m_PauseMenu::Setting:
				m_PauseMenu = m_PauseMenu::Resume;
				return;
			case m_PauseMenu::MainMenu:
				m_PauseMenu = m_PauseMenu::Setting;
				return;
			default:
				return;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001 || GetAsyncKeyState(0x53) & 0x0001) {
			switch (m_PauseMenu) {
			case m_PauseMenu::Resume:
				m_PauseMenu = m_PauseMenu::Setting;
				return;
			case m_PauseMenu::Setting:
				m_PauseMenu = m_PauseMenu::MainMenu;
				return;
			default:
				return;
			}
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001 || GetAsyncKeyState(VK_SPACE) & 0x0001) {
			switch (m_PauseMenu) {
			case m_PauseMenu::Resume:
				_IsPause = false;
				return;
			case m_PauseMenu::Setting:
				_IsPause = false;
				return;
			case m_PauseMenu::MainMenu:
				_IsPause = false;
				gameManager->GetSceneManager()->ChangeScene("FirstScene");
			default:
				return;
			}
		}
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001 || GetAsyncKeyState(0x57) & 0x0001) {
		if (_MusicSelectNum / 4 == 0)	return;
		_MusicSelectNum -= 4;
		_MusicSelectEdge.UpdateEdgePos(_MusicSelectNum);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x0001 || GetAsyncKeyState(0x53) & 0x0001) {
		if (_MusicSelectNum / 4 == 3)	return;
		_MusicSelectNum += 4;
		_MusicSelectEdge.UpdateEdgePos(_MusicSelectNum);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 || GetAsyncKeyState(0x44) & 0x0001) {
		if (_MusicSelectNum == 15)	return;
		_MusicSelectNum += 1;
		_MusicSelectEdge.UpdateEdgePos(_MusicSelectNum);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x0001 || GetAsyncKeyState(0x41) & 0x0001) {
		if (_MusicSelectNum == 0)		return;
		_MusicSelectNum -= 1;
		_MusicSelectEdge.UpdateEdgePos(_MusicSelectNum);
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x0001 || GetAsyncKeyState(VK_SPACE) & 0x0001) {
		gameManager->GetSceneManager()->ChangeScene("GameScene");
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
		_IsPause = true;
		m_PauseMenu = m_PauseMenu::Resume;
	}
}

void MusicSelectScene::OnEnable() {
	_MusicSelectPage = 0;
	_MusicSelectNum = 0;
}

void MusicSelectScene::OnDisable() {
}

void MusicSelectScene::Init() {
	_MusicSelectPage = 0;
	_MusicSelectNum = 0;
}

void MusicSelectScene::Update() {
	_MusicSelectBackgournd.Update();
	_MusicSelectPanel.Update();
	_MusicSelectEdge.Update();
	_PauseMenu.Update();
	_MusicInfoPanel.Update();

	KeyInput();
}

void MusicSelectScene::Render(HDC hdc) {
	_MusicSelectBackgournd.Render(hdc);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_MusicSelectPanel.Render(hdc, i, j);
		}
	}
	_MusicSelectEdge.Render(hdc);

	if (_IsPause)
		_PauseMenu.Render(hdc);

	_MusicInfoPanel.Render(hdc);
}
