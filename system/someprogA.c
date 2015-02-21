/*  someprogA.c  - someprogA */


#include <xinu.h>
#include <stdio.h>

int somefuncA(char );

void someprogA(){
	putc(CONSOLE, 'A');
	somefuncA('a');
	putc(CONSOLE, 'A');
}
