/*  rogueB2.c  - rogueB2 */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
static unsigned long  *esp;
void roguefuncB();



void rogueB2(){
    unsigned int sptr;
    unsigned int chr = 'a';
    unsigned int spVal=chr;

    sleepms(10);
    asm("movl %esp,esp");
    sptr=*(unsigned int*)esp;

    while(sptr!=spVal){
      esp--;
      sptr=*(unsigned int*)esp;
    }
    esp--;
    *esp=(unsigned int)&roguefuncB;
}

void roguefuncB(){
	putc(CONSOLE, 'Q');
  kill(currpid); 
}
