#pragma once
#pragma warning (disable : 4996)
#pragma warning (disable: 4819)

// 메모리 릭을 확인하기 위해 포함
#include <crtdbg.h>

// 기본 라이브러리 포함
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>

// TransparentBlt를 사용하기 위해서 추가
#pragma comment (lib, "Msimg32.lib")

using namespace std;

// GDI+
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
using namespace Gdiplus;

// 실행할 때 콘솔창을 사용할 것인지 지정
// t : 사용, f : 사용 안함
#define	USECONSOLE	true

#if USECONSOLE == true
// 콘솔창을 띄움
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif // USECONSOLE == true


// 로그 띄우기
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

// 현재 모니터 화면 가로 세로 크기
#define	SCREEN_WIDTH	GetSystemMetrics(SM_CXSCREEN)
#define	SCREEN_HEIGHT	GetSystemMetrics(SM_CYSCREEN)

// 창 가로 세로 크기
#define WND_WIDTH	800
#define WND_HEIGHT	1000

// 창 크기를 고정시킬 것인지 지정
#define	FREEZE_WND_SIZE	true

// 타이틀 바 이름
const LPCWSTR g_TitleName = L"API_FRAMEWORK";

// extern : 외부 변수
// 해당 이름의 변수를 사용하겠다 라는 뜻
// 이 곳에는 정의가 불가능, 다른 곳에 선언 및 정의를 한 후 사용해야 함
// 모든 곳에서 값을 공유하게 됨

// 현재 창이 포커스를 얻었는지 확인
extern bool windowActive;

// 이미지 타입
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