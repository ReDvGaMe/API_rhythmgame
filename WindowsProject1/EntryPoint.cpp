#include "defines.h"
#include "GameManager.h"

// WinApi = �̺�Ʈ ������ ���α׷�
// WinApi���� Window�� ����� ����
// 1. WndClass ����	: ����� â�� �Ӽ��� ����
// 2. RegisterClass	: ������ Ŭ���� ���
// 3. CreateWindow	: �޸𸮻� �����츦 ����
// 4. ShowWindow	: ������ ȭ�� ���
// 5. �޽��� ����	: ����ڷκ��� �޽����� �޾� ó��

// hInstance	: ���α׷��� �ν��Ͻ� �ڵ�
// hPrevIns		: ȣȯ���� ���ؼ��� �����ϴ� �Ű�����
// IpCmdLine	: ��������� �Էµ� ���α׷� ���ڰ�(main������ argv)
// nCmdShow		: ���α׷��� ���� ��(���̰� ��) ����(�ּ�ȭ, ���� ��)

// argv��?
// main �Լ��� ���� ���ڰ�

bool windowActive = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpCmdLine, int nCmdShow) {

	return GameManager::GetGameManager()->Loop(hInstance, nCmdShow);
}