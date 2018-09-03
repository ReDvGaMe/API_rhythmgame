#include "PrepareWnd.h"
#include "WindowProc.h"



PrepareWnd::PrepareWnd() {
	// 윈도우의 스타일
	// CS_HREDRAW | CS_VREDRAW : 윈도우의 수직 혹은 수평 크기가 변경될 경우 윈도우를 다시 그림
	style = CS_HREDRAW | CS_VREDRAW;

	// 윈도우의 메시지 처리 함수를 지정
	lpfindWndProc = WindowProc::WndProc;

	// 윈도우 클래스 여분 메모리
	cbClsExtra = 0;

	// 윈도우 인스턴스 여분 메모리
	cbWndExtra = 0;

	// 창 아이콘을 설정
	// IDI_ASTERISK			: !(느낌표) 모양의 아이콘
	// IDI_EXCLAMATION		: 세모 모양의 아이콘
	// IDI_QUESTION			: 물음표 모양의 아이콘
	// 사용하지 않을 경우	: NULL
	hIcon = LoadIcon(NULL, IDI_ASTERISK);

	// 해당 창에서 사용될 커서 지정
	// IDC_ARROW	: 화살표 모양
	// IDC_CROSS	: 십자 모양
	// IDC_HAND		: 클릭 손가락 모양
	// IDC_PIN		: 핀 손가락 모양
	hCursor = LoadCursor(NULL, IDC_ARROW);

	// 배경 색상을 채색할 브러쉬
	hbrBackground = NULL;

	// RegisterClass 로 윈도우를 등록할 때 등록하고자 하는 윈도우 클래스 이름
	lpszClassName = L"winClass";

	// 창 이름
	lpWindowName = g_TitleName;

	// 윈도우 스타일
	// WS_OVERLAPPEDWINDOW : 가장 무난한 스타일
	dwStyle = WS_OVERLAPPEDWINDOW;

	// 창의 보이기 속성
	// SW_SHOW				: 윈도우를 활성화하며 보이도록 함
	// SW_SHOWMAXIMUMIZED	: 윈도우를 최대화 된 상태로 활성화함
	// SW_SHOWMINIMUMIZED	: 윈도우를 최소화 한 상태로 활성화함
	nCmdShow = SW_SHOW;
}


PrepareWnd::~PrepareWnd() {
}
