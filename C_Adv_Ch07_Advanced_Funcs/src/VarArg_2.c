/*
 *  VarArg_2.c
 *  Created on: 20 okt. 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdarg.h>

// function prototype
void intprintf(const char *string, ...);

/* --------------------- Start of Main Program ------------------------ */
int main()
{

	printf("\n\n List of integers: ");
	intprintf(" Val1=%d, Val2=%d, Val3=%d, Val4=%d", 15, 11, 39, 42);

	printf("\n percentage test: ");
	intprintf("  5% of %d is %d", 200, 5*200/100);

	printf("\n percentage test : ");
	intprintf(" %d of %d is %d%", 20, 100, 20*100/100);

	printf("\n-------------- End of program ------------------");

return 0;
}

void intprintf(const char *string, ...)
{
int val, flag=0;
va_list argptr;
char temp;

	// init pointer to first argument in list
	va_start(argptr, string);

	// print string including ints when %d found
	while((temp=*string++) != '\0'){
		// test if read char could be start of specifier
		if(temp=='%'){
			flag++;
			// test if '%' at end of string
			if((temp=*string) != '\0'){
				// test if correct specifier read
				if(temp=='d'){
					flag--;
					string++;
					// read argument from list
					val=va_arg(argptr, int);
					printf("%d", val);
				}
			}
		}
		// copy read char
		else
			putchar(temp);

		// test if '%' should be printed out
		if(flag){
			putchar('%');
			flag=0;
		}
	}

	// set argument pointer to NULL at end of list
	va_end(argptr);
}
