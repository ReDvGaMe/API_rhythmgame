#include "defines.h"
#include "GameManager.h"

// WinApi = 이벤트 반응형 프로그램
// WinApi에서 Window를 만드는 과정
// 1. WndClass 정의	: 사용할 창의 속성을 정의
// 2. RegisterClass	: 윈도우 클래스 등록
// 3. CreateWindow	: 메모리상에 윈도우를 생성
// 4. ShowWindow	: 윈도우 화면 출력
// 5. 메시지 루프	: 사용자로부터 메시지를 받아 처리

// hInstance	: 프로그램의 인스턴스 핸들
// hPrevIns		: 호환성을 위해서만 존재하는 매개변수
// IpCmdLine	: 명령행으로 입력된 프로그램 인자값(main에서의 argv)
// nCmdShow		: 프로그램이 실행 될(보이게 될) 형태(최소화, 숨김 등)

// argv란?
// main 함수가 받은 인자값

bool windowActive = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpCmdLine, int nCmdShow) {

	return GameManager::GetGameManager()->Loop(hInstance, nCmdShow);
}