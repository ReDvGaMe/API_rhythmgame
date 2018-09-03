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
	// 글씨
	TextViewUtil _GuideGameStart, _GuideSetting, _GuideExit;

	// 로고 이미지
	LogoImage _LogoImage;

	// 배경 이미지
	MainBackground _MainBackground;

	// 메뉴 패널
	MainPanel _MainPanel;

	// 텍스트 글자 크기
	int _TextSize = 45;

	StartMenu _StartMenu = StartMenu::Start;
public:
#pragma endregion

#pragma region Method
private:
	// 텍스트 뷰 데이터 초기화용 멤버함수
	void InitTextView();

	// 키 입력
	void KeyInput();
public:
	virtual void	OnEnable()			override;
	virtual void	OnDisable()			override;
	virtual void	Init()				override;
	virtual void	Update()			override;
	virtual void	Render(HDC hdc)		override;
#pragma endregion
};

