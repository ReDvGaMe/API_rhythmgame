#include "GameManager.h"



GameManager::GameManager() {
	_SceneManager = new SceneManager();
	_SoundManager = new SoundManager();
}

GameManager::~GameManager() {
	delete _SceneManager;
	_SceneManager = NULL;
	delete _SoundManager;
	_SoundManager = NULL;

	// �޸� �� Ȯ��
	_CrtDumpMemoryLeaks();
}

void GameManager::Update() {
	_SceneManager->Update();
	_SoundManager->Update();
}

void GameManager::Render(HDC hdc) {
	HDC memDC;
	RECT wndRc;
	HBITMAP bitmap;

	if(FREEZE_WND_SIZE)
		wndRc = GetWndRect();
	else
		GetClientRect(GetWnd(), &wndRc);

	// ���ڷ� �־��� hdc�� �ȼ� ������ ���� DC�� ����
	memDC = CreateCompatibleDC(hdc);

	// CreateCompatibleDC �� ��� ����� ���� �׸��� �ɼǸ� �ִ� DC
	// WndManager���� GetDC�� ���� DC�� ��¿� DC
	// ȭ�� ũ��� ������ Bitmap�� ����� GetDC�� ���� DC�� ����
	bitmap = CreateCompatibleBitmap(hdc, wndRc.right, wndRc.bottom);

	// SelectObject : �������� DC�� �ش� ��ü�� ����� �� �ֵ��� ��������
	SelectObject(memDC, bitmap);
	FillRect(memDC, &wndRc, (HBRUSH)COLOR_BACKGROUND);

	_SceneManager->Render(memDC);

	// ���� ũ�� �״�� �����ͼ� ���ϴ� ������ �׸�
	BitBlt(
		hdc,			// ȭ���� ������ DC
		0,				// �̹����� ����ϱ� ������ ��ǥ x, y
		0,				//
		wndRc.right,	// ��� ������ ������ ǥ���� ������ ����
		wndRc.bottom,	//
		memDC,			// �� ���� �̹��� �����͸� ����
		0,				// ��� �������� �ڸ��� ������ ������ ����
		0,				//
		SRCCOPY			// ���� �ɼ� : ��Ӻ��� / NOTSRCCOPY : �̹��� ���� ����
	);

	DeleteObject(bitmap);
	DeleteDC(memDC);
}

GameManager * GameManager::GetGameManager() {
	static GameManager _GameManager;
	return &_GameManager;
}

SceneManager * GameManager::GetSceneManager() {
	return _SceneManager;
}

SoundManager * GameManager::GetSoundManager() {
	return _SoundManager;
}
