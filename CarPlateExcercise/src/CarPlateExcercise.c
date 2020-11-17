/*
 ============================================================================
 Name        : CarPlateExcercise.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "CarPlateHeader.h"

int main(int argc, char *argv[]) {

	setbuf(stdout,NULL);
	_Bool ok = false;

	char *filters[MAX] = {LETTER, LETTER, LETTER, SEP, DIGIT, DIGIT, DIGIT};
	char *New[MAX] = {LETTER, LETTER, LETTER, SEP, DIGIT, DIGIT, LETTER};

	if(argc > 1 && argc < 4)
	{
		int k = 0;
		char temp = 'a';
		printf("\n Arguments found, will use them");
		char args[MAX];



		Args_to_char(argv,args);

		int length;
		length = strlen(args);

		while((temp=args[k]) != EOS)
		{
			if(isdigit(args[length]))
				ok = Checker(temp,filters[k]);
			else
				ok = Checker(temp,New[k]);
			if(!ok)
				break;
			k++;
		}
	}
	else
	{
		if(argc>3)
			printf("\n Too many arguments found will return too user input");
		int k = 0;
		char temp[MAX];
		printf("\n Input plate number using format XXX XXX \n Input: ");
		fgets(temp,MAX,stdin);

		int length= strlen(temp);

		while(temp[k] != ENTER)
		{
			if(isdigit(temp[length]))
				ok = Checker(temp[k],filters[k]);
			else
				ok = Checker(temp[k],New[k]);
			if(!ok)
				break;
			k++;
		}
	}

	if(ok)
		printf("\n Input valid!");

	else
		printf("\n Input invalid!");

	return EXIT_SUCCESS;
}
