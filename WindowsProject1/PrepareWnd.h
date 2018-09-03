#pragma once
#include "defines.h"


class PrepareWnd {
public:
	PrepareWnd();
	~PrepareWnd();

	UINT			style;				// �������� ��Ÿ��
	WNDPROC			lpfindWndProc;		// �������� �޽��� ó�� �Լ� ����
	int				cbClsExtra;			// ������ Ŭ���� ���� �޸�
	int				cbWndExtra;			// ������ �ν��Ͻ� ���� �޸�
	HINSTANCE		hInstance;			// ���α׷��� �ν��Ͻ� �ڵ� (Loop���� �ʱ�ȭ �� ����)
	HICON			hIcon;				// â ������
	HCURSOR			hCursor;			// Ŀ�� ����
	HBRUSH			hbrBackground;		// ���� �������� ä���� �귯�� ����
	LPCWSTR			lpszClassName;		// ����ϰ��� �ϴ� ������ Ŭ������ �̸�
	LPCWSTR			lpWindowName;		// â Ÿ��Ʋ �̸�
	DWORD			dwStyle;			// �������� ��Ÿ��
	int				nCmdShow;			// â�� ���̱� �Ӽ�

};

