#include "BitmapUtil.h"



BitmapUtil::BitmapUtil() {
}


BitmapUtil::~BitmapUtil() {
	// �̹����� ������� ���� ��쿡�� �޸𸮸� ����
	if (!BmpNullCheck())
		DeleteObject(m_Image);
}

void BitmapUtil::LoadImg(LPCWSTR path, int width, int height) {
	// ��Ʈ�� �̹����� �ҷ���
	m_Image = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);

	// �̹����� �ε����� ���� ���, �Ʒ� ������ �������� ����
	if(!BmpNullCheck()) {
		// HBITMAP�� ������ ����
		GetObject(m_Image, sizeof(m_ImageInfo), &m_ImageInfo);
	}
}

void BitmapUtil::DrawOriSize(HDC hdc, int x, int y, int areaW, int areaH, int startX, int startY) {
	if (BmpNullCheck())	return;

	// ���ڷ� �־��� hdc�� �ȼ� ������ ���� dc�� ����
	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	BitBlt(
		hdc,											// ȭ���� ������ DeviceContext(�����͸� ���޹��� DC)
		x, y,											// �̹����� ����� ��ǥ
		(areaW == 0) ? m_ImageInfo.bmWidth : areaW,		// ��������� ������ ǥ���� ������ ����
		(areaH == 0) ? m_ImageInfo.bmHeight : areaH,
		memDC,											// �� ���� �̹��� �����͸� ����
		startX, startY,									// ��� �������� �ڸ��� ������ ������ ����
		SRCCOPY											// ���� �ɼ�
	);

	// DC�� ��� �Ŀ��� �ݵ�� ����
	DeleteDC(memDC);
}

void BitmapUtil::DrawCustomSize(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {
	if (BmpNullCheck())	return;

	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	// SetStretchBltMode : ��Ʈ��Ī ��带 ����
	// �̹��� ��ҽ� �߻��Ǵ� �̹��� �ս��� �����ϴ� �Լ�
	// COLORONCOLOR : ��ҽ� ���� �ȼ��� �������� �ʰ� �ȼ� ������ ����
	SetStretchBltMode(hdc, COLORONCOLOR);

	// ���ϴ� �������� ����� �� ����
	StretchBlt(
		hdc,									// ȭ�� ���� DC
		x, y,									// �̹��� ��� ���� ��ǥ
		(w == 0) ? m_ImageInfo.bmWidth : w,		// �̹����� ���������� ��� ���� ũ��� ����� ���ΰ�
		(h == 0) ? m_ImageInfo.bmHeight : h,
		memDC,									// �̹��� ������ ����� DC
		startX, startY,							// �ڸ��� ������ ��ǥ
		areaW, areaH,							// �ڸ��� ������ ��ǥ���� ��� �������� �󸶳� �߶� ǥ���� ������
		SRCCOPY
	);

	DeleteDC(memDC);
}

void BitmapUtil::DrawUseTransparent(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {
	if (BmpNullCheck())	return;

	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	TransparentBlt(
		hdc,									// ȭ�� ���� DC
		x, y,									// �̹��� ��� ���� ��ǥ
		(w == 0) ? m_ImageInfo.bmWidth : w,		// �̹����� ���������� ��� ���� ũ��� ����� ���ΰ�// �̹����� ���������� ��� ���� ũ��� ����� ���ΰ�
		(h == 0) ? m_ImageInfo.bmHeight : h,
		memDC,									// �̹��� ������ ����� DC
		startX, startY,							// �ڸ��� ������ ��ǥ
		(areaW == 0) ? m_ImageInfo.bmWidth : areaW,	// �ڸ��� ������ ��ǥ���� ��� �������� �󸶳� �߶� ǥ���� ������
		(areaH == 0) ? m_ImageInfo.bmHeight : areaH,
		m_TransparentColor						// Ư�� ������ �����ϰ� ����� �� ���
	);

	DeleteDC(memDC);
}

BITMAP & BitmapUtil::GetBMPInfo() {
	return m_ImageInfo;
}

bool BitmapUtil::BmpNullCheck() {
	return (m_Image == NULL);
}

void BitmapUtil::SetTransparentColor(UINT color) {
	m_TransparentColor = color;
}
