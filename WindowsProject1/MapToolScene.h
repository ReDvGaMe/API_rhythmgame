#pragma once
#include "Scene.h"
#include "TilePallete.h"

// 전방선언
class GameManager;
class MapData;

class MapToolScene :
	public Scene
{
public:
	MapToolScene();
	virtual ~MapToolScene();


#pragma region Variable
private:
	// 화면에 그려질 타일 가로 세로 크기
	int _DrawTileSize = 64;

	// 타일 초기화 크기(나중에 크기 초기화 기능에 사용됨)
	int _InitTileSize = 0;

	// 이미지에서 가져올 타일 가로 세로 크기
	const int CROP_TILE_SIZE = 32;

	// MapData의 가로 세로 사이즈를 참조하게될 포인터
	int* _MapWidthSize;
	int* _MapHeightSize;

	// 카메라 좌표를 받을 POINT 구조체
	POINT _CamPos = { 0, 0 };

	// 카메라를 움직일 속도
	int _CamMoveSpeed = 0;

	// 기본 속도
	int _NormalCamSpeed = 1;

	// 빠르기 이동시킬 속도
	int _FastCamSpeed = 3;

	// GameManager 참조변수
	GameManager* _GameManager;

	// MapData 참조변수
	MapData* _MapData;

	// 타일 팔레트
	TilePallete _TilePallete;

	// 타일을 그릴 때 필요한 BitmapUTIL
	BitmapUtil _BmpUtil;
public:
#pragma endregion

#pragma region Method
private:
	// 타일 아이템을 그립니다
	void DrawTileItem(HDC hdc);

	// 키 입력을 받음
	void InputKey();

	// 어떤 타일이 클릭되었는지 타일 인덱스 위치를 반환
	POINT GetClickTileIndex();
public:
	virtual void OnEnable()			override;
	virtual void OnDisable()		override;
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
#pragma endregion
};

