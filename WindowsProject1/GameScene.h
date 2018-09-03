#pragma once
#include "Scene.h"
#include "MouseUtil.h"
#include "MusicInfoPanel.h"
#include "PauseMenu.h"
#include "MusicSelectScene.h"
#include "MarkerManager.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();


#pragma region Variable
private:
	// ���� ���� �г�
	MusicInfoPanel			_MusicInfoPanel;

	// �Ͻ����� �޴�
	m_PauseMenu ingame_PauseMenu = m_PauseMenu::Resume;
	PauseMenu				_PauseMenu;
	bool _IsPause = false;

	// ��Ŀ
	MarkerManager _MarkerManager;

	POINT _MousePos;
public:
#pragma endregion

#pragma region Method
private:
	void KeyInput();
public:
	virtual void	OnEnable()			override;
	virtual void	OnDisable()			override;
	virtual void	Init()				override;
	virtual void	Update()			override;
	virtual void	Render(HDC hdc)		override;
#pragma endregion
};

