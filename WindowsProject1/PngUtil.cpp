#include "PngUtil.h"



PngUtil::PngUtil() {

	// GdiplusStartup() : 사용하기 전에 라이브러리를 초기화합니다.
	// token : 초기화시 받는 토큰, 종료할 때 전달 해야 함!
	// input : 입력 옵션 구조체
	// output:  초기화 결과를 돌려주기 위한 구조체.
	GdiplusStartup(&_GdipToken, &_GdiplusStartupInput, NULL);
}


PngUtil::~PngUtil() {

	if (PngNullCheck()) {
		delete m_Image;
		m_Image = NULL;
	}

	// 자원 해제
	GdiplusShutdown(_GdipToken);
}

void PngUtil::LoadImg(LPCWSTR path) {
	m_Image = Image::FromFile(path);
}

void PngUtil::DrawImage(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {

	if (PngNullCheck()) return;

	// Graphics 객체를 만듭니다.
	Graphics g(hdc);

	// 그릴 영역을 지정합니다.
	m_DrawArea = { x, y, w, h };

	// 이미지 보간 모드를 설정
	// 보간 : 확대시 새로운 점을 만들기 위하여 수많은 점들을 평균화 시키는 것
	// InterpolationModeNearestNeighbor : 최근접 보간법
	// - 가장 가까운 픽셀을 찾아서 해당 화소값을 사용
	// - 계산이 빠르고, 픽셀 그래픽을 사용할 경우 깔끔하지만, 확대시 해상도가 낮아짐
	g.SetInterpolationMode(InterpolationModeNearestNeighbor);

	// 이미지를 그립니다.
	g.DrawImage(
		// 그릴 이미지
		m_Image,

		// 그릴 영역
		m_DrawArea,

		// 이미지를 어느 좌표부터 자르기 시작할 것인지
		startX, startY,

		// 어느 지점까지 잘라서 표시할 것인지
		(areaW == 0) ? m_Image->GetWidth() : areaW,
		(areaH == 0) ? m_Image->GetHeight() : areaH,

		// 단위 지정 : 단위가 1픽셀입니다.
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
