/*  someprogB.c  - someprogB */

#include <xinu.h>
#include <stdio.h>
#include "lab1.h"

char rogueB(char );
int somefuncB(char );

void someprogB(char spb){
	putc(CONSOLE, spb);
	sleepms(100);
	rogueB(spb);
	// somefuncB('b');
}
