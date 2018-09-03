#pragma once
#include "defines.h"

class Object abstract {
public:
	Object();
	virtual ~Object();

#pragma region Variable
private:
public:
	//### Object Basic Option
	// ������Ʈ Ȱ��ȭ ����
	bool m_Active = true;

	// �̹����� ��� ������ �����մϴ�.
	bool m_ShowImage = true;

	// ������Ʈ�� ��ġ�� ī�޶��� ������ �޵��� �� ������ �����մϴ�.
	// UI�� ���� �� false �� ����.
	bool m_UseCamPos = true;

	// ������Ʈ ��ǥ
	int m_PosX = 0, m_PosY = 0;

	// �̹������� ������ ���� ���� ũ��
	int m_CropWidth = 0, m_CropHeight = 0;

	// ������Ʈ ����
	RECT m_Rect = { 0, 0, 0, 0 };

	// ������Ʈ ���� ����
	int m_Width = 0, m_Height = 0;

	// BMP �̹����� ��� �� , Ư�� ������ ���� ������ �����մϴ�
	bool m_UseTranparent = false;
	//### Object Basic Option



	//### ForUseSprite
	// ��������Ʈ �̹����� ����� ������ �����մϴ�.
	bool m_UseSprite = false;

	// ��������Ʈ ������
	int m_SpriteDelay = 0;

	// ��������Ʈ �ð� üũ
	int m_CheckTime = 0;

	// ���� �ִϸ��̼� �ε���
	int m_SpriteIndex = 0;

	// ��������Ʈ ���� �ε���
	int m_SpriteStartIndex = 0;

	// �ִϸ��̼� ���� �ε���
	int m_SpriteEndIndex = 0;

	// ��������Ʈ�� �׸��� �����ϴ� Y��ǥ
	int m_DrawYIndex = 0;

	// ��������Ʈ ���� �ε���
	int m_SpriteStartYIndex = 0;

	// �ִϸ��̼� ���� �ε���
	int m_SpriteEndYIndex = 0;
	//### ForUseSprite




	//### ForDebugMode
	// ����� ��带 �մϴ�. [�ϴ� �ɼ��� ����� ����� �� �۵��մϴ�.]
	bool m_DebugMode = false;

	// �׵θ��� �׸� ������ �����մϴ�.
	bool m_DrawRect = false;

	// �ش� ������Ʈ�� ��ǥ�� �α�â�� ��� ������ �����մϴ�.
	bool m_DebugPosition = false;

	// ������Ʈ�� ��ġ�� ���콺 ��ġ�� �ִ� ������ ��ġ�մϴ�.
	// (��ġ�� ��ǥ Ȯ�ο�)
	bool m_MoveMousePos = false;
	//### ForDebugMode
#pragma endregion


#pragma region Method
private:

public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render(HDC hdc) PURE;

	// ĳ���� RECT�� posX, posY �� ����ȭ ��ŵ�ϴ�.
	void UpdateRect();


#pragma endregion
};

