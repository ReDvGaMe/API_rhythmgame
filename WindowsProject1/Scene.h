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
	// 씬이 활성화 될 때 한 번 호출
	virtual void		OnEnable()			PURE;
	// 씬이 비활성화 될 때(다른 씬으로 변경 될 때) 한 번 호출
	virtual void		OnDisable()			PURE;

	// 초기화할 구문을 작성
	// 씬을 등록 할 때 한 번 호출
	virtual void		Init()					PURE;
	virtual void		Update()				PURE;
	virtual void		Render(HDC hdc)	PURE;
#pragma endregion

};