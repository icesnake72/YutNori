#pragma once

#define YUT_COUNT	4

#define	FRONT_DO	1
#define	GAE			2
#define GIRL		3
#define YUT			4
#define MO			0
#define BBACK_DO	-1

#define BACK		0
#define FRONT		1

#define USER		1
#define COMPUTER	2

#define GOAL		20

int YutNori(void);

void ThrowYut(char* yut);

int CheckYutResult(short gubun, const char* yut);