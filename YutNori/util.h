#pragma once

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define TERMINATE   0
#define QUIT_INFO	"x (�Ǵ� X)Ű�� ������ �����մϴ�.\n\n"

void WelcomeMessageOut(void);

void ByeMessage(void);

void WindowClear(void);

int CheckTerminate(void);

int SelectGame(void);

void Randomize(void);

