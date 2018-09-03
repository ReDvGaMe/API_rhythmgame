#pragma once
#include "Scene.h"
#include "TextViewUtil.h"
#include "MainButton.h"
#include "MainCheckButton.h"
#include "LogoImage.h"
#include "MainBackground.h"
#include "MainPanel.h"

enum class StartMenu {
	Start,
	Setting,
	Exit
};

class FirstScene final :
	public Scene {
public:
	FirstScene();
	virtual ~FirstScene();


#pragma region Variable
private:
	// �۾�
	TextViewUtil _GuideGameStart, _GuideSetting, _GuideExit;

	// �ΰ� �̹���
	LogoImage _LogoImage;

	// ��� �̹���
	MainBackground _MainBackground;

	// �޴� �г�
	MainPanel _MainPanel;

	// �ؽ�Ʈ ���� ũ��
	int _TextSize = 45;

	StartMenu _StartMenu = StartMenu::Start;
public:
#pragma endregion

#pragma region Method
private:
	// �ؽ�Ʈ �� ������ �ʱ�ȭ�� ����Լ�
	void InitTextView();

	// Ű �Է�
	void KeyInput();
public:
	virtual void	OnEnable()			override;
	virtual void	OnDisable()			override;
	virtual void	Init()				override;
	virtual void	Update()			override;
	virtual void	Render(HDC hdc)		override;
#pragma endregion
};

