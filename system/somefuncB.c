/*  somefuncB.c  - somefuncB */


#include <xinu.h>
#include <stdio.h>

int somefuncB(char param){

  sleepms((100));
  putc(CONSOLE, param);
  return 1;
}
