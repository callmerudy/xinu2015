/*  somefuncA.c  - somefuncA */


#include <xinu.h>
#include <stdio.h>

int somefuncA(char param){

	sleepms((100));
	putc(CONSOLE, param);
	return 1;
	
}
