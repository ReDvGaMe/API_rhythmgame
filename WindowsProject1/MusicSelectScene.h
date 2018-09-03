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
	// ��� �̹���
	MusicSelectBackGround	_MusicSelectBackgournd;

	// ���� �ٹ� ���� ��׶���
	MusicSelectPanel		_MusicSelectPanel;

	// ���� ���� �׵θ�
	MusicSelectEdge			_MusicSelectEdge;

	// ���� ���� �׵θ� ��ġ
	int _MusicSelectNum = 0;
	// ���� ���� ������
	int _MusicSelectPage = 0;

	// �Ͻ����� �޴�
	m_PauseMenu m_PauseMenu = m_PauseMenu::Resume;
	PauseMenu				_PauseMenu;
	bool _IsPause = false;

	// ���� ����
	MusicInfo					_MusicInfo[16];
	// ���� ���� �г�
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