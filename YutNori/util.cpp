#include "util.h"

void WelcomeMessageOut()
{
	WindowClear();

	printf("Game Pack�� ���Ű� ȯ���մϴ�.\n\n");

	printf("������ �Ѱ��� ��ȣ�� �����Ͻø� �ش� �������� �̵��մϴ�.\n\n");

	printf("���Ͻô� ������ �������ּ���\n\n");

	printf("1) ���� �߱� ����\n\n");

	printf("2) ������ ����\n\n");

	printf("3) ���� ����\n\n");

	printf(QUIT_INFO);
}

void ByeMessage()
{
	WindowClear();

	printf("�̿��� �ּż� �����մϴ�.\n\n");
	printf("�ȳ��� ������\n\n");
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



