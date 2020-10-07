/*
 * Input_Control.c
 *
 *  Created on: 7 okt. 2020
 *      Author: Benny
 */

#include "header.h"

_Bool Input_Control(int Inputs, Dates date)
{
	_Bool Valid = true;

	for(int i=0;i<Inputs;i++)
	{
		if(date.year>MAX_YEAR)
		{
			Valid = false;
		}
		if(date.month>MAX_MONTH)
		{
			Valid = false;
		}
		if(date.day>MAX_DAYS)
		{
			Valid = false;
		}
	}


	return Valid;
}
