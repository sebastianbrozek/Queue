//////////////////////////////////////////////////////////////////////////////////////////
//    my_STACK.h

#ifndef MY_STACK___H
#define MY_STACK___H

struct MY_STACK
{
	void *pData;    
	MY_STACK *next; 
};

typedef void (*FreeData)(void *pdat); 
typedef int (CompData)(void * pcurData, void * pSearchData); 

void MY_STACK_Init(FreeData pFreeDat);
void MY_STACK_Free();
MY_STACK * MY_STACK_Push(void *pdat);
MY_STACK MY_STACK_Pop();
void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry);

#endif