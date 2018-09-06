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
	// 배경색 그리기
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(hdc, RGB(0, 0, 0));
	Rectangle(hdc, 0, 0, WND_WIDTH, WND_HEIGHT);

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

	if (_IsPause)
		_PauseMenu.Render(hdc);
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
				gameManager->GetSceneManager()->ChangeScene("MusicSelectScene");
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
	}
	if (GetAsyncKeyState(0x58) & 0x0001) {
		_MousePos.x = MouseUtil::GetClientMousePosition().x;
		_MousePos.y = MouseUtil::GetClientMousePosition().y;
	}
}
