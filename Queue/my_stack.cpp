// my_STACK.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_stack.h"

static MY_STACK *first  = NULL;
FreeData ptr_free_dat;          

void MY_STACK_Init(FreeData pFreeDat)
{
	first = NULL;
	ptr_free_dat = pFreeDat;
}

void MY_STACK_Free()
{
	MY_STACK *p = first, *ptmp = NULL;

	while(p)
	{
		(*ptr_free_dat)(p->pData);
		ptmp = p;
		p = p->next;
		free(ptmp);
	}

	first = NULL;
}

MY_STACK * MY_STACK_Push(void *pdat)
{

	MY_STACK *current = (MY_STACK *)malloc(sizeof(MY_STACK));
	//if (!current)
	//{
	//	my_mess_fun(MY_MESS_MEM_ALLOC_NOT_FATAL);
	//	return NULL;
	//}
	current->next = first;
	current->pData = pdat;
	first = current;

	return current;
}



MY_STACK MY_STACK_Pop()
{
	MY_STACK rv;
	if (!first)
	{

		rv.pData = NULL;
		rv.next = NULL;
	}
	else
	{

		MY_STACK *next = first->next;
		rv.pData = first->pData;
		rv.next = NULL;
		free(first);
		first = next;
	}

	return rv;
}

void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry)
{
	static MY_STACK *p;
	MY_STACK *ptmp = NULL;

	if (FirstEntry)
		p = first;

	while (p)
	{
		if (!(*ptr_comp_fun)(p->pData, pSearchDat))
		{
			p = p->next;
		}
		else
		{
			ptmp = p;
			p = p->next; 
			return ptmp->pData; 
		}
	}

	return NULL;
}