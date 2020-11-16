/*
 ============================================================================
 Name        : temp.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef char *va_list;
#define va_start(ap, v)ap=(va_list)&v + sizeof(v)
#define va_end(ap)ap=NULL

int main(int args, char *argval[] ) {
	setbuf(stdout,NULL);

	char val;

	va_list argpntr;

	if(args)
	{
	va_start(argpntr,args);

	for(int i=0; i<args;i++)
	{
		val = va_arg(argpntr,char);
		printf(" %c", val);
	}
	}
	else
	{
		printf("\n No args found");
	}

	va_end(argpntr);
	return EXIT_SUCCESS;
}

