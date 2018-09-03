#pragma once
#include "defines.h"

class PngUtil {
public:
	PngUtil();
	virtual ~PngUtil();

#pragma region Variable
private:
	// 초기화
	ULONG_PTR _GdipToken;

	// 입력 옵션 구조체
	GdiplusStartupInput _GdiplusStartupInput;

public:

	// 이미지
	Image * m_Image;

	// 이미지를 그릴 영역
	Rect m_DrawArea;


#pragma endregion


#pragma region Method
private:

public:
	// 이미지를 불러옵니다.
	void LoadImg(LPCWSTR path);

	// 이미지를 원하는 크기만큼 그립니다.
	void DrawImage(HDC hdc, int x, int y, int w, int h,
		int startX, int startY, int areaW, int areaH);

	// 이미지가 비어있는지 체크합니다.
	bool PngNullCheck();

	// 이미지의 가로 사이즈를 가져옵니다.
	int GetWidth();

	// 이미지의 세로 사이즈를 가져옵니다.
	int GetHeight();
#pragma endregion
};

