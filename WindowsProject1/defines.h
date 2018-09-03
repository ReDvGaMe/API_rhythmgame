#pragma once
#pragma warning (disable : 4996)
#pragma warning (disable: 4819)

// �޸� ���� Ȯ���ϱ� ���� ����
#include <crtdbg.h>

// �⺻ ���̺귯�� ����
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>

// TransparentBlt�� ����ϱ� ���ؼ� �߰�
#pragma comment (lib, "Msimg32.lib")

using namespace std;

// GDI+
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
using namespace Gdiplus;

// ������ �� �ܼ�â�� ����� ������ ����
// t : ���, f : ��� ����
#define	USECONSOLE	true

#if USECONSOLE == true
// �ܼ�â�� ���
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif // USECONSOLE == true


// �α� ����
template <typename T>
__forceinline void Log(string logname, T value) {
#if USECONSOLE == true
	cout << "LogName[" << logname << "] :: " << value << "\n";
#endif // USECONSOLE == true

}

template <typename T1, typename T2>
__forceinline void Log(string logname, T1 value1, T2 value2) {
#if USECONSOLE == true
	cout << "LogName[" << logname << "] :: " << value1 << " _ " << value2 << "\n";
#endif // USECONSOLE == true

}

// ���� ����� ȭ�� ���� ���� ũ��
#define	SCREEN_WIDTH	GetSystemMetrics(SM_CXSCREEN)
#define	SCREEN_HEIGHT	GetSystemMetrics(SM_CYSCREEN)

// â ���� ���� ũ��
#define WND_WIDTH	800
#define WND_HEIGHT	1000

// â ũ�⸦ ������ų ������ ����
#define	FREEZE_WND_SIZE	true

// Ÿ��Ʋ �� �̸�
const LPCWSTR g_TitleName = L"API_FRAMEWORK";

// extern : �ܺ� ����
// �ش� �̸��� ������ ����ϰڴ� ��� ��
// �� ������ ���ǰ� �Ұ���, �ٸ� ���� ���� �� ���Ǹ� �� �� ����ؾ� ��
// ��� ������ ���� �����ϰ� ��

// ���� â�� ��Ŀ���� ������� Ȯ��
extern bool windowActive;

// �̹��� Ÿ��
#define	BMP	0
#define	PNG	1


/*
#pragma region Variable
private:
public:
#pragma endregion

#pragma region Method
private:
public:
#pragma endregion
*/