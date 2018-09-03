#pragma once
#include "defines.h"

class Object abstract {
public:
	Object();
	virtual ~Object();

#pragma region Variable
private:
public:
	//### Object Basic Option
	// 오브젝트 활성화 여부
	bool m_Active = true;

	// 이미지를 띄울 것인지 지정합니다.
	bool m_ShowImage = true;

	// 오브젝트의 위치가 카메라의 영향을 받도록 할 것인지 지정합니다.
	// UI를 만들 때 false 로 지정.
	bool m_UseCamPos = true;

	// 오브젝트 좌표
	int m_PosX = 0, m_PosY = 0;

	// 이미지에서 가져올 가로 세로 크기
	int m_CropWidth = 0, m_CropHeight = 0;

	// 오브젝트 영역
	RECT m_Rect = { 0, 0, 0, 0 };

	// 오브젝트 가로 세로
	int m_Width = 0, m_Height = 0;

	// BMP 이미지를 사용 중 , 특정 색상을 숨길 것인지 지정합니다
	bool m_UseTranparent = false;
	//### Object Basic Option



	//### ForUseSprite
	// 스프라이트 이미지를 사용할 것인지 지정합니다.
	bool m_UseSprite = false;

	// 스프라이트 딜레이
	int m_SpriteDelay = 0;

	// 스프라이트 시간 체크
	int m_CheckTime = 0;

	// 현재 애니메이션 인덱스
	int m_SpriteIndex = 0;

	// 스프라이트 시작 인덱스
	int m_SpriteStartIndex = 0;

	// 애니메이션 종료 인덱스
	int m_SpriteEndIndex = 0;

	// 스프라이트를 그리기 시작하는 Y좌표
	int m_DrawYIndex = 0;

	// 스프라이트 시작 인덱스
	int m_SpriteStartYIndex = 0;

	// 애니메이션 종료 인덱스
	int m_SpriteEndYIndex = 0;
	//### ForUseSprite




	//### ForDebugMode
	// 디버깅 모드를 켭니다. [하단 옵션은 디버깅 모드일 때 작동합니다.]
	bool m_DebugMode = false;

	// 테두리를 그릴 것인지 지정합니다.
	bool m_DrawRect = false;

	// 해당 오브젝트의 좌표를 로그창에 띄울 것인지 지정합니다.
	bool m_DebugPosition = false;

	// 오브젝트의 위치를 마우스 위치가 있는 곳으로 배치합니다.
	// (배치시 좌표 확인용)
	bool m_MoveMousePos = false;
	//### ForDebugMode
#pragma endregion


#pragma region Method
private:

public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render(HDC hdc) PURE;

	// 캐릭터 RECT를 posX, posY 와 동기화 시킵니다.
	void UpdateRect();


#pragma endregion
};

