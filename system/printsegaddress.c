/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

extern int etext, edata, end; 

void printsegaddress(){

char *segbound;
int i;

//Address of the end of the text segment & the 12 bytes preceding and following 
	kprintf("end of the text segment:[%08x]\n", ((char *)&etext)-1);
	kprintf("preceding 12 bytes...\n"); 
	segbound = ((char *)&etext);
	segbound - 2;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound--);
	}

	kprintf("following 12 bytes...\n"); 
	segbound = (char *)&etext;
	// segbound++;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound++);
	}

//Address of the end of the data segment & the 12 bytes preceding and following 
	kprintf("\n");
	kprintf("end of the data segment:[%08x]\n", (char *)&edata);
	kprintf("preceding 12 bytes...\n"); 
	segbound = (char *)&edata;
	segbound--;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound--);
	}


	kprintf("following 12 bytes...\n"); 
	segbound = (char *)&edata;
	// segbound++;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound++);
	}

//Address of the end of the bss segment & the 12 bytes preceding and following 
	kprintf("\n");
	kprintf("end of the bss segment::  [%08x]\n", (char *)&end);
	kprintf("Preceding 12 bytes...\n"); 
	segbound--;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound--);
	}


	kprintf("following 12 bytes...\n"); 
	segbound = (char *)&end;
	// segbound++;
	for(i=1; i<=12; i++){
	  kprintf("%d. [%08x]\n", i, segbound++);
	}

}
