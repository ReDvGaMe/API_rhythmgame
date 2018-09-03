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
	// 그릴 이미지
	HBITMAP			m_Image;

	// 이미지의 정보
	BITMAP			m_ImageInfo;

	// 투명 처리할 색상
	UINT			m_TransparentColor = RGB(0, 0, 0);
#pragma endregion

#pragma region Method
private:
public:
	// 이미지를 불러옴
	void			LoadImg(LPCWSTR path, int width, int height);

	// 이미지를 원본 사이즈 그대로 가져와서 그림
	void			DrawOriSize(HDC hdc, int x, int y, int areaW, int areaH, int startX, int startY);

	// 이미지를 원하는 크기만큼 그림
	void			DrawCustomSize(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH);

	// 이미지를 원하는 크기만큼 그리며, 투명 처리할 색상 한 가지를 지정
	void			DrawUseTransparent(HDC hdc, int x, int y, int w, int h, int startX, int startY, int areaW, int areaH);

	// 이미지의 정보를 반환
	BITMAP&			GetBMPInfo();

	// 해당 비트맵 이미지가 비어있는지 검사
	bool			BmpNullCheck();

	// 숨길 색상을 지정
	void			SetTransparentColor(UINT color);
#pragma endregion
};

