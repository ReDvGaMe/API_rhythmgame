#include "WindowProc.h"



WindowProc::WindowProc() {
}


WindowProc::~WindowProc() {
}

LRESULT WindowProc::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {

	case WM_CREATE:		// â�� ������� �� �߻��ϴ� �޽���
		Log("MSG_", "â�� �����Ǿ����ϴ�.");
		return 0;

	case WM_SETFOCUS:	// â�� ��Ŀ���� ���� �� �߻�
		Log("MSG_", "â Ȱ��ȭ!");
		windowActive = true;
		return 0;

	case WM_KILLFOCUS:	// â�� ��Ŀ���� ���� �� �߻�
		Log("MSG_", "â ��Ȱ��ȭ!");
		windowActive = false;
		return 0;

	case WM_GETMINMAXINFO:	// â�� ũ�⸦ �����ϰų�, â�� ��ġ�� �̵���ų �� �߻�
		if (FREEZE_WND_SIZE) {
			Log("MSG_", "â ũ�⸦ ������ŵ�ϴ�.");
			((MINMAXINFO *)lParam)->ptMaxTrackSize.x = WND_WIDTH;
			((MINMAXINFO *)lParam)->ptMaxTrackSize.y = WND_HEIGHT;
			((MINMAXINFO *)lParam)->ptMinTrackSize.x = WND_WIDTH;
			((MINMAXINFO *)lParam)->ptMinTrackSize.y = WND_HEIGHT;
		}
		return 0;

	case WM_DESTROY:	// â�� ������ ���� ��û�� �� �ش� �޽����� �߻�
		PostQuitMessage(0);	// â�� ���� �� �� ���μ����� ���� ����ǵ��� ��
		// exit(0); ���� ��ɾ�� �ȵǸ� �̰��� ���
		return 0;
	}

	// ������ ó������ ���� ������ �޽������� �˾Ƽ� ó���ϵ��� �ѱ�
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
