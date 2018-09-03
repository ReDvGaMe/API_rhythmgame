#include "TextViewUtil.h"



TextViewUtil::TextViewUtil() {
	// 사용하기 전에 라이브러리를 초기화
	GdiplusStartup(&_GdiplusToken, &_GdipluStartupInput, NULL);
}


TextViewUtil::~TextViewUtil() {
	// 자원해제
	GdiplusShutdown(_GdiplusToken);
}

void TextViewUtil::SetFont(LPCWSTR fontname) {
	// 사용할 폰트 이름을 지정
	_FontName = fontname;
}

void TextViewUtil::SetFontSize(int size) {
	// 폰트 사이즈를 설정
	_FontSize = size;
}

void TextViewUtil::SetFontStyle(bool useBold, bool useItalic, bool useUnderLine, bool useStrikeout) {
	_FontStyle =
		FontStyleRegular							|	// 기본값 사용
		(useBold)		? FontStyleBold		 : NULL |	// 굵게 사용
		(useItalic)		? FontStyleItalic	 : NULL |	// 기울이기 사용
		(useUnderLine)	? FontStyleUnderline : NULL |	// 밑줄 사용
		(useStrikeout)	? FontStyleStrikeout : NULL;	// 취소선 사용
}

void TextViewUtil::SetFontColor(BYTE r, BYTE g, BYTE b) {
	cR = r;
	cG = g;
	cB = b;
	cA = 255;	// 완전 불투명
}

void TextViewUtil::SetFontColor(BYTE r, BYTE g, BYTE b, BYTE a) {
	cR = r;
	cG = g;
	cB = b;
	cA = a;
}

void TextViewUtil::SetPosition(int x, int y) {
	_Position.X = x;
	_Position.Y = y;
}

wstring TextViewUtil::GetText() {
	return _Text;
}

void TextViewUtil::SetText(wstring text) {
	_Text = text;
}

void TextViewUtil::AddText(wstring text) {
	_Text.append(text);
}

void TextViewUtil::DrawTextView(HDC hdc) {
	// Graphics 객체 생성
	Graphics g(hdc);

	// 폰트 객체 생성
	Font font(
		_FontName,	// 폰트 이름
		_FontSize,	// 폰트 사이즈
		_FontStyle,	// 폰트 스타일
		UnitPixel	// 단위 지정(단위가 1픽셀임을 지정)
	);

	// 브러쉬 객체 생성
	// 글자 색상을 지정하는 부분
	SolidBrush myBrush(Color(cA, cR, cG, cB));

	// c_str() : wstring -> LPCWSTR
	g.DrawString(
		_Text.c_str(),			// 출력할 문자열
		lstrlen(_Text.c_str()),	// 문자열 길이
			&font,				// 폰트 객체
			_Position,			// 출력할 문자열의 left, top 좌표
			&myBrush			// 사용할 브러쉬
		);
}
