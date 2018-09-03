#include "Button.h"
#include "MouseUtil.h"


Button::Button() {
}


Button::~Button() {
}


int Button::CheckState() {
	return _ButtonState;
}

bool Button::CheckClick() {
	// 창이 활성화 되지 않았을 경우 체크하지 않음
	if (!windowActive)	return false;

	// 클릭 확인 조건
	// 1 버튼에 마우스가 올려진 상태여야 함
	// 2 버튼을 눌렀다가 뗌
	//   ㄴ 버튼이 눌려있지 않은 상태여야 함
	//   ㄴ 이 전에 버튼이 클릭되었어야 함
	// 버튼에 마우스가 올려진 상태이며, 버튼이 눌려잇지 않은 상태에, 이 전에 클릭이 되었다면
	if (_ButtonState == 1 && !_IsPressed && _IsClicked) {
		// 후에 눌릴 것을 대비하여
		// '클릭 됨' 체크 변수를 초기화
		_IsClicked = false;

		// 클릭되었으므로
		return true;
	}

	// 아니라면 false
	return false;
}

void Button::BaseUpdate() {
	// 오브젝트가 비활성화 중이라면 하단 구문을 실행하지 않음
	if (!m_Active)	return;

	// 디버그모드라면
	if (m_DebugMode)	DebugUpdate();

	// 창이 활성화 되지 않았다면 버튼 상태를 초기화며 하단 구문을 시행시키지 않음
	if (!windowActive) {
		if (_ButtonState != 0)	_ButtonState = 0;
		if (_IsPressed)			_IsPressed = false;
		if (_IsClicked)			_IsClicked = false;
		return;
	}

	// 창이 활성화 되었다면 하단 구문을 실행
	POINT mousePos = MouseUtil::GetClientMousePosition();

	// PtInRect() : RECT 와 POINT 간의 충돌 여부를 검사
	// hover / pressed
	if (PtInRect(&m_Rect, mousePos)) {
		// 마우스 클릭이 되었다면
		// ## pressed
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (_ButtonState != 2)	_ButtonState = 2;
			if (!_IsPressed)		_IsPressed = true;
			if (!_IsClicked)		_IsClicked = true;
		}
		// 클릭 되지 않고, 버튼 위에 마우스가 올려져 있다면
		// ## hover
		else {
			if (_ButtonState != 1)	_ButtonState = 1;
			if (_IsPressed)			_IsPressed = false;
		}
	}
	// 마우스가 버튼 위에 없다면
	// normal
	else {
		// 버튼 상태 초기화
		if (_ButtonState != 0)	_ButtonState = 0;
		// 만약 버튼을 누른 상태로 버튼 범위를 벗어났다면
		if (GetAsyncKeyState(VK_LBUTTON)) {
			// 클릭되었음 상태를 초기화
			if (!_IsClicked)		_IsClicked = false;
		}
	}
}

void Button::BaseRender(HDC hdc) {
	// 오브젝트가 비활성화 중이라면 하단 구문을 실행하지 않음
	if (!m_Active)	return;
	// 디버그 모드라면
	if (m_DebugMode)	DebugRender(hdc);

	// 이미지 그리기
	if (GetImageType() == BMP && m_Bmp != NULL) {
		// 이미지가 비어있다면 그리지 않음
		if (m_Bmp->BmpNullCheck())	return;
		BMPRender(hdc);
	}
	else if (GetImageType() == PNG && m_Png != NULL) {
		// 이미지가 비어있다면 그리지 않음
		if (m_Png->PngNullCheck())	return;
		PNGRender(hdc);
	}
}

void Button::BMPRender(HDC hdc) {
	// 이미지를 띄울 것인지 체크
	if (!m_ShowImage)	return;
	// 색상 숨김 속성을 사용하고 있다면
	if (m_UseTranparent) {
		m_Bmp->DrawUseTransparent(
			hdc,						// 화면 제어권자
			m_Rect.left, m_Rect.top,	// 그려질 위치, 영역
			m_Width, m_Height,			//
			0, StartCropY(),			// 잘라올 시작 좌표
			m_CropWidth, m_CropHeight	// 잘라올 끝좌표
		);
	}
	// 색상 숨김 속성을 사용하지 않고 있다면
	else {
		m_Bmp->DrawCustomSize(
			hdc,						// 화면 제어권자
			m_Rect.left, m_Rect.top,	// 그려질 위치, 영역
			m_Width, m_Height,			//
			0, StartCropY(),			// 잘라올 시작 좌표
			m_CropWidth, m_CropHeight	// 잘라올 끝좌표
		);
	}
}

void Button::PNGRender(HDC hdc) {
	// 이미지를 띄울 것인지 체크
	if (!m_ShowImage)	return;

	m_Png->DrawImage(
		hdc,						// 화면 제어권자
		m_Rect.left, m_Rect.top,	// 그려질 위치, 영역
		m_Width, m_Height,			//
		0, StartCropY(),			// 잘라올 시작 좌표
		m_CropWidth, m_CropHeight	// 잘라올 끝좌표
	);
}

int Button::StartCropY() {
	// 이미지 자르기 시작할 Y위치
	int cropStartY;

	// normal hover pressed 속성 모두 사용
	if (m_UseHover) {
		if (GetImageType() == BMP)
			cropStartY = _ButtonState * (m_Bmp->GetBMPInfo().bmHeight / 3);
		else if (GetImageType() == PNG)
			cropStartY = _ButtonState * (m_Png->GetHeight() / 3);
	}
	// normal pressed 속성만 사용
	// (버튼 스프라이트가 normal & pressed 만 있다고 가정)
	else {
		if (GetImageType() == BMP)
			cropStartY = (_ButtonState == 2) ? (m_Bmp->GetBMPInfo().bmHeight / 2) : 0;
		else if (GetImageType() == PNG)
			cropStartY = (_ButtonState == 2) ? (m_Png->GetHeight() / 2) : 0;
	}

	return cropStartY;
}