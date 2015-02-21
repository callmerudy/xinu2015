/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>
#include <lab1.h>

// long host2netl_asm(long);
// long net2hostl_asm(long);
// void printsegaddress();
// void printprocstks();
// char myfuncA(char);
// int myprogA(int);
// int somefuncA(char);
// void someprogA();
// void someprogB(char);
// char rogueB(char);
// void rogueB2();


process	main(void){


/* 					Lab 1: Getting Acquainted with XINU 			*/

/*----------------------------------------------*
* 3. Inspecting XINU's run-time environment*
*-----------------------------------------------*/

//------3.1	long host2netl_asm (long param), net2hostl_asm (long param)

			unsigned long address = 0x1bfa0947;
			kprintf("address: %08x\n", address);
			kprintf("host2net: %08x\n", host2netl_asm(address));
			kprintf("net2host: %08x\n", net2hostl_asm(address));


//------3.2	printsegaddress()

			printsegaddress();


//------3.3 Examining the run-time stack


		//Print the address and content of the top of the run-time stack before myprogA() is created.
			register int sp asm ("sp");
			kprintf("BEFORE myprogA is created: address = [%08x]\tvalue = [%x]\n", sp, (int *)sp);
		// Print the contents of up to 12 stack locations (in units of 4-byte words) at and "below" the top of the stack
			kprintf("contents ""below"" the top of the stack:\n");
			int *stack_locations = (int *)sp;
			int i;
			for(i=1; i<=12; i++){
				kprintf("%d. [%08x]\n", i, *stack_locations++);
			}
			kprintf("\n");

			resume(create(myprogA, 2048, 20, "myprogA", 1, 10));
			kprintf("\n");
			


//------3.4 void printprocstks()

			printprocstks();



// ----------------------------------------------------------------
// *5. Impact of intentional stack overflow
// -----------------------------------------------------------------
// */

			// // resume(create(someprogB, 512, 20, "someprogB", 1,  'B'));
			resume(create(rogueB2, 512, 20, "rogueB2", 0));
			resume(create(someprogA, 512, 20, "someprogA", 1, 'A'));

		
		
		recvclr();
		// Recreate shell
		while(TRUE){
			receive();
			sleepms(200);
			kprintf("\n\nMain process recreating shell\n\n");
			resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
		
		}

	return OK;

}
