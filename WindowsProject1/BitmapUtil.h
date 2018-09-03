#pragma once
#include "defines.h"

class BitmapUtil
{
public:
	BitmapUtil();
	virtual ~BitmapUtil();

#pragma region Variable
private:
public:
	// �׸� �̹���
	HBITMAP			m_Image;

	// �̹����� ����
	BITMAP			m_ImageInfo;

	// ���� ó���� ����
	UINT			m_TransparentColor = RGB(0, 0, 0);
#pragma endregion

#pragma region Method
private:
public:
	// �̹����� �ҷ���
	void			LoadImg(LPCWSTR path, int width, int height);

	// �̹����� ���� ������ �״�� �����ͼ� �׸�
	void			DrawOriSize(HDC hdc, int x, int y, int areaW, int areaH, int startX, int startY);

	// �̹����� ���ϴ� ũ�⸸ŭ �׸�
	void			DrawCustomSize(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH);

	// �̹����� ���ϴ� ũ�⸸ŭ �׸���, ���� ó���� ���� �� ������ ����
	void			DrawUseTransparent(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH);

	// �̹����� ������ ��ȯ
	BITMAP&			GetBMPInfo();

	// �ش� ��Ʈ�� �̹����� ����ִ��� �˻�
	bool			BmpNullCheck();

	// ���� ������ ����
	void			SetTransparentColor(UINT color);
#pragma endregion
};

