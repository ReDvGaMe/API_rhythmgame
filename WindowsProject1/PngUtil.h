#pragma once
#include "defines.h"

class PngUtil {
public:
	PngUtil();
	virtual ~PngUtil();

#pragma region Variable
private:
	// �ʱ�ȭ
	ULONG_PTR _GdipToken;

	// �Է� �ɼ� ����ü
	GdiplusStartupInput _GdiplusStartupInput;

public:

	// �̹���
	Image * m_Image;

	// �̹����� �׸� ����
	Rect m_DrawArea;


#pragma endregion


#pragma region Method
private:

public:
	// �̹����� �ҷ��ɴϴ�.
	void LoadImg(LPCWSTR path);

	// �̹����� ���ϴ� ũ�⸸ŭ �׸��ϴ�.
	void DrawImage(HDC hdc, int x, int y, int w, int h,
		int startX, int startY, int areaW, int areaH);

	// �̹����� ����ִ��� üũ�մϴ�.
	bool PngNullCheck();

	// �̹����� ���� ����� �����ɴϴ�.
	int GetWidth();

	// �̹����� ���� ����� �����ɴϴ�.
	int GetHeight();
#pragma endregion
};

