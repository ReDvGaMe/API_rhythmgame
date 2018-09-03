#include "FirstScene.h"
#include "MapData.h"
#include "GameManager.h"



FirstScene::FirstScene() {
	Init();
}


FirstScene::~FirstScene() {
	OnDisable();
}

void FirstScene::InitTextView() {
	// �޴� ��� �ؽ�Ʈ
	// ��Ʈ ����
	_GuideGameStart.SetFont(L"segoe UI");
	_GuideSetting.SetFont(L"segoe UI");
	_GuideExit.SetFont(L"segoe UI");

	// ��Ʈ ũ��
	_GuideGameStart.SetFontSize(_TextSize);
	_GuideSetting.	SetFontSize(_TextSize);
	_GuideExit.		SetFontSize(_TextSize);

	// ��ġ ����
	_GuideGameStart.SetPosition(WND_WIDTH / 2 - (_TextSize * 3), WND_HEIGHT / 10 * 7);
	_GuideSetting.SetPosition(WND_WIDTH / 2 - (_TextSize * 2), WND_HEIGHT / 10 * 7);
	_GuideExit.SetPosition(WND_WIDTH / 2 - (_TextSize * 1), WND_HEIGHT / 10 * 7);

	// ��� �ؽ�Ʈ ����
	_GuideGameStart.SetText(L"Game Start");
	_GuideSetting.SetText(L"Setting");
	_GuideExit.SetText(L"Exit");

	// �ؽ�Ʈ ��Ÿ�� ����
	_GuideGameStart.SetFontStyle(1, 0, 0, 0);
	_GuideSetting.SetFontStyle(1, 0, 0, 0);
	_GuideExit.SetFontStyle(1, 0, 0, 0);

	// �ؽ�Ʈ ���� ����
	_GuideGameStart.SetFontColor(255, 197, 28);
	_GuideSetting.SetFontColor(255, 197, 28);
	_GuideExit.SetFontColor(255, 197, 28);
}

void FirstScene::KeyInput() {
	if (!windowActive)	return;

	// ��Ű Ȥ�� wŰ
	if (GetAsyncKeyState(VK_UP) & 0x0001 || GetAsyncKeyState(0x57) & 0x0001) {
		switch (_StartMenu) {
		case StartMenu::Setting:
			_StartMenu = StartMenu::Start;
			break;
		case StartMenu::Exit:
			_StartMenu = StartMenu::Setting;
			break;
		default:
			break;
		}
	}
	// �Ʒ�Ű Ȥ�� dŰ
	else if (GetAsyncKeyState(VK_DOWN) & 0x0001 || GetAsyncKeyState(0x53) & 0x0001) {
		switch (_StartMenu) {
		case StartMenu::Start:
			_StartMenu = StartMenu::Setting;
			break;
		case StartMenu::Setting:
			_StartMenu = StartMenu::Exit;
			break;
		default:
			break;
		}
	}

	// ����Ű Ȥ�� �����̽��ٷ� �� ��ȯ
	if (GetAsyncKeyState(VK_RETURN) & 0x0001 || GetAsyncKeyState(VK_SPACE) & 0x0001) {
		GameManager* gameManager = GameManager::GetGameManager();
		switch (_StartMenu) {
		case StartMenu::Start:
			gameManager->GetSceneManager()->ChangeScene("MusicSelectScene");
			break;
		case StartMenu::Setting:
			gameManager->GetSceneManager()->ChangeScene("MapToolScene");
			break;
		case StartMenu::Exit:
			PostQuitMessage(0);
			break;
		default:
			break;
		}
	}
}

void FirstScene::OnEnable() {
}

void FirstScene::OnDisable() {
}

void FirstScene::Init() {
	InitTextView();
}

void FirstScene::Update() {
	_MainBackground.Update();
	_LogoImage.Update();
	_MainPanel.Update();
	KeyInput();
}

void FirstScene::Render(HDC hdc) {
	_MainBackground.Render(hdc);
	_MainPanel.Render(hdc);
	_LogoImage.Render(hdc);

	switch (_StartMenu) {
	case StartMenu::Start:
		_GuideGameStart.DrawTextView(hdc);
		break;
	case StartMenu::Setting:
		_GuideSetting.DrawTextView(hdc);
		break;
	case StartMenu::Exit:
		_GuideExit.DrawTextView(hdc);
		break;
	default:
		break;
	}
}