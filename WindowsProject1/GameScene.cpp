#include "GameScene.h"
#include "GameManager.h"



GameScene::GameScene() {
	Init();
}

GameScene::~GameScene() {
}

void GameScene::OnEnable() {
}

void GameScene::OnDisable() {
}

void GameScene::Init() {
}

void GameScene::Update() {
	KeyInput();
	_MusicInfoPanel.Update();
	_MarkerManager.Update();
}

void GameScene::Render(HDC hdc) {
	_MusicInfoPanel.Render(hdc);
	_MarkerManager.Render(hdc);
}

void GameScene::KeyInput() {
	if (!windowActive)	return;

	if (_IsPause) {
		GameManager* gameManager = GameManager::GetGameManager();

		if (GetAsyncKeyState(VK_UP) & 0x0001 || GetAsyncKeyState(0x57) & 0x0001) {
			switch (ingame_PauseMenu) {
			case m_PauseMenu::MainMenu:
				ingame_PauseMenu = m_PauseMenu::Resume;
				return;
			default:
				return;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001 || GetAsyncKeyState(0x53) & 0x0001) {
			switch (ingame_PauseMenu) {
			case m_PauseMenu::Resume:
				ingame_PauseMenu = m_PauseMenu::MainMenu;
				return;
			default:
				return;
			}
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001 || GetAsyncKeyState(VK_SPACE) & 0x0001) {
			switch (ingame_PauseMenu) {
			case m_PauseMenu::Resume:
				_IsPause = false;
				return;
			case m_PauseMenu::MainMenu:
				_IsPause = false;
				gameManager->GetSceneManager()->ChangeScene("MusicSelectSecene");
			default:
				return;
			}
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
		_IsPause = true;
		ingame_PauseMenu = m_PauseMenu::Resume;
	}

	if (GetAsyncKeyState(0x5A) & 0x0001) {
		_MousePos.x = MouseUtil::GetClientMousePosition().x;
		_MousePos.y = MouseUtil::GetClientMousePosition().y;

		_MarkerManager.MakeMarker("Z", _MousePos.x, _MousePos.y);
		Log("_Z KEY MARKER_", _MousePos.x, _MousePos.y);
		/*if (_MousePos.x > (_Marker.m_PosX - _Marker._CropSize - 10) &&
			_MousePos.x < (_Marker.m_PosX + _Marker._CropSize + 10) &&
			_MousePos.y > (_Marker.m_PosY - _Marker._CropSize - 10) &&
			_MousePos.y < (_Marker.m_PosY + _Marker._CropSize + 10)) {
			Log("_Z KEY MARKER_", _Marker.m_PosX - _Marker._CropSize, _Marker.m_PosX + _Marker._CropSize);
			Log("_Z KEY MARKER_", _Marker.m_PosY - _Marker._CropSize, _Marker.m_PosY + _Marker._CropSize);
			Log("_Z KEY MousPos_", _MousePos.x, _MousePos.y);
		}*/
	}
	if (GetAsyncKeyState(0x58) & 0x0001) {
		_MousePos.x = MouseUtil::GetClientMousePosition().x;
		_MousePos.y = MouseUtil::GetClientMousePosition().y;

		_MarkerManager.MakeMarker("X", _MousePos.x, _MousePos.y);
		Log("_X KEY MARKER_", _MousePos.x, _MousePos.y);

	/*	if (_MousePos.x > (_Marker.m_PosX - _Marker._CropSize - 10) &&
			_MousePos.x < (_Marker.m_PosX + _Marker._CropSize - 10) &&
			_MousePos.y > (_Marker.m_PosY - _Marker._CropSize - 10) &&
			_MousePos.y < (_Marker.m_PosY + _Marker._CropSize - 10)) {
			Log("_X KEY MARKER_", _Marker.m_PosX - _Marker._CropSize, _Marker.m_PosX + _Marker._CropSize);
			Log("_X KEY MARKER_", _Marker.m_PosY - _Marker._CropSize, _Marker.m_PosY + _Marker._CropSize);
			Log("_X KEY MousPos_", _MousePos.x, _MousePos.y);
		}*/
	}
}
