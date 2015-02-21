/*  rogueB.c  - rogueB */


#include <xinu.h>
#include <stdio.h>


char rogueB(char rb){
		putc(CONSOLE, rb);
		return rogueB(rb);
}


