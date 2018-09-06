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

	// 메모리 릭 확인
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

	// 인자로 주어진 hdc와 픽셀 포멧이 같은 DC를 생성
	memDC = CreateCompatibleDC(hdc);

	// CreateCompatibleDC 는 출력 대상이 없는 그리기 옵션만 있는 DC
	// WndManager에서 GetDC로 얻은 DC는 출력용 DC
	// 화면 크기와 동일한 Bitmap을 만들어 GetDC로 얻은 DC에 연결
	bitmap = CreateCompatibleBitmap(hdc, wndRc.right, wndRc.bottom);

	// SelectObject : 지정해준 DC가 해당 객체를 사용할 수 있도록 연결해줌
	SelectObject(memDC, bitmap);
	FillRect(memDC, &wndRc, (HBRUSH)COLOR_BACKGROUND);

	_SceneManager->Render(memDC);

	// 원본 크기 그대로 가져와서 원하는 영역을 그림
	BitBlt(
		hdc,			// 화면을 제어할 DC
		0,				// 이미지를 출력하기 시작할 좌표 x, y
		0,				//
		wndRc.right,	// 어느 정도의 영역을 표시할 것인지 지정
		wndRc.bottom,	//
		memDC,			// 이 곳에 이미지 데이터를 저장
		0,				// 어느 지점부터 자르기 시작할 것인지 정함
		0,				//
		SRCCOPY			// 복사 옵션 : 고속복사 / NOTSRCCOPY : 이미지 색상 반전
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
