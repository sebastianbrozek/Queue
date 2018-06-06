//STACK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_interface.h"
#include "my_stack.h"
#include "my_data.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
	MY_STACK_Init(MY_STUDENT_Free);
	size_t op = 0;
	while(op >= INTERF_PUSH && op <= INTERF_STOP)
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
		case INTERF_PUSH: push();
			break;
		case INTERF_POP: pop();
			break;
		case INTERF_CLEAR: clear();
			break;
		case INTERF_FIND_LASTNAME: find_lastname();
			break;
		case INTERF_STOP: clear(); 
			return 0;
		default:
			printf("nieuznawany kod operacji\n");
		};
	}


	return 0;
}

