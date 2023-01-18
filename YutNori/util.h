#pragma once

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define TERMINATE   0
#define QUIT_INFO	"x (또는 X)키를 누르면 종료합니다.\n\n"

void WelcomeMessageOut(void);

void ByeMessage(void);

void WindowClear(void);

int CheckTerminate(void);

int SelectGame(void);

void Randomize(void);

