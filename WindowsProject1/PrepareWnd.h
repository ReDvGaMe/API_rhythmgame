#pragma once
#include "defines.h"


class PrepareWnd {
public:
	PrepareWnd();
	~PrepareWnd();

	UINT			style;				// 윈도우의 스타일
	WNDPROC			lpfindWndProc;		// 윈도우의 메시지 처리 함수 지정
	int				cbClsExtra;			// 윈도우 클래스 여분 메모리
	int				cbWndExtra;			// 윈도우 인스턴스 여분 메모리
	HINSTANCE		hInstance;			// 프로그램의 인스턴스 핸들 (Loop에서 초기화 할 것임)
	HICON			hIcon;				// 창 아이콘
	HCURSOR			hCursor;			// 커서 지정
	HBRUSH			hbrBackground;		// 현재 배경색상을 채색할 브러쉬 지정
	LPCWSTR			lpszClassName;		// 등록하고자 하는 윈도우 클래스의 이름
	LPCWSTR			lpWindowName;		// 창 타이틀 이름
	DWORD			dwStyle;			// 윈도우의 스타일
	int				nCmdShow;			// 창의 보이기 속성

};

