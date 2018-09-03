#pragma once
#include "GameObject.h"
class TilePallete :
	public GameObject
{
public:
	TilePallete();
	virtual ~TilePallete();


#pragma region Variable
private:
	// 팔레트를 표시할 때 이동시킬 목표 좌표 x
	int _ShowPosX;

	// 팔레트를 숨길 때 이동시킬 목표 좌표 x
	int _HidePosX;

public:
	// 선택된 타일 아이템
	int m_SelectTile = 0;

	// 충돌 타일 선택
	bool m_SelectCollTile = false;

	// 팔레트를 사용하고 있는지 검사
	bool m_UsePallete = true;
#pragma endregion

#pragma region Method
private:
	// 팔레트를 열음
	void OpenPallete();

	// 아이템 선택
	void SelectItem();
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
#pragma endregion
};

