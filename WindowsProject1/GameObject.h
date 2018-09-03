#pragma once
#include "Object.h"
#include "BitmapUtil.h"
#include "PngUtil.h"

class GameObject abstract :
	public Object
{
public:
	GameObject();
	virtual ~GameObject();


#pragma region Variable
private:
	// 이미지 타입, 기본값은 BMP;
	int _ImageType = BMP;

	// 디버깅용 좌표
	int m_DebugPosX = 0, m_DebugPosY = 0;

public:
	BitmapUtil* m_Bmp = NULL;
	PngUtil* m_Png = NULL;
#pragma endregion

#pragma region Method
private:
	// BMP Draw
	void BMPRender(HDC hdc);

	// PNG Draw
	void PNGRender(HDC hdc);

public:
	// DebugDraw
	void DebugRender(HDC hdc);

	// DebugUpdate
	void DebugUpdate();

	// 이미지를 불러옴
	void LoadBMPImg(LPCWSTR path, int width, int height);
	void LoadPNGImg(LPCWSTR path);

	// 자식 객체의 Update와 Render 에서 꼭 호출해주어야 함
	virtual void BaseUpdate();
	virtual void BaseRender(HDC hdc);

	// 스프라이트 인덱스를 제어
	void LoopSpriteIndex();

	// 스프라이트 시작, 끝 인덱스를 설정
	void SetSpriteIndex(int start, int end);

	// 스프라이트를 그리기 시작하는 Y인덱스를 지정
	void SetSpriteYIndex(int start, int end);

	// 스프라이트 딜레이를 설정
	void SetSpriteDelay(int time);

	// 오브젝트의 가로 세로 크기를 설정
	void SetObjectWH(int w, int h);

	// 사진에서 가져올 가로 세로 크기 설정
	void SetCropSize(int w, int h);

	// BMP 이미지일 경우 숨길 색상을 지정
	void SetTransparentColor(UINT color);

	// 이미지 타입을 가져옴
	int GetImageType();

#pragma endregion
};

