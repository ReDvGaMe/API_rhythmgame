#include "GameObject.h"
#include "MouseUtil.h"
#include "GameManager.h"


GameObject::GameObject() {
}


GameObject::~GameObject() {
	// �޸� ����
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
	// �̹��� Ÿ���� BMP�� ����
	_ImageType = BMP;

	// ���� PNG�̹����� ����ߴٸ� �޷θ� ����
	if (m_Png != NULL) {
		delete m_Png;
		m_Png = NULL;
	}

	// �����Ҵ�
	m_Bmp = new BitmapUtil();

	// �̹����� �ҷ���
	m_Bmp->LoadImg(path, width, height);

	// �̹��� �ҷ����⿡ �����ߴٸ�
	if (!m_Bmp->BmpNullCheck()) {
		Log("_GameObject_", "BMP �̹��� �ҷ����� ����.");

		// ������Ʈ�� ���� ���� ũ�⸦ �ҷ��� �̹��� ũ�⸸ŭ �ʱ�ȭ
		SetObjectWH(m_Bmp->GetBMPInfo().bmWidth, m_Bmp->GetBMPInfo().bmHeight);

		// ������Ʈ ������ �ʱ�ȭ
		UpdateRect();
	}
	else
		Log("_GameObject_", "BMP �̹��� �ҷ����� ����.");
}

void GameObject::LoadPNGImg(LPCWSTR path) {
	// �̹��� Ÿ���� PNG�� ����
	_ImageType = PNG;

	// ���� BMP �̹����� ����ߴٸ� �޸� ����
	if (m_Bmp != NULL) {
		delete m_Bmp;
		m_Bmp = NULL;
	}

	// �����Ҵ�
	m_Png = new PngUtil();

	// �̹����� �ҷ���
	m_Png->LoadImg(path);

	// �̹��� �ҷ����⿡ �����ߴٸ�
	if (!m_Png->PngNullCheck()) {
		Log("_GameObject_", "PNG �̹��� �ҷ����� ����.");

		// ������Ʈ�� ���� ���� ũ�⸦ �ҷ��� �̹����� ũ�⸸ŭ �ʱ�ȭ
		SetObjectWH(m_Png->GetWidth(), m_Png->GetHeight());

		// ������Ʈ ������ �ʱ�ȭ
		UpdateRect();
	}
	else
		Log("_GameObject_", "PNG �̹��� �ҷ����� ����.");
}

void GameObject::BaseUpdate() {
	// ������Ʈ�� ��Ȱ��ȭ ���̶�� �ϴ� ������ �������� ����
	if (!m_Active)	return;

	// ��������Ʈ �̹����� ����Ѵٸ� ��������Ʈ �ε����� ������Ŵ
	if (m_UseSprite)	LoopSpriteIndex();

	// ����� �����
	if (m_DebugMode)	DebugUpdate();
}

void GameObject::BaseRender(HDC hdc) {
	// ������Ʈ�� ��Ȱ��ȭ ���̶�� �ϴ� ������ �������� ����
	if (!m_Active)	return;

	// ����� �����
	if (m_DebugMode)	DebugRender(hdc);

	// �̹��� Ÿ���� BMP�̸�, m_Bmp�� NULL�� �ƴ϶��
	if (_ImageType == BMP && m_Bmp != NULL)			BMPRender(hdc);
	// �̹��� Ÿ���� PNG�̸�, m_Png�� NULL�� �ƴ϶��
	else if (_ImageType == PNG && m_Png != NULL)	PNGRender(hdc);
}

void GameObject::LoopSpriteIndex() {
	if (GetTickCount() - m_CheckTime > m_SpriteDelay) {
		m_CheckTime = GetTickCount();

		// ��������Ʈ �ε����� ����
		m_SpriteIndex++;

		// ��������Ʈ �ε����� �� �ε������ ���� �ε����� �ʱ�ȭ
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
	// �̹����� ��� ������ üũ
	if (!m_ShowImage)	return;

	// ���� â ���� �ȿ� ���� �ʴٸ� �׸��� ����
	RECT dest;
	if (!IntersectRect(&dest, &GameManager::GetGameManager()->GetWndRect(), &m_Rect))	return;

	if (m_UseTranparent) {
		m_Bmp->DrawUseTransparent(
			hdc,

			// �׷��� ��ġ, ����
			m_Rect.left, m_Rect.top,
			m_Width, m_Height,

			// �߶�� ���� ��ǥ
			(m_UseSprite) ? m_SpriteIndex * m_CropWidth : 0,
			(m_UseSprite) ? m_DrawYIndex * m_CropHeight : 0,

			// �߶�� �� ��ǥ
			m_CropWidth, m_CropHeight);
	}

	// ���� �Ӽ��� ������� �ʰ� �ִٸ�
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
	// �̹����� ��� ������ üũ
	if (!m_ShowImage)	return;

	// ���� â ���� �ȿ� ���� �ʴٸ� �׸��� ����
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
	// ������Ʈ ������ �簢���� �׸��ٸ�
	if (m_DrawRect)
		Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void GameObject::DebugUpdate() {
	// ������Ʈ ��ǥ���� �α�â�� ���
	if (m_DebugPosition) {
		// �α� �ּ�ȭ, ������� ��ǥ�� ���� ��ǥ�� ���ٸ� �α׸� ����� ����
		if (m_DebugPosX != m_PosX || m_DebugPosY != m_PosY) {
			m_DebugPosX = m_PosX;
			m_DebugPosY = m_PosY;
			Log("_Debug_Position_XY_", m_PosX, m_PosY);
		}
	}

	// ���콺 ��ǥ�� ������Ʈ�� �����̵��� �����ߴٸ�
	if (m_MoveMousePos) {
		m_PosX = MouseUtil::GetClientMousePosition().x;
		m_PosY = MouseUtil::GetClientMousePosition().y;
		UpdateRect();
	}
}