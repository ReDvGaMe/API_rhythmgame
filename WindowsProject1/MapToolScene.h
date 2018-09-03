#pragma once
#include "Scene.h"
#include "TilePallete.h"

// ���漱��
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
	// ȭ�鿡 �׷��� Ÿ�� ���� ���� ũ��
	int _DrawTileSize = 64;

	// Ÿ�� �ʱ�ȭ ũ��(���߿� ũ�� �ʱ�ȭ ��ɿ� ����)
	int _InitTileSize = 0;

	// �̹������� ������ Ÿ�� ���� ���� ũ��
	const int CROP_TILE_SIZE = 32;

	// MapData�� ���� ���� ����� �����ϰԵ� ������
	int* _MapWidthSize;
	int* _MapHeightSize;

	// ī�޶� ��ǥ�� ���� POINT ����ü
	POINT _CamPos = { 0, 0 };

	// ī�޶� ������ �ӵ�
	int _CamMoveSpeed = 0;

	// �⺻ �ӵ�
	int _NormalCamSpeed = 1;

	// ������ �̵���ų �ӵ�
	int _FastCamSpeed = 3;

	// GameManager ��������
	GameManager* _GameManager;

	// MapData ��������
	MapData* _MapData;

	// Ÿ�� �ȷ�Ʈ
	TilePallete _TilePallete;

	// Ÿ���� �׸� �� �ʿ��� BitmapUTIL
	BitmapUtil _BmpUtil;
public:
#pragma endregion

#pragma region Method
private:
	// Ÿ�� �������� �׸��ϴ�
	void DrawTileItem(HDC hdc);

	// Ű �Է��� ����
	void InputKey();

	// � Ÿ���� Ŭ���Ǿ����� Ÿ�� �ε��� ��ġ�� ��ȯ
	POINT GetClickTileIndex();
public:
	virtual void OnEnable()			override;
	virtual void OnDisable()		override;
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
#pragma endregion
};

