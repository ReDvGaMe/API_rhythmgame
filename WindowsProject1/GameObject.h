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
	// �̹��� Ÿ��, �⺻���� BMP;
	int _ImageType = BMP;

	// ������ ��ǥ
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

	// �̹����� �ҷ���
	void LoadBMPImg(LPCWSTR path, int width, int height);
	void LoadPNGImg(LPCWSTR path);

	// �ڽ� ��ü�� Update�� Render ���� �� ȣ�����־�� ��
	virtual void BaseUpdate();
	virtual void BaseRender(HDC hdc);

	// ��������Ʈ �ε����� ����
	void LoopSpriteIndex();

	// ��������Ʈ ����, �� �ε����� ����
	void SetSpriteIndex(int start, int end);

	// ��������Ʈ�� �׸��� �����ϴ� Y�ε����� ����
	void SetSpriteYIndex(int start, int end);

	// ��������Ʈ �����̸� ����
	void SetSpriteDelay(int time);

	// ������Ʈ�� ���� ���� ũ�⸦ ����
	void SetObjectWH(int w, int h);

	// �������� ������ ���� ���� ũ�� ����
	void SetCropSize(int w, int h);

	// BMP �̹����� ��� ���� ������ ����
	void SetTransparentColor(UINT color);

	// �̹��� Ÿ���� ������
	int GetImageType();

#pragma endregion
};

