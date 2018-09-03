#include "PngUtil.h"



PngUtil::PngUtil() {

	// GdiplusStartup() : ����ϱ� ���� ���̺귯���� �ʱ�ȭ�մϴ�.
	// token : �ʱ�ȭ�� �޴� ��ū, ������ �� ���� �ؾ� ��!
	// input : �Է� �ɼ� ����ü
	// output:  �ʱ�ȭ ����� �����ֱ� ���� ����ü.
	GdiplusStartup(&_GdipToken, &_GdiplusStartupInput, NULL);
}


PngUtil::~PngUtil() {

	if (PngNullCheck()) {
		delete m_Image;
		m_Image = NULL;
	}

	// �ڿ� ����
	GdiplusShutdown(_GdipToken);
}

void PngUtil::LoadImg(LPCWSTR path) {
	m_Image = Image::FromFile(path);
}

void PngUtil::DrawImage(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {

	if (PngNullCheck()) return;

	// Graphics ��ü�� ����ϴ�.
	Graphics g(hdc);

	// �׸� ������ �����մϴ�.
	m_DrawArea = { x, y, w, h };

	// �̹��� ���� ��带 ����
	// ���� : Ȯ��� ���ο� ���� ����� ���Ͽ� ������ ������ ���ȭ ��Ű�� ��
	// InterpolationModeNearestNeighbor : �ֱ��� ������
	// - ���� ����� �ȼ��� ã�Ƽ� �ش� ȭ�Ұ��� ���
	// - ����� ������, �ȼ� �׷����� ����� ��� ���������, Ȯ��� �ػ󵵰� ������
	g.SetInterpolationMode(InterpolationModeNearestNeighbor);

	// �̹����� �׸��ϴ�.
	g.DrawImage(
		// �׸� �̹���
		m_Image,

		// �׸� ����
		m_DrawArea,

		// �̹����� ��� ��ǥ���� �ڸ��� ������ ������
		startX, startY,

		// ��� �������� �߶� ǥ���� ������
		(areaW == 0) ? m_Image->GetWidth() : areaW,
		(areaH == 0) ? m_Image->GetHeight() : areaH,

		// ���� ���� : ������ 1�ȼ��Դϴ�.
		UnitPixel);

}

bool PngUtil::PngNullCheck() {
	return m_Image == NULL;
}

int PngUtil::GetWidth() {
	return m_Image->GetWidth();
}

int PngUtil::GetHeight() {
	return m_Image->GetHeight();
}
