#pragma once
#include "Scene.h"
#include "TextViewUtil.h"
#include "MusicSelectBackGround.h"
#include "MusicSelectPanel.h"
#include "MusicSelectEdge.h"
#include "MusicInfoPanel.h"
#include "PauseMenu.h"
#include "MusicInfo.h"

enum class m_PauseMenu {
	Resume,
	Setting,
	MainMenu
};

class MusicSelectScene final :
	public Scene
{
public:
	MusicSelectScene();
	virtual ~MusicSelectScene();


#pragma region Variable
private:
	// 배경 이미지
	MusicSelectBackGround	_MusicSelectBackgournd;

	// 음악 앨범 자켓 백그라운드
	MusicSelectPanel		_MusicSelectPanel;

	// 음악 선택 테두리
	MusicSelectEdge			_MusicSelectEdge;

	// 음악 선택 테두리 위치
	int _MusicSelectNum = 0;
	// 음악 선택 페이지
	int _MusicSelectPage = 0;

	// 일시정지 메뉴
	m_PauseMenu m_PauseMenu = m_PauseMenu::Resume;
	PauseMenu				_PauseMenu;
	bool _IsPause = false;

	// 음악 정보
	MusicInfo					_MusicInfo[16];
	// 음악 정보 패널
	MusicInfoPanel			_MusicInfoPanel;
public:
#pragma endregion

#pragma region Method
private:
	void KeyInput();
public:
	virtual void	OnEnable()			override;
	virtual void	OnDisable()			override;
	virtual void	Init()					override;
	virtual void	Update()				override;
	virtual void	Render(HDC hdc)	override;
#pragma endregion
};