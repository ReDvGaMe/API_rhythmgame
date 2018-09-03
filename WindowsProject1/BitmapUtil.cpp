#include "BitmapUtil.h"



BitmapUtil::BitmapUtil() {
}


BitmapUtil::~BitmapUtil() {
	// 이미지가 비어있지 않을 경우에만 메모리를 해제
	if (!BmpNullCheck())
		DeleteObject(m_Image);
}

void BitmapUtil::LoadImg(LPCWSTR path, int width, int height) {
	// 비트맵 이미지를 불러옴
	m_Image = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);

	// 이미지를 로드하지 못한 경우, 아래 구문을 실행하지 않음
	if(!BmpNullCheck()) {
		// HBITMAP의 정보를 구함
		GetObject(m_Image, sizeof(m_ImageInfo), &m_ImageInfo);
	}
}

void BitmapUtil::DrawOriSize(HDC hdc, int x, int y, int areaW, int areaH, int startX, int startY) {
	if (BmpNullCheck())	return;

	// 인자로 주어진 hdc와 픽셀 포멧이 같은 dc를 생성
	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	BitBlt(
		hdc,											// 화면을 제어할 DeviceContext(데이터를 전달받을 DC)
		x, y,											// 이미지를 출력할 좌표
		(areaW == 0) ? m_ImageInfo.bmWidth : areaW,		// 어느정도의 영역을 표시할 것인지 지정
		(areaH == 0) ? m_ImageInfo.bmHeight : areaH,
		memDC,											// 이 곳에 이미지 데이터를 저장
		startX, startY,									// 어느 지점부터 자르기 시작할 것인지 지정
		SRCCOPY											// 복사 옵션
	);

	// DC를 사용 후에는 반드시 해제
	DeleteDC(memDC);
}

void BitmapUtil::DrawCustomSize(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {
	if (BmpNullCheck())	return;

	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	// SetStretchBltMode : 스트레칭 모드를 설정
	// 이미지 축소시 발생되는 이미지 손실을 보정하는 함수
	// COLORONCOLOR : 축소시 남는 픽셀을 보전하지 않고 픽셀 라인을 제거
	SetStretchBltMode(hdc, COLORONCOLOR);

	// 원하는 사이즈대로 출력할 수 있음
	StretchBlt(
		hdc,									// 화면 제어 DC
		x, y,									// 이미지 출력 시작 좌표
		(w == 0) ? m_ImageInfo.bmWidth : w,		// 이미지를 최종적으로 어느 정도 크기로 출력할 것인가
		(h == 0) ? m_ImageInfo.bmHeight : h,
		memDC,									// 이미지 데이터 저장용 DC
		startX, startY,							// 자르기 시작할 좌표
		areaW, areaH,							// 자르기 시작할 좌표부터 어느 지점까지 얼마나 잘라서 표시할 것인지
		SRCCOPY
	);

	DeleteDC(memDC);
}

void BitmapUtil::DrawUseTransparent(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH) {
	if (BmpNullCheck())	return;

	HDC memDC = CreateCompatibleDC(hdc);

	SelectObject(memDC, m_Image);

	TransparentBlt(
		hdc,									// 화면 제어 DC
		x, y,									// 이미지 출력 시작 좌표
		(w == 0) ? m_ImageInfo.bmWidth : w,		// 이미지를 최종적으로 어느 정도 크기로 출력할 것인가// 이미지를 최종적으로 어느 정도 크기로 출력할 것인가
		(h == 0) ? m_ImageInfo.bmHeight : h,
		memDC,									// 이미지 데이터 저장용 DC
		startX, startY,							// 자르기 시작할 좌표
		(areaW == 0) ? m_ImageInfo.bmWidth : areaW,	// 자르기 시작할 좌표부터 어느 지점까지 얼마나 잘라서 표시할 것인지
		(areaH == 0) ? m_ImageInfo.bmHeight : areaH,
		m_TransparentColor						// 특정 색상을 제외하고 출력할 때 사용
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
