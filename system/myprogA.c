/*  myprogA.c  - myprogA */
#include <xinu.h>
#include <stdio.h>

char myfuncA(char);
int myprogA(int pram){

// Print the address and content of the top of the run-time stack after myprogA() is created but before myfuncA() is called by myprogA().
	register int sp asm ("sp");
	kprintf("\n");
	kprintf("AFTER myprogA is created: address = [%08x] value = %x\n", sp, (int *)sp);

// Print the contents of up to 12 stack locations (in units of 4-byte words) at and "below" the top of the stack
	kprintf("content ""below"":\n");
	int *stack_locations = (int *)sp;
	int i;
	for(i=1; i<=12; i++){
		kprintf("%d. %x\n", i, *stack_locations++);
	}
	kprintf("\n");


	myfuncA('a');
	kprintf("\n");

	return pram;
}
