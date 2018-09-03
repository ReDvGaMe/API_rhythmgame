#pragma once
#include "GameObject.h"
class MusicSelectEdge final :
	public GameObject
{
public:
	MusicSelectEdge();
	virtual ~MusicSelectEdge();


#pragma region Variable
private:
	int	_MusicIndex = 0;
public:
#pragma endregion

#pragma region Method
private:
public:
	virtual void Init()					override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
	void UpdateEdgePos(int MusicNo);
#pragma endregion
};

