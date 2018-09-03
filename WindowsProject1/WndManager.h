#pragma once
#include "defines.h"

// ���� ����, Ŭ������ �ִٴ� �͸� �˷���
class PrepareWnd;

class WndManager abstract {
public:
	WndManager();
	virtual ~WndManager();


#pragma region Variable
private:
	// HINSTANCE
	// ���� �������� ���α׷��� ���� �ν��Ͻ� �ĺ���
	// �޸𸮿� �÷��� ���α׷��� �������� �����ϱ� ���� �ĺ��ڸ� �ο��޴µ�
	// �̰��� �ٷ� HINSTANCE
	HINSTANCE	_hInstance;

	// Handle Window
	// â�� �ڵ� ��ȣ
	HWND		_hWnd;

	// �ش� â�� ����
	// Left, Top, Right, Bottom ������ �̷���� ����
	RECT		_WndRc = { 0, 0, WND_WIDTH, WND_HEIGHT };
public:
#pragma endregion

#pragma region Method
private:
	// 2. WndClass ��� (1���� �޼ҵ� �ȿ� �ۼ�)
	void		RegisterWndClass(PrepareWnd& value);

	// 3. CreateWindow : �޸𸮻� �����츦 ����
	void		CreateWnd(PrepareWnd& value);

	// 4. ShowWnd : ������ ȭ�� ���
	void		ShowWnd(PrepareWnd& value);
public:
	// 5. �޽��� ���� : ����ڷκ��� �޽����� �޾� ó��
	int			Loop(HINSTANCE hInstance, int nCmdShow);

	// �� ������ �ð����� ǥ���� ������ ��� ���� �ذ�
	virtual void Update()			PURE;
	// �� ������ �ð����� ǥ���� �ϴ� ������ �ۼ�
	virtual void Render(HDC hdc)	PURE;

	// â ������ ������
	RECT		GetWndRect();

	// _hInstance�� ���� Getter
	HINSTANCE	GetInstanceHandle();

	// _hWnd�� ���� Getter
	HWND		GetWnd();
#pragma endregion
};

