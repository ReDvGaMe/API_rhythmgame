#pragma once
#include "GameObject.h"
class MusicSelectPanel final :
	public GameObject
{
public:
	MusicSelectPanel();
	virtual ~MusicSelectPanel();


#pragma region Variable
private:
public:
	int m_PosX[4] = { 0, 0, 0, 0 };
	int m_PosY[4] = { 0, 0, 0, 0 };
	RECT m_Rect[4][4];
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
	void Render(HDC hdc, int i, int j);
	void UpdateRect(int i, int j);
#pragma endregion
};

