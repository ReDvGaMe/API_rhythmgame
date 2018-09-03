#pragma once
#include "defines.h"
class TextViewUtil
{
public:
	TextViewUtil();
	virtual ~TextViewUtil();


#pragma region Variable
private:
	// 초기화
	ULONG_PTR _GdiplusToken;

	// 입력 옵션 구조체
	GdiplusStartupInput	_GdipluStartupInput;

	// 사용할 폰트 종류
	LPCWSTR	_FontName = L"Arial";

	// 폰트 사이즈
	int _FontSize = 15;

	// 폰트 스타일
	int _FontStyle = FontStyleRegular;

	// 폰트가 출력될 left, top 좌표
	// POINT : 구조체, PointF : 클래스
	PointF _Position;

	// 글자 색상
	// cA : 투명도, RGB
	BYTE cA = 255, cR = 0, cG = 0, cB = 0;

	// 출력할 문자열
	wstring _Text = L"Hello World!";

public:
#pragma endregion

#pragma region Method
private:
public:
	// 사용할 폰트 설정
	void SetFont(LPCWSTR fontname);

	// 폰트 사이즈를 설정
	void SetFontSize(int size);

	// 폰트 스타일 설정
	// 굵게, 기울이기, 밑줄, 취소선
	void SetFontStyle(bool useBold, bool useItalic, bool useUnderLine, bool useStrikeout);

	// 폰트 색상에 대한 게터와 세터
	void SetFontColor(BYTE r, BYTE g, BYTE b);
	void SetFontColor(BYTE r, BYTE g, BYTE b, BYTE a);

	// 폰트 위치를 설정
	void SetPosition(int x, int y);

	// 출력하고 있는 문자열에 대한 게터와 세터
	wstring GetText();
	void SetText(wstring text);

	// 문자열에 어떠한 값을 더함
	void AddText(wstring text);

	// 텍스트를 그림
	virtual void DrawTextView(HDC hdc);
#pragma endregion
};

