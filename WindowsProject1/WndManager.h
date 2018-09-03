#pragma once
#include "defines.h"

// 전방 선언, 클래스가 있다는 것만 알려줌
class PrepareWnd;

class WndManager abstract {
public:
	WndManager();
	virtual ~WndManager();


#pragma region Variable
private:
	// HINSTANCE
	// 현재 실행중인 프로그램에 대한 인스턴스 식별자
	// 메모리에 올려진 프로그램을 윈도에서 관리하기 위해 식별자를 부여받는데
	// 이것이 바로 HINSTANCE
	HINSTANCE	_hInstance;

	// Handle Window
	// 창의 핸들 번호
	HWND		_hWnd;

	// 해당 창의 영역
	// Left, Top, Right, Bottom 값으로 이루어져 있음
	RECT		_WndRc = { 0, 0, WND_WIDTH, WND_HEIGHT };
public:
#pragma endregion

#pragma region Method
private:
	// 2. WndClass 등록 (1번은 메소드 안에 작성)
	void		RegisterWndClass(PrepareWnd& value);

	// 3. CreateWindow : 메모리상에 윈도우를 생성
	void		CreateWnd(PrepareWnd& value);

	// 4. ShowWnd : 윈도우 화면 출력
	void		ShowWnd(PrepareWnd& value);
public:
	// 5. 메시지 루프 : 사용자로부터 메시지를 받아 처리
	int			Loop(HINSTANCE hInstance, int nCmdShow);

	// 이 곳에서 시각적인 표현을 제외한 모든 것을 해결
	virtual void Update()			PURE;
	// 이 곳에서 시각적인 표현을 하는 구문을 작성
	virtual void Render(HDC hdc)	PURE;

	// 창 영역을 가져옴
	RECT		GetWndRect();

	// _hInstance에 대한 Getter
	HINSTANCE	GetInstanceHandle();

	// _hWnd에 대한 Getter
	HWND		GetWnd();
#pragma endregion
};

