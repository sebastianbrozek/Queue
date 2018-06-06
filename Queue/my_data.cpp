/////////////////////////////////////////////////////////////////////////////////////
//    my_STUDENT.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_data.h"
#include "string.h"

#pragma warning (disable : 4996)

void *MY_STUDENT_Init(char *llastname, int year, COURSE course)
{
	MY_STUDENT *pdat = (MY_STUDENT *)malloc(sizeof(MY_STUDENT));
	if(pdat)
	{
		strcpy(pdat->lastname, llastname); 
		pdat->year = year;
		pdat->course = course;

	}
	return (void *)(pdat);
}


void MY_STUDENT_Free(void *ptr)
{
	MY_STUDENT *pDat = (MY_STUDENT *)ptr;
	if(pDat)
		free(pDat);
}

void * MY_STUDENT_Push(char *lastname, int year, COURSE course)
{
	return MY_STUDENT_Init(lastname, year, course);
}

void MY_STUDENT_Print(void *ptr)
{
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	if(p)
	{
		printf("lastname: %s\n", p->lastname);
		printf("course    : %d\n", p->course);
		printf("year    : %d\n", p->year);
		//printf("course: %s\n ", p->course);
	}
}

int MY_STUDENT_SerchLastName(void *pCurSTUDENT, void *pSearchSTUDENT)
{
	MY_STUDENT *pcur    = (MY_STUDENT *)pCurSTUDENT;
	MY_STUDENT *psearch = (MY_STUDENT *)pSearchSTUDENT;

	if (strcmp(pcur->lastname, psearch->lastname) == 0)
		return 1;

	return 0;
}