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

	// 좌표 테스트용
	/*
	Rectangle(hdc, 0, 200, 200, 400);
	Rectangle(hdc, 200, 200, 400, 400);
	Rectangle(hdc, 400, 200, 600, 400);
	Rectangle(hdc, 600, 200, 800, 400);

	Rectangle(hdc, 0, 400, 200, 600);
	Rectangle(hdc, 200, 400, 400, 600);
	Rectangle(hdc, 400, 400, 600, 600);
	Rectangle(hdc, 600, 400, 800, 600);

	Rectangle(hdc, 0, 600, 200, 800);
	Rectangle(hdc, 200, 600, 400, 800);
	Rectangle(hdc, 400, 600, 600, 800);
	Rectangle(hdc, 600, 600, 800, 800);

	Rectangle(hdc, 0, 800, 200, 1000);
	Rectangle(hdc, 200, 800, 400, 1000);
	Rectangle(hdc, 400, 800, 600, 1000);
	Rectangle(hdc, 600, 800, 800, 1000);
	*/
}

void GameScene::KeyInput() {
	// 창 활성화때만 키 입력을 받음
	if (!windowActive)	return;

	// 일시정지 시
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

	// esc 키 입력 시 일시정지 활성화
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
		_IsPause = true;
		ingame_PauseMenu = m_PauseMenu::Resume;
	}

	if (GetAsyncKeyState(0x5A) & 0x0001) {
		_MousePos.x = MouseUtil::GetClientMousePosition().x;
		_MousePos.y = MouseUtil::GetClientMousePosition().y;

		/*_MarkerManager.MakeMarker("Z", _MousePos.x, _MousePos.y);*/
		for (int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++)
				_MarkerManager.MakeMarker("Z", i, j);
		}
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

		/*_MarkerManager.MakeMarker("X", _MousePos.x, _MousePos.y);*/
		_MarkerManager.MakeMarker("X", _MousePos.x, _MousePos.y);
		//Log("_X KEY MARKER_", MarkerPosArr[3][3].x, MarkerPosArr[3][3].y);
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
