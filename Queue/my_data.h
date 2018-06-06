///////////////////////////////////////////////////////////
//   my_aata.h

#ifndef MY_STUDENT_ADFGRETW__H
#define MY_STUDENT_ADFGRETW__H

void *MY_STUDENT_Init(char *llastname, int year, COURSE course);
void MY_STUDENT_Free(void *ptr);
void *MY_STUDENT_Push(char *lastname, int year, COURSE course);
void MY_STUDENT_Print(void *ptr);
int MY_STUDENT_SerchLastName(void *pCurSTUDENT, void *pSearchSTUDENT);
#endif

typedef enum{ it, maths, physics }COURSE;

struct MY_STUDENT
{
    char lastname[512];
	int year;
	COURSE course;
};