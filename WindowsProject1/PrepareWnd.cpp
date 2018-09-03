#include "PrepareWnd.h"
#include "WindowProc.h"



PrepareWnd::PrepareWnd() {
	// �������� ��Ÿ��
	// CS_HREDRAW | CS_VREDRAW : �������� ���� Ȥ�� ���� ũ�Ⱑ ����� ��� �����츦 �ٽ� �׸�
	style = CS_HREDRAW | CS_VREDRAW;

	// �������� �޽��� ó�� �Լ��� ����
	lpfindWndProc = WindowProc::WndProc;

	// ������ Ŭ���� ���� �޸�
	cbClsExtra = 0;

	// ������ �ν��Ͻ� ���� �޸�
	cbWndExtra = 0;

	// â �������� ����
	// IDI_ASTERISK			: !(����ǥ) ����� ������
	// IDI_EXCLAMATION		: ���� ����� ������
	// IDI_QUESTION			: ����ǥ ����� ������
	// ������� ���� ���	: NULL
	hIcon = LoadIcon(NULL, IDI_ASTERISK);

	// �ش� â���� ���� Ŀ�� ����
	// IDC_ARROW	: ȭ��ǥ ���
	// IDC_CROSS	: ���� ���
	// IDC_HAND		: Ŭ�� �հ��� ���
	// IDC_PIN		: �� �հ��� ���
	hCursor = LoadCursor(NULL, IDC_ARROW);

	// ��� ������ ä���� �귯��
	hbrBackground = NULL;

	// RegisterClass �� �����츦 ����� �� ����ϰ��� �ϴ� ������ Ŭ���� �̸�
	lpszClassName = L"winClass";

	// â �̸�
	lpWindowName = g_TitleName;

	// ������ ��Ÿ��
	// WS_OVERLAPPEDWINDOW : ���� ������ ��Ÿ��
	dwStyle = WS_OVERLAPPEDWINDOW;

	// â�� ���̱� �Ӽ�
	// SW_SHOW				: �����츦 Ȱ��ȭ�ϸ� ���̵��� ��
	// SW_SHOWMAXIMUMIZED	: �����츦 �ִ�ȭ �� ���·� Ȱ��ȭ��
	// SW_SHOWMINIMUMIZED	: �����츦 �ּ�ȭ �� ���·� Ȱ��ȭ��
	nCmdShow = SW_SHOW;
}


PrepareWnd::~PrepareWnd() {
}
