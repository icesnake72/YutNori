#include "util.h"

void WelcomeMessageOut()
{
	WindowClear();

	printf("Game Pack에 오신걸 환영합니다.\n\n");

	printf("다음중 한개의 번호를 선택하시면 해당 게임으로 이동합니다.\n\n");

	printf("원하시는 게임을 선택해주세요\n\n");

	printf("1) 숫자 야구 게임\n\n");

	printf("2) 윷놀이 게임\n\n");

	printf("3) 블랙잭 게임\n\n");

	printf(QUIT_INFO);
}

void ByeMessage()
{
	WindowClear();

	printf("이용해 주셔서 감사합니다.\n\n");
	printf("안녕히 가세요\n\n");
}

int CheckTerminate()
{
	int key = _getch();
	if (key == 'X' || key == 'x')
		return 0;

	return key;
}

int SelectGame()
{
	return CheckTerminate();
}

void WindowClear()
{
	system("cls");
}

void Randomize()
{
	srand((unsigned int)time(NULL));
}



