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

	// GameManager 참조
	_GameManager = GameManager::GetGameManager();

	// MapData 참조
	_MapData = MapData::GetMapData();
}

void MapToolScene::OnDisable() {
}

void MapToolScene::Init() {
	// _CamMoveSpeed 를 초기화
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

	// 타일을 그림
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

			// 겹친 RECT 영역을 저장할 변수
			RECT dest;

			// 화면에 그려질 때만 그리드를 그림
			if (&dest, &_GameManager->GetWndRect(), &rc) {
				// 흰색 사각형을 그림
				if (_MapData->m_TileMap[i][j] == -1) {
					Rectangle(hdc, left, top, right, bottom);
				}
				else {
					// 맵 타일을 그림
					_BmpUtil.DrawUseTransparent(
						hdc,
						left, top,
						_DrawTileSize, _DrawTileSize,
						(_MapData->m_TileMap[i][j] % 4) * 32,
						(_MapData->m_TileMap[i][j] / 4) * 32,
						32, 32
					);
				}

				// 충돌 타일을 오른쪽 하단에 표시
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

	// Shift키로 가속
	if (GetAsyncKeyState(VK_LSHIFT)) {
		if (_CamMoveSpeed != _FastCamSpeed)	_CamMoveSpeed = _FastCamSpeed;
	}
	else
		if (_CamMoveSpeed != _NormalCamSpeed)	_CamMoveSpeed = _NormalCamSpeed;

	// Space 로 원래 위치로 되돌림
	if (GetAsyncKeyState(VK_SPACE)) {
		POINT initPos = { 0, 0 };
		CameraUtil::GetCam()->SetPosition(initPos);
	}

	// 확대 축소
	// 확대		숫자1 KEY
	if (GetAsyncKeyState(0x31)) {
		if (_DrawTileSize < 100)	_DrawTileSize += 2;
	}
	// 축소		숫자 2 KEY
	else if (GetAsyncKeyState(0x32)) {
		if (_DrawTileSize > 20)	_DrawTileSize -= 2;
	}
	// 원래 크기로 되돌림	숫자 3 KEY
	else if (GetAsyncKeyState(0x33)) {
		_DrawTileSize = _InitTileSize;
	}

	// 마우스 클릭
	// 마우스 클릭이 되었을 경우
	// 창이 활성화중이며, 타일 영역 내부에 마우스 위치가 있을 경우
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

		// 배열 범위 초과 예외처리
		if (indexX < 0 || indexY > (*_MapWidthSize) - 1 ||
			indexY < 0 || indexX > (*_MapHeightSize) - 1)	return;

		// 팔레트 사용중이라면 타일을 찍을 수 없도록 설정
		if (_TilePallete.m_UsePallete)	return;

		// 선택한 타일 아이템으로 현재 타일을 설정
		_MapData->m_TileMap[indexY][indexX] = _TilePallete.m_SelectTile;
		// 충돌 타일을 선택했따면 충돌 타일로 설정
		_MapData->m_CollMap[indexY][indexX] = _TilePallete.m_SelectCollTile;
	}

	// 저장하기
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		_MapData->SaveMap();
}

POINT MapToolScene::GetClickTileIndex() {
	POINT tileIndex;

	tileIndex.x = (MouseUtil::GetClientMousePosition().x - CameraUtil::GetCam()->GetPositionX()) / _DrawTileSize;
	tileIndex.y = (MouseUtil::GetClientMousePosition().y - CameraUtil::GetCam()->GetPositionY()) / _DrawTileSize;

	return tileIndex;
}
