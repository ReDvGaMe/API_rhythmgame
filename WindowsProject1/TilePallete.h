#pragma once
#include "GameObject.h"
class TilePallete :
	public GameObject
{
public:
	TilePallete();
	virtual ~TilePallete();


#pragma region Variable
private:
	// �ȷ�Ʈ�� ǥ���� �� �̵���ų ��ǥ ��ǥ x
	int _ShowPosX;

	// �ȷ�Ʈ�� ���� �� �̵���ų ��ǥ ��ǥ x
	int _HidePosX;

public:
	// ���õ� Ÿ�� ������
	int m_SelectTile = 0;

	// �浹 Ÿ�� ����
	bool m_SelectCollTile = false;

	// �ȷ�Ʈ�� ����ϰ� �ִ��� �˻�
	bool m_UsePallete = true;
#pragma endregion

#pragma region Method
private:
	// �ȷ�Ʈ�� ����
	void OpenPallete();

	// ������ ����
	void SelectItem();
public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Render(HDC hdc)	override;
#pragma endregion
};

