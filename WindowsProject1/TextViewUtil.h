#pragma once
#include "defines.h"
class TextViewUtil
{
public:
	TextViewUtil();
	virtual ~TextViewUtil();


#pragma region Variable
private:
	// �ʱ�ȭ
	ULONG_PTR _GdiplusToken;

	// �Է� �ɼ� ����ü
	GdiplusStartupInput	_GdipluStartupInput;

	// ����� ��Ʈ ����
	LPCWSTR	_FontName = L"Arial";

	// ��Ʈ ������
	int _FontSize = 15;

	// ��Ʈ ��Ÿ��
	int _FontStyle = FontStyleRegular;

	// ��Ʈ�� ��µ� left, top ��ǥ
	// POINT : ����ü, PointF : Ŭ����
	PointF _Position;

	// ���� ����
	// cA : ����, RGB
	BYTE cA = 255, cR = 0, cG = 0, cB = 0;

	// ����� ���ڿ�
	wstring _Text = L"Hello World!";

public:
#pragma endregion

#pragma region Method
private:
public:
	// ����� ��Ʈ ����
	void SetFont(LPCWSTR fontname);

	// ��Ʈ ����� ����
	void SetFontSize(int size);

	// ��Ʈ ��Ÿ�� ����
	// ����, ����̱�, ����, ��Ҽ�
	void SetFontStyle(bool useBold, bool useItalic, bool useUnderLine, bool useStrikeout);

	// ��Ʈ ���� ���� ���Ϳ� ����
	void SetFontColor(BYTE r, BYTE g, BYTE b);
	void SetFontColor(BYTE r, BYTE g, BYTE b, BYTE a);

	// ��Ʈ ��ġ�� ����
	void SetPosition(int x, int y);

	// ����ϰ� �ִ� ���ڿ��� ���� ���Ϳ� ����
	wstring GetText();
	void SetText(wstring text);

	// ���ڿ��� ��� ���� ����
	void AddText(wstring text);

	// �ؽ�Ʈ�� �׸�
	virtual void DrawTextView(HDC hdc);
#pragma endregion
};

