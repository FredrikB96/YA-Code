/*
 * functions.c
 *
 *  Created on: 16 nov. 2020
 *      Author: blomg
 */

#include "CarPlateHeader.h"

_Bool Checker(char temp, const char *filters)
{
	_Bool ok = false;
	if(isupper(temp))
		temp = tolower(temp);



	if((isalpha(temp))||(isdigit(temp))||temp == ' ')
	{
		while(((*filters != ENTER) || (*filters != EOS)) && ok==false)
		{
			ok = (temp == *filters++)? true: ok;
		}
	}
	return ok;
}


void Args_to_char(char *argA[], char res[])
{

	strcpy(res,argA[1]);
	int length = strlen(res);
	res[length] = ' ';
	res[length+1] = EOS;

	strcat(res,argA[2]);

}
