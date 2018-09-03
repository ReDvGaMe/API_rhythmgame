#include "WindowProc.h"



WindowProc::WindowProc() {
}


WindowProc::~WindowProc() {
}

LRESULT WindowProc::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {

	case WM_CREATE:		// 창이 만들어질 때 발생하는 메시지
		Log("MSG_", "창이 생성되었습니다.");
		return 0;

	case WM_SETFOCUS:	// 창이 포커스를 얻을 때 발생
		Log("MSG_", "창 활성화!");
		windowActive = true;
		return 0;

	case WM_KILLFOCUS:	// 창이 포커스를 잃을 때 발생
		Log("MSG_", "창 비활성화!");
		windowActive = false;
		return 0;

	case WM_GETMINMAXINFO:	// 창의 크기를 조절하거나, 창의 위치를 이동시킬 때 발생
		if (FREEZE_WND_SIZE) {
			Log("MSG_", "창 크기를 고정시킵니다.");
			((MINMAXINFO *)lParam)->ptMaxTrackSize.x = WND_WIDTH;
			((MINMAXINFO *)lParam)->ptMaxTrackSize.y = WND_HEIGHT;
			((MINMAXINFO *)lParam)->ptMinTrackSize.x = WND_WIDTH;
			((MINMAXINFO *)lParam)->ptMinTrackSize.y = WND_HEIGHT;
		}
		return 0;

	case WM_DESTROY:	// 창이 꺼지는 것을 요청할 때 해당 메시지를 발생
		PostQuitMessage(0);	// 창이 꺼질 때 이 프로세스도 같이 종료되도록 함
		// exit(0); 위의 명령어로 안되면 이것을 사용
		return 0;
	}

	// 위에서 처리하지 않은 나머지 메시지들을 알아서 처리하도록 넘김
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
