#include "GameObject.h"
#include "MouseUtil.h"
#include "GameManager.h"


GameObject::GameObject() {
}


GameObject::~GameObject() {
	// 메모리 해제
	if (m_Bmp != NULL) {
		delete m_Bmp;
		m_Bmp = NULL;
	}
	if (m_Png != NULL) {
		delete m_Png;
		m_Png = NULL;
	}
}

void GameObject::LoadBMPImg(LPCWSTR path, int width, int height) {
	// 이미지 타입을 BMP로 설정
	_ImageType = BMP;

	// 만약 PNG이미지를 사용했다면 메로리 해제
	if (m_Png != NULL) {
		delete m_Png;
		m_Png = NULL;
	}

	// 동적할당
	m_Bmp = new BitmapUtil();

	// 이미지를 불러옴
	m_Bmp->LoadImg(path, width, height);

	// 이미지 불러오기에 성공했다면
	if (!m_Bmp->BmpNullCheck()) {
		Log("_GameObject_", "BMP 이미지 불러오기 성공.");

		// 오브젝트의 가로 세로 크기를 불러온 이미지 크기만큼 초기화
		SetObjectWH(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

		// 오브젝트 영역을 초기화
		UpdateRect();
	}
	else
		Log("_GameObject_", "BMP 이미지 불러오기 실패.");
}

void GameObject::LoadPNGImg(LPCWSTR path) {
	// 이미지 타입을 PNG로 설정
	_ImageType = PNG;

	// 만약 BMP 이미지를 사용했다면 메모리 해제
	if (m_Bmp != NULL) {
		delete m_Bmp;
		m_Bmp = NULL;
	}

	// 동적할당
	m_Png = new PngUtil();

	// 이미지를 불러옴
	m_Png->LoadImg(path);

	// 이미지 불러오기에 성공했다면
	if (!m_Png->PngNullCheck()) {
		Log("_GameObject_", "PNG 이미지 불러오기 성공.");

		// 오브젝트의 가로 세로 크기를 불러온 이미지의 크기만큼 초기화
		SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

		// 오브젝트 영역을 초기화
		UpdateRect();
	}
	else
		Log("_GameObject_", "PNG 이미지 불러오기 실패.");
}

void GameObject::BaseUpdate() {
	// 오브젝트가 비활성화 중이라면 하단 구문을 실행하지 않음
	if (!m_Active)	return;

	// 스프라이트 이미지를 사용한다면 스프라이트 인덱스를 증가시킴
	if (m_UseSprite)	LoopSpriteIndex();

	// 디버그 모드라면
	if (m_DebugMode)	DebugUpdate();
}

void GameObject::BaseRender(HDC hdc) {
	// 오브젝트가 비활성화 중이라면 하단 구문을 실행하지 않음
	if (!m_Active)	return;

	// 디버그 모드라면
	if (m_DebugMode)	DebugRender(hdc);

	// 이미지 타입이 BMP이며, m_Bmp가 NULL이 아니라면
	if (_ImageType == BMP && m_Bmp != NULL)			BMPRender(hdc);
	// 이미지 타입이 PNG이며, m_Png가 NULL이 아니라면
	else if (_ImageType == PNG && m_Png != NULL)	PNGRender(hdc);
}

void GameObject::LoopSpriteIndex() {
	if (GetTickCount() - m_CheckTime > m_SpriteDelay) {
		m_CheckTime = GetTickCount();

		// 스프라이트 인덱스를 증가
		m_SpriteIndex++;

		// 스프라이트 인덱스가 끝 인덱스라면 시작 인덱스로 초기화
		if (m_SpriteIndex > m_SpriteEndIndex) {
			m_SpriteIndex = m_SpriteStartIndex;
			m_DrawYIndex++;
		}
		if (m_DrawYIndex > m_SpriteEndYIndex)	m_DrawYIndex = m_SpriteStartYIndex;
	}
}

void GameObject::SetSpriteIndex(int start, int end) {
	m_SpriteStartIndex = start;
	m_SpriteEndIndex = end;
}

void GameObject::SetSpriteYIndex(int start, int end) {
	m_SpriteStartYIndex = start;
	m_SpriteEndYIndex = end;
}

void GameObject::SetSpriteDelay(int time) {
	m_SpriteDelay = time;
}

void GameObject::SetObjectWH(int w, int h) {
	m_Width = w;
	m_Height = h;
	UpdateRect();
}

void GameObject::SetCropSize(int w, int h) {
	m_CropWidth = w;
	m_CropHeight = h;
}

void GameObject::SetTransparentColor(UINT color) {
	if (m_Bmp == NULL)	return;

	m_Bmp->SetTransparentColor(color);
}

int GameObject::GetImageType() {
	return _ImageType;
}



void GameObject::BMPRender(HDC hdc) {
	// 이미지를 띄울 것인지 체크
	if (!m_ShowImage)	return;

	// 만약 창 영역 안에 있지 않다면 그리지 않음
	RECT dest;
	if (!IntersectRect(&dest, &GameManager::GetGameManager()->GetWndRect(), &m_Rect))	return;

	if (m_UseTranparent) {
		m_Bmp->DrawUseTransparent(
			hdc,

			// 그려질 위치, 영역
			m_Rect.left, m_Rect.top,
			m_Width, m_Height,

			// 잘라올 시작 좌표
			(m_UseSprite) ? m_SpriteIndex * m_CropWidth : 0,
			(m_UseSprite) ? m_DrawYIndex * m_CropHeight : 0,

			// 잘라올 끝 좌표
			m_CropWidth, m_CropHeight);
	}

	// 색상 속성을 사용하지 않고 있다면
	else {
		m_Bmp->DrawCustomSize(
			hdc,
			m_Rect.left, m_Rect.top,
			m_Width, m_Height,
			(m_UseSprite) ? m_SpriteIndex * m_CropWidth : 0,
			(m_UseSprite) ? m_DrawYIndex * m_CropHeight : 0,
			m_CropWidth, m_CropHeight
		);
	}
}

void GameObject::PNGRender(HDC hdc) {
	// 이미지를 띄울 것인지 체크
	if (!m_ShowImage)	return;

	// 만약 창 영역 안에 있지 않다면 그리지 않음
	RECT dest;
	if (!IntersectRect(&dest, &GameManager::GetGameManager()->GetWndRect(), &m_Rect))	return;

	m_Png->DrawImage(
		hdc,
		m_Rect.left, m_Rect.top,
		m_Width, m_Height,
		(m_UseSprite) ? m_SpriteIndex * m_CropWidth : 0,
		(m_UseSprite) ? m_DrawYIndex * m_CropHeight : 0,
		m_CropWidth, m_CropHeight
	);
}

void GameObject::DebugRender(HDC hdc) {
	// 오브젝트 영역에 사각형을 그린다면
	if (m_DrawRect)
		Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void GameObject::DebugUpdate() {
	// 오브젝트 좌표값을 로그창에 띄움
	if (m_DebugPosition) {
		// 로그 최소화, 디버깅할 좌표와 현재 좌표가 같다면 로그를 띄우지 않음
		if (m_DebugPosX != m_PosX || m_DebugPosY != m_PosY) {
			m_DebugPosX = m_PosX;
			m_DebugPosY = m_PosY;
			Log("_Debug_Position_XY_", m_PosX, m_PosY);
		}
	}

	// 마우스 좌표로 오브젝트를 움직이도록 설정했다면
	if (m_MoveMousePos) {
		m_PosX = MouseUtil::GetClientMousePosition().x;
		m_PosY = MouseUtil::GetClientMousePosition().y;
		UpdateRect();
	}
}