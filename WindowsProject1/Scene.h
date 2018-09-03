#pragma once
#include "defines.h"

class Scene abstract {
public:
	Scene() {}
	virtual ~Scene() {}

#pragma region Variable
private:
public:
#pragma endregion

#pragma region Method
private:
public:
	// ���� Ȱ��ȭ �� �� �� �� ȣ��
	virtual void		OnEnable()			PURE;
	// ���� ��Ȱ��ȭ �� ��(�ٸ� ������ ���� �� ��) �� �� ȣ��
	virtual void		OnDisable()			PURE;

	// �ʱ�ȭ�� ������ �ۼ�
	// ���� ��� �� �� �� �� ȣ��
	virtual void		Init()					PURE;
	virtual void		Update()				PURE;
	virtual void		Render(HDC hdc)	PURE;
#pragma endregion

};