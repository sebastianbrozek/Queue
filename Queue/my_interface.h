//////////////////////////////////////////////////////////////////////////////
//   my_interface.h

#ifndef MY_INTERFACE___H
#define MY_INTERFACE___H

enum MY_INTERF_EN
{
	INTERF_PUSH,
	INTERF_POP,
	INTERF_CLEAR,
	INTERF_FIND_LASTNAME,
	INTERF_STOP,
	INTERF_TOT
};

void push();
void pop();
void clear();
void menu();
void find_lastname();

#endif