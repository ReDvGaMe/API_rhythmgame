#include "MapToolScene.h"
#include "MapData.h"
#include "MouseUtil.h"
#include "CameraUtil.h"
#include "GameManager.h"



MapToolScene::MapToolScene() {
	Init();
}


MapToolScene::~MapToolScene() {
	OnDisable();
}

void MapToolScene::OnEnable() {
	_MapWidthSize = &MapData::GetMapData()->m_MapWidth;
	_MapHeightSize = &MapData::GetMapData()->m_MapHeight;

	// GameManager ����
	_GameManager = GameManager::GetGameManager();

	// MapData ����
	_MapData = MapData::GetMapData();
}

void MapToolScene::OnDisable() {
}

void MapToolScene::Init() {
	// _CamMoveSpeed �� �ʱ�ȭ
	_CamMoveSpeed = _NormalCamSpeed;
	_InitTileSize = _DrawTileSize;

	_BmpUtil.LoadImg(L"Resource\\TileImage\\MapTile.bmp", 0, 0);
	_BmpUtil.m_TransparentColor = RGB(255, 0, 255);
}

void MapToolScene::Update() {
	_TilePallete.Update();

	_CamPos.x = CameraUtil::GetCam()->GetPositionX();
	_CamPos.y = CameraUtil::GetCam()->GetPositionY();

	InputKey();
}

void MapToolScene::Render(HDC hdc) {
	if (_MapData->m_TileMap == NULL)	return;
	if (_MapWidthSize == NULL || _MapHeightSize == NULL) return;

	// Ÿ���� �׸�
	DrawTileItem(hdc);

	_TilePallete.Render(hdc);
}

void MapToolScene::DrawTileItem(HDC hdc) {
	for (int i = 0; i < *_MapHeightSize; i++) {
		for (int j = 0; j < *_MapWidthSize; j++) {
			int left	= _CamPos.x + (j * _DrawTileSize);
			int top		= _CamPos.y + (i * _DrawTileSize);
			int right	= left + _DrawTileSize;
			int bottom	= top + _DrawTileSize;

			RECT rc = { left, top, right, bottom };

			// ��ģ RECT ������ ������ ����
			RECT dest;

			// ȭ�鿡 �׷��� ���� �׸��带 �׸�
			if (&dest, &_GameManager->GetWndRect(), &rc) {
				// ��� �簢���� �׸�
				if (_MapData->m_TileMap[i][j] == -1) {
					Rectangle(hdc, left, top, right, bottom);
				}
				else {
					// �� Ÿ���� �׸�
					_BmpUtil.DrawUseTransparent(
						hdc,
						left, top,
						_DrawTileSize, _DrawTileSize,
						(_MapData->m_TileMap[i][j] % 4) * 32,
						(_MapData->m_TileMap[i][j] / 4) * 32,
						32, 32
					);
				}

				// �浹 Ÿ���� ������ �ϴܿ� ǥ��
				if (_MapData->m_CollMap[i][j] == 1) {
					Rectangle(
						hdc,
						left + ((float)_DrawTileSize / 1.5),
						top + ((float)_DrawTileSize / 1.5),
						right, bottom
					);
				}
			}
		}
	}
}

void MapToolScene::InputKey() {
	// A KEY
	if (GetAsyncKeyState(0x41)) {
		CameraUtil::GetCam()->AddPositionX(_CamMoveSpeed);
	}
	// D KEY
	else if (GetAsyncKeyState(0x44)) {
		CameraUtil::GetCam()->AddPositionX(-_CamMoveSpeed);
	}

	// W KEY
	if (GetAsyncKeyState(0x57)) {
		CameraUtil::GetCam()->AddPositionY(_CamMoveSpeed);
	}
	// S KEY
	else if (GetAsyncKeyState(0x53)) {
		CameraUtil::GetCam()->AddPositionY(-_CamMoveSpeed);
	}

	// ShiftŰ�� ����
	if (GetAsyncKeyState(VK_LSHIFT)) {
		if (_CamMoveSpeed != _FastCamSpeed)	_CamMoveSpeed = _FastCamSpeed;
	}
	else
		if (_CamMoveSpeed != _NormalCamSpeed)	_CamMoveSpeed = _NormalCamSpeed;

	// Space �� ���� ��ġ�� �ǵ���
	if (GetAsyncKeyState(VK_SPACE)) {
		POINT initPos = { 0, 0 };
		CameraUtil::GetCam()->SetPosition(initPos);
	}

	// Ȯ�� ���
	// Ȯ��		����1 KEY
	if (GetAsyncKeyState(0x31)) {
		if (_DrawTileSize < 100)	_DrawTileSize += 2;
	}
	// ���		���� 2 KEY
	else if (GetAsyncKeyState(0x32)) {
		if (_DrawTileSize > 20)	_DrawTileSize -= 2;
	}
	// ���� ũ��� �ǵ���	���� 3 KEY
	else if (GetAsyncKeyState(0x33)) {
		_DrawTileSize = _InitTileSize;
	}

	// ���콺 Ŭ��
	// ���콺 Ŭ���� �Ǿ��� ���
	// â�� Ȱ��ȭ���̸�, Ÿ�� ���� ���ο� ���콺 ��ġ�� ���� ���
	RECT tileArea = {
		CameraUtil::GetCam()->GetPositionX(),
		CameraUtil::GetCam()->GetPositionY(),
		CameraUtil::GetCam()->GetPositionX() + (_DrawTileSize * (*_MapWidthSize)),
		CameraUtil::GetCam()->GetPositionY() + (_DrawTileSize * (*_MapHeightSize)),
	};

	if (GetAsyncKeyState(VK_LBUTTON) && windowActive
		&& PtInRect(&tileArea, MouseUtil::GetClientMousePosition())) {
		int indexX = GetClickTileIndex().x;
		int indexY = GetClickTileIndex().y;

		// �迭 ���� �ʰ� ����ó��
		if (indexX < 0 || indexY > (*_MapWidthSize) - 1 ||
			indexY < 0 || indexX > (*_MapHeightSize) - 1)	return;

		// �ȷ�Ʈ ������̶�� Ÿ���� ���� �� ������ ����
		if (_TilePallete.m_UsePallete)	return;

		// ������ Ÿ�� ���������� ���� Ÿ���� ����
		_MapData->m_TileMap[indexY][indexX] = _TilePallete.m_SelectTile;
		// �浹 Ÿ���� �����ߵ��� �浹 Ÿ�Ϸ� ����
		_MapData->m_CollMap[indexY][indexX] = _TilePallete.m_SelectCollTile;
	}

	// �����ϱ�
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		_MapData->SaveMap();
}

POINT MapToolScene::GetClickTileIndex() {
	POINT tileIndex;

	tileIndex.x = (MouseUtil::GetClientMousePosition().x - CameraUtil::GetCam()->GetPositionX()) / _DrawTileSize;
	tileIndex.y = (MouseUtil::GetClientMousePosition().y - CameraUtil::GetCam()->GetPositionY()) / _DrawTileSize;

	return tileIndex;
}
