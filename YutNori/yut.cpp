#include "util.h"
#include "yut.h"


int CheckYutResult(short gubun, const char* yut)
{
	int tot = 0;
	for (int i = 0; i < YUT_COUNT; i++)
		tot += yut[i];

	char strGubun[20];
	if ( gubun== COMPUTER )
		strcpy_s(strGubun, 20, "��ǻ�ʹ�");
	else 
		strcpy_s(strGubun, 20, "�����");

	switch (tot)
	{
	case FRONT_DO: printf("%s ���� �������ϴ�. �ܿ� ��ĭ ������ �����մϴ�.\n\n", strGubun); break;
	case GAE: printf("%s ���� �������ϴ�. ��ĭ ������ �����մϴ�.\n\n", strGubun); break;
	case GIRL:printf("%s ���� �������ϴ�. ��ĭ ������ �����մϴ�.\n\n", strGubun); break;
	case YUT: printf("%s �Ϳ�! ���� �������ϴ�. ��ĭ ������ �����մϴ�.\n\n", strGubun); break;
	case MO: printf("%s ���! �� �������ϴ�. �ټ�ĭ ������ �����մϴ�.\n\n", strGubun);
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

		printf("��ǻ�Ϳ� �����̸� �����մϴ�\n\n");
		printf("���� 20�� �����ϸ� �¸��մϴ�\n\n");
		printf("���� �����÷��� ����Ű�� ġ����)\n\n");
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
				printf("����� %dĭ ������ �����߽��ϴ�. ���� ��ġ�� %dĭ �Դϴ�.\n\n", cur, myPos);
				if (cur > GIRL)
					printf("����� �ѹ��� �����ϴ�.\n\n");
			} while (cur > GIRL);
			
			do
			{
				ThrowYut(yut);
				cur = CheckYutResult(COMPUTER, yut);
				comsPos += cur;
				printf("��ǻ�ʹ� %dĭ ������ �����߽��ϴ�. ���� ��ġ�� %dĭ �Դϴ�.\n\n", cur, comsPos);
				if (cur > GIRL)
					printf("��ǻ�ʹ� �ѹ��� �����ϴ�.\n\n");
			} while (cur > GIRL);

			printf("����� ��ġ�� %dĭ, ��ǻ���� ��ġ�� %dĭ �Դϴ�.\n\n", myPos, comsPos);
			
			if (comsPos >= GOAL || myPos >= GOAL)
				break;

			printf("���� �����÷��� ����Ű�� ġ����)\n\n");			
			_getch();			
		}

		if (comsPos > myPos)
		{
			printf("��ǻ���� �¸��Դϴ�.");
		}
		else
		{
			printf("����� �¸��Դϴ�.");
		}

		printf("�ƹ�Ű�� ��������.\n\n");
		_getch();

	} while (1);
		
	return 1;
}