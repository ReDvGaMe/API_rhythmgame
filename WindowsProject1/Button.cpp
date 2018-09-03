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
	// â�� Ȱ��ȭ ���� �ʾ��� ��� üũ���� ����
	if (!windowActive)	return false;

	// Ŭ�� Ȯ�� ����
	// 1 ��ư�� ���콺�� �÷��� ���¿��� ��
	// 2 ��ư�� �����ٰ� ��
	//   �� ��ư�� �������� ���� ���¿��� ��
	//   �� �� ���� ��ư�� Ŭ���Ǿ���� ��
	// ��ư�� ���콺�� �÷��� �����̸�, ��ư�� �������� ���� ���¿�, �� ���� Ŭ���� �Ǿ��ٸ�
	if (_ButtonState == 1 && !_IsPressed && _IsClicked) {
		// �Ŀ� ���� ���� ����Ͽ�
		// 'Ŭ�� ��' üũ ������ �ʱ�ȭ
		_IsClicked = false;

		// Ŭ���Ǿ����Ƿ�
		return true;
	}

	// �ƴ϶�� false
	return false;
}

void Button::BaseUpdate() {
	// ������Ʈ�� ��Ȱ��ȭ ���̶�� �ϴ� ������ �������� ����
	if (!m_Active)	return;

	// ����׸����
	if (m_DebugMode)	DebugUpdate();

	// â�� Ȱ��ȭ ���� �ʾҴٸ� ��ư ���¸� �ʱ�ȭ�� �ϴ� ������ �����Ű�� ����
	if (!windowActive) {
		if (_ButtonState != 0)	_ButtonState = 0;
		if (_IsPressed)			_IsPressed = false;
		if (_IsClicked)			_IsClicked = false;
		return;
	}

	// â�� Ȱ��ȭ �Ǿ��ٸ� �ϴ� ������ ����
	POINT mousePos = MouseUtil::GetClientMousePosition();

	// PtInRect() : RECT �� POINT ���� �浹 ���θ� �˻�
	// hover / pressed
	if (PtInRect(&m_Rect, mousePos)) {
		// ���콺 Ŭ���� �Ǿ��ٸ�
		// ## pressed
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (_ButtonState != 2)	_ButtonState = 2;
			if (!_IsPressed)		_IsPressed = true;
			if (!_IsClicked)		_IsClicked = true;
		}
		// Ŭ�� ���� �ʰ�, ��ư ���� ���콺�� �÷��� �ִٸ�
		// ## hover
		else {
			if (_ButtonState != 1)	_ButtonState = 1;
			if (_IsPressed)			_IsPressed = false;
		}
	}
	// ���콺�� ��ư ���� ���ٸ�
	// normal
	else {
		// ��ư ���� �ʱ�ȭ
		if (_ButtonState != 0)	_ButtonState = 0;
		// ���� ��ư�� ���� ���·� ��ư ������ ����ٸ�
		if (GetAsyncKeyState(VK_LBUTTON)) {
			// Ŭ���Ǿ��� ���¸� �ʱ�ȭ
			if (!_IsClicked)		_IsClicked = false;
		}
	}
}

void Button::BaseRender(HDC hdc) {
	// ������Ʈ�� ��Ȱ��ȭ ���̶�� �ϴ� ������ �������� ����
	if (!m_Active)	return;
	// ����� �����
	if (m_DebugMode)	DebugRender(hdc);

	// �̹��� �׸���
	if (GetImageType() == BMP && m_Bmp != NULL) {
		// �̹����� ����ִٸ� �׸��� ����
		if (m_Bmp->BmpNullCheck())	return;
		BMPRender(hdc);
	}
	else if (GetImageType() == PNG && m_Png != NULL) {
		// �̹����� ����ִٸ� �׸��� ����
		if (m_Png->PngNullCheck())	return;
		PNGRender(hdc);
	}
}

void Button::BMPRender(HDC hdc) {
	// �̹����� ��� ������ üũ
	if (!m_ShowImage)	return;
	// ���� ���� �Ӽ��� ����ϰ� �ִٸ�
	if (m_UseTranparent) {
		m_Bmp->DrawUseTransparent(
			hdc,						// ȭ�� �������
			m_Rect.left, m_Rect.top,	// �׷��� ��ġ, ����
			m_Width, m_Height,			//
			0, StartCropY(),			// �߶�� ���� ��ǥ
			m_CropWidth, m_CropHeight	// �߶�� ����ǥ
		);
	}
	// ���� ���� �Ӽ��� ������� �ʰ� �ִٸ�
	else {
		m_Bmp->DrawCustomSize(
			hdc,						// ȭ�� �������
			m_Rect.left, m_Rect.top,	// �׷��� ��ġ, ����
			m_Width, m_Height,			//
			0, StartCropY(),			// �߶�� ���� ��ǥ
			m_CropWidth, m_CropHeight	// �߶�� ����ǥ
		);
	}
}

void Button::PNGRender(HDC hdc) {
	// �̹����� ��� ������ üũ
	if (!m_ShowImage)	return;

	m_Png->DrawImage(
		hdc,						// ȭ�� �������
		m_Rect.left, m_Rect.top,	// �׷��� ��ġ, ����
		m_Width, m_Height,			//
		0, StartCropY(),			// �߶�� ���� ��ǥ
		m_CropWidth, m_CropHeight	// �߶�� ����ǥ
	);
}

int Button::StartCropY() {
	// �̹��� �ڸ��� ������ Y��ġ
	int cropStartY;

	// normal hover pressed �Ӽ� ��� ���
	if (m_UseHover) {
		if (GetImageType() == BMP)
			cropStartY = _ButtonState * (m_Bmp->GetBMPInfo().bmHeight / 3);
		else if (GetImageType() == PNG)
			cropStartY = _ButtonState * (m_Png->GetHeight() / 3);
	}
	// normal pressed �Ӽ��� ���
	// (��ư ��������Ʈ�� normal & pressed �� �ִٰ� ����)
	else {
		if (GetImageType() == BMP)
			cropStartY = (_ButtonState == 2) ? (m_Bmp->GetBMPInfo().bmHeight / 2) : 0;
		else if (GetImageType() == PNG)
			cropStartY = (_ButtonState == 2) ? (m_Png->GetHeight() / 2) : 0;
	}

	return cropStartY;
}