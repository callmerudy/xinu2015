/*  printprocstks.c  - printprocstks */
#include <xinu.h>
#include <stdio.h>

char myfuncA(char);
int myprogA(int);

// print the stack base, stack size, stack limit, stack pointer and the process id

void printprocstks(){

	int i;
	struct procent *prentry;


	kprintf("\n");
	create(myprogA, 1024, 20, "myprogA", 1, 'm');
	create(myfuncA, 1024, 20, "myfuncA", 1, 2);


	for(i=0; i<NPROC; i++){

		// struct procent *prentry = &proctab[i];
		prentry = &proctab[i];

		if(prentry->prstate != PR_FREE){

			kprintf("\n");
			kprintf("Proc [%s].Pid = %d\n", prentry->prname, i);
			kprintf(" Stack: ");
			kprintf("Base = %08x\n", (prentry->prstkbase));
			kprintf(" Len = %x\n", prentry->prstklen);
			kprintf(" Limit = %08x\n", (prentry->prstkbase)-(prentry->prstklen));
			if(prentry->prstate == PR_CURR){
				register int sp asm ("sp");
				kprintf("StkPtr = %08x\n", sp);
			}
			else{
				kprintf("StkPtr = %08x\n", (prentry->prstkptr));
			}
		}
	}
	
	printf("\n");
}
