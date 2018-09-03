#include "WndManager.h"
#include "PrepareWnd.h"



WndManager::WndManager(){
}


WndManager::~WndManager(){
}

void WndManager::RegisterWndClass(PrepareWnd & value) {
	// 1. WndClass 정의 : 사용할 창의 속성을 정의
	WNDCLASS wcls;

	wcls.style			= value.style;
	wcls.lpfnWndProc	= value.lpfindWndProc;
	wcls.cbClsExtra		= value.cbClsExtra;
	wcls.cbWndExtra		= value.cbWndExtra;
	wcls.hInstance		= value.hInstance;
	wcls.hIcon			= value.hIcon;
	wcls.hCursor		= value.hCursor;
	wcls.hbrBackground	= NULL;
	wcls.lpszMenuName	= NULL;
	wcls.lpszClassName	= value.lpszClassName;

	// 2. RegisterClss : 윈도우 클래스 등록
	RegisterClass(&wcls);

}

void WndManager::CreateWnd(PrepareWnd & value) {
	// 3. CreateWindow : 메모리 상에 윈도우를 생성
	_hWnd = CreateWindow(
		// 클래스 명
		value.lpszClassName,

		// 타이틀 바 텍스트
		value.lpWindowName,

		// 윈도우 스타일
		value.dwStyle,

		// 창을 화면에서 어떤 곳에 배치시킬 것인지 지정
		(SCREEN_WIDTH - WND_WIDTH) / 2,
		(SCREEN_HEIGHT - WND_HEIGHT) / 2,

		// 창의 크기 지정
		WND_WIDTH, WND_HEIGHT,

		// 윈도우 부모핸들, 메뉴핸들
		NULL, NULL,

		// 인스턴스 식별자
		value.hInstance,

		// 생성인자
		NULL
	);
}

void WndManager::ShowWnd(PrepareWnd & value) {
	// 4. ShowWinidow : 윈도우 화면 출력
	ShowWindow(_hWnd, value.nCmdShow);

	// WM_PAINT 메시지를 보내서 즉각적으로 화면을 갱신
	// WM_PAINT : 그림을 그리는 이벤트가 발생할 때 해당 메시지가 발생
	UpdateWindow(_hWnd);
}

int WndManager::Loop(HINSTANCE hInstance, int nCmdShow) {
	// 윈도우를 만들기 위해 필요한 값들을 가진 클래스
	PrepareWnd value;

	_hInstance = hInstance;
	value.hInstance = hInstance;

	RegisterWndClass(value);
	CreateWnd(value);
	ShowWnd(value);

	// 발생한 메시지를 담을 변수
	MSG msg;
	msg.message = WM_NULL; // 메시지를 NULL로 초기화

	while (msg.message != WM_QUIT) {
		// GetMessge와 PeekMessage의 차이
		// GetMessage	: 메시지가 없다면 발생할 때까지 대기
		// PeekMessage	: 메시지가 있다면 true, 없다면 false 발생
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			// PM_REMOVE : 메시지가 있다면 메시지를 확인 후 삭제하라는 뜻

			// TranslateMessage : 사용자가 메시지를 처리할 수 있도록 msg에 들어온 메시지를 번역
			TranslateMessage(&msg);

			// DispatchMessage : 메시지를 처리, 이 때 윈도우 프로시저가 호출됨
			DispatchMessage(&msg);
		}
		else {
			// HDC : Handle Device Contex
			// DC : 출력에 필요한 모든 정보를 가지고 있는 데티어 구조체
			// DC를 사용하여 우리가 직접적으로 출력은 불가능 -> 핸들을 사용
			HDC hdc = GetDC(_hWnd);

			Update();
			Render(hdc);

			// GetDC로 얻어온 DC는 반드시 ReleaseDC로 해제해야 함
			ReleaseDC(_hWnd, hdc);
		}
	}
	return (int)msg.wParam;
}

RECT WndManager::GetWndRect() {
	return _WndRc;
}

HINSTANCE WndManager::GetInstanceHandle() {
	return _hInstance;
}

HWND WndManager::GetWnd() {
	return _hWnd;
}
