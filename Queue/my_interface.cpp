//////////////////////////////////////////////////////////////////////
//  my_interface.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_data.h"
#include "my_stack.h"
#include "my_interface.h"

#pragma warning (disable : 4996)

static char *strtab[] =
{
	"0 - push",			 //INTERF_PUSH
	"1 - pop",			 //INTERF_POP
	"2 - clear",		 //INTERF_CLEAR
	"3 - find lastname", //INTERF_FIND_LASTNAME
	"4 - finish"         //INTERF_STOP
};

void menu()
{
	size_t it;
	for(it=0; it<INTERF_TOT; ++it)
	{
		printf("%s\n", strtab[it]);
	}
}

void push()
{
	char lastname[512];
	int year;
	COURSE course;
	printf("lastname, year\n");
	scanf("%s", lastname);
	scanf("%d", &year);
	scanf("%s", &course);

	void *pdat = MY_STUDENT_Push(lastname, year, it);
	if(!MY_STACK_Push(pdat))
		printf("push error\n");
}


void pop()
{
	MY_STACK tmp = MY_STACK_Pop();
	MY_STUDENT_Print(tmp.pData);
	MY_STUDENT_Free(tmp.pData);
}

void find_lastname()
{
	char str[512];
	printf("input lastname\n");
	scanf_s("%s", str, sizeof(str));
	MY_STUDENT serachDat;
	memset(&serachDat, 0, sizeof(MY_STUDENT));
	strcpy_s(serachDat.lastname, sizeof(serachDat.lastname), str);
	
	void * pDat = MY_STACK_Search(&serachDat, MY_STUDENT_SerchLastName, 1);

	if (pDat)
	{
		printf("found : \n");
		MY_STUDENT_Print(pDat);
	}
	
	while (pDat)
	{
		pDat = MY_STACK_Search(&serachDat, MY_STUDENT_SerchLastName, 0);
		if (pDat)
		{
			printf("found : \n");
			MY_STUDENT_Print(pDat);
		}
	}
}

void clear()
{
	MY_STACK_Free();
}