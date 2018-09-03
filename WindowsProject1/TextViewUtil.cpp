#include "TextViewUtil.h"



TextViewUtil::TextViewUtil() {
	// ����ϱ� ���� ���̺귯���� �ʱ�ȭ
	GdiplusStartup(&_GdiplusToken, &_GdipluStartupInput, NULL);
}


TextViewUtil::~TextViewUtil() {
	// �ڿ�����
	GdiplusShutdown(_GdiplusToken);
}

void TextViewUtil::SetFont(LPCWSTR fontname) {
	// ����� ��Ʈ �̸��� ����
	_FontName = fontname;
}

void TextViewUtil::SetFontSize(int size) {
	// ��Ʈ ����� ����
	_FontSize = size;
}

void TextViewUtil::SetFontStyle(bool useBold, bool useItalic, bool useUnderLine, bool useStrikeout) {
	_FontStyle =
		FontStyleRegular							|	// �⺻�� ���
		(useBold)		? FontStyleBold		 : NULL |	// ���� ���
		(useItalic)		? FontStyleItalic	 : NULL |	// ����̱� ���
		(useUnderLine)	? FontStyleUnderline : NULL |	// ���� ���
		(useStrikeout)	? FontStyleStrikeout : NULL;	// ��Ҽ� ���
}

void TextViewUtil::SetFontColor(BYTE r, BYTE g, BYTE b) {
	cR = r;
	cG = g;
	cB = b;
	cA = 255;	// ���� ������
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
	// Graphics ��ü ����
	Graphics g(hdc);

	// ��Ʈ ��ü ����
	Font font(
		_FontName,	// ��Ʈ �̸�
		_FontSize,	// ��Ʈ ������
		_FontStyle,	// ��Ʈ ��Ÿ��
		UnitPixel	// ���� ����(������ 1�ȼ����� ����)
	);

	// �귯�� ��ü ����
	// ���� ������ �����ϴ� �κ�
	SolidBrush myBrush(Color(cA, cR, cG, cB));

	// c_str() : wstring -> LPCWSTR
	g.DrawString(
		_Text.c_str(),			// ����� ���ڿ�
		lstrlen(_Text.c_str()),	// ���ڿ� ����
			&font,				// ��Ʈ ��ü
			_Position,			// ����� ���ڿ��� left, top ��ǥ
			&myBrush			// ����� �귯��
		);
}
