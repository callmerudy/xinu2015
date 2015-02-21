/*  myfuncA.c  - myfuncA */


#include <xinu.h>
#include <stdio.h>

char myfuncA(char prog){

// Print the address and content of the top of the run-time stack just after myfuncA() is called but before it returns. 
	register int sp asm ("sp");
	kprintf("AFTER myfuncA is called address: [%08x] value:%x\n", sp, (int *)sp);

	// Print the contents of up to 12 stack locations (in units\n of 4-byte words) at and "below" the top of the stack
	kprintf("content ""below"":\n");
	int *stack_locations = (int *)sp;
	int i;
	for(i=1; i<=12; i++){
		kprintf("%d. %x\n", i, *stack_locations++);
	}
	kprintf("\n");

	return prog;
}
