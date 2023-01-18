#include "util.h"
#include "yut.h"


int CheckYutResult(short gubun, const char* yut)
{
	int tot = 0;
	for (int i = 0; i < YUT_COUNT; i++)
		tot += yut[i];

	char strGubun[20];
	if ( gubun== COMPUTER )
		strcpy_s(strGubun, 20, "컴퓨터는");
	else 
		strcpy_s(strGubun, 20, "당신은");

	switch (tot)
	{
	case FRONT_DO: printf("%s 도를 던졌습니다. 겨우 한칸 앞으로 전진합니다.\n\n", strGubun); break;
	case GAE: printf("%s 개를 던졌습니다. 두칸 앞으로 전진합니다.\n\n", strGubun); break;
	case GIRL:printf("%s 걸을 던졌습니다. 세칸 앞으로 전진합니다.\n\n", strGubun); break;
	case YUT: printf("%s 와우! 윷을 던졌습니다. 네칸 앞으로 전진합니다.\n\n", strGubun); break;
	case MO: printf("%s 대박! 모를 던졌습니다. 다섯칸 앞으로 전진합니다.\n\n", strGubun);
	}

	return tot;
}

void ThrowYut(char *yut)
{
	for (int i = 0; i < YUT_COUNT; i++)
		yut[i] = rand() % 2;
}

int YutNori()
{
	do
	{
		WindowClear();

		printf("컴퓨터와 윷놀이를 시작합니다\n\n");
		printf("먼저 20에 도달하면 승리합니다\n\n");
		printf("윷을 던지시려면 엔터키를 치세요)\n\n");
		printf(QUIT_INFO);

		int key = 0;		// ENTER KEY == 13
		if (CheckTerminate() == TERMINATE)
			break;

		int myPos = 0;
		int comsPos = 0;
		int cur = 0;
		
		char yut[YUT_COUNT] = { 0 };

		while (1) {
			WindowClear();
			
			do {
				ThrowYut(yut);
				cur = CheckYutResult(USER, yut);
				myPos += cur;
				printf("당신은 %d칸 앞으로 전진했습니다. 현재 위치는 %d칸 입니다.\n\n", cur, myPos);
				if (cur > GIRL)
					printf("당신은 한번더 던집니다.\n\n");
			} while (cur > GIRL);
			
			do
			{
				ThrowYut(yut);
				cur = CheckYutResult(COMPUTER, yut);
				comsPos += cur;
				printf("컴퓨터는 %d칸 앞으로 전진했습니다. 현재 위치는 %d칸 입니다.\n\n", cur, comsPos);
				if (cur > GIRL)
					printf("컴퓨터는 한번더 던집니다.\n\n");
			} while (cur > GIRL);

			printf("당신의 위치는 %d칸, 컴퓨터의 위치는 %d칸 입니다.\n\n", myPos, comsPos);
			
			if (comsPos >= GOAL || myPos >= GOAL)
				break;

			printf("윷을 던지시려면 엔터키를 치세요)\n\n");			
			_getch();			
		}

		if (comsPos > myPos)
		{
			printf("컴퓨터의 승리입니다.");
		}
		else
		{
			printf("당신의 승리입니다.");
		}

		printf("아무키나 누르세요.\n\n");
		_getch();

	} while (1);
		
	return 1;
}