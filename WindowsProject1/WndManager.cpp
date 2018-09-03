#include "WndManager.h"
#include "PrepareWnd.h"



WndManager::WndManager(){
}


WndManager::~WndManager(){
}

void WndManager::RegisterWndClass(PrepareWnd & value) {
	// 1. WndClass ���� : ����� â�� �Ӽ��� ����
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

	// 2. RegisterClss : ������ Ŭ���� ���
	RegisterClass(&wcls);

}

void WndManager::CreateWnd(PrepareWnd & value) {
	// 3. CreateWindow : �޸� �� �����츦 ����
	_hWnd = CreateWindow(
		// Ŭ���� ��
		value.lpszClassName,

		// Ÿ��Ʋ �� �ؽ�Ʈ
		value.lpWindowName,

		// ������ ��Ÿ��
		value.dwStyle,

		// â�� ȭ�鿡�� � ���� ��ġ��ų ������ ����
		(SCREEN_WIDTH - WND_WIDTH) / 2,
		(SCREEN_HEIGHT - WND_HEIGHT) / 2,

		// â�� ũ�� ����
		WND_WIDTH, WND_HEIGHT,

		// ������ �θ��ڵ�, �޴��ڵ�
		NULL, NULL,

		// �ν��Ͻ� �ĺ���
		value.hInstance,

		// ��������
		NULL
	);
}

void WndManager::ShowWnd(PrepareWnd & value) {
	// 4. ShowWinidow : ������ ȭ�� ���
	ShowWindow(_hWnd, value.nCmdShow);

	// WM_PAINT �޽����� ������ �ﰢ������ ȭ���� ����
	// WM_PAINT : �׸��� �׸��� �̺�Ʈ�� �߻��� �� �ش� �޽����� �߻�
	UpdateWindow(_hWnd);
}

int WndManager::Loop(HINSTANCE hInstance, int nCmdShow) {
	// �����츦 ����� ���� �ʿ��� ������ ���� Ŭ����
	PrepareWnd value;

	_hInstance = hInstance;
	value.hInstance = hInstance;

	RegisterWndClass(value);
	CreateWnd(value);
	ShowWnd(value);

	// �߻��� �޽����� ���� ����
	MSG msg;
	msg.message = WM_NULL; // �޽����� NULL�� �ʱ�ȭ

	while (msg.message != WM_QUIT) {
		// GetMessge�� PeekMessage�� ����
		// GetMessage	: �޽����� ���ٸ� �߻��� ������ ���
		// PeekMessage	: �޽����� �ִٸ� true, ���ٸ� false �߻�
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			// PM_REMOVE : �޽����� �ִٸ� �޽����� Ȯ�� �� �����϶�� ��

			// TranslateMessage : ����ڰ� �޽����� ó���� �� �ֵ��� msg�� ���� �޽����� ����
			TranslateMessage(&msg);

			// DispatchMessage : �޽����� ó��, �� �� ������ ���ν����� ȣ���
			DispatchMessage(&msg);
		}
		else {
			// HDC : Handle Device Contex
			// DC : ��¿� �ʿ��� ��� ������ ������ �ִ� ��Ƽ�� ����ü
			// DC�� ����Ͽ� �츮�� ���������� ����� �Ұ��� -> �ڵ��� ���
			HDC hdc = GetDC(_hWnd);

			Update();
			Render(hdc);

			// GetDC�� ���� DC�� �ݵ�� ReleaseDC�� �����ؾ� ��
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
