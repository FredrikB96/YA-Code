/*
 * Input_Control.c
 *
 *  Created on: 7 okt. 2020
 *      Author: Benny
 */

#include "header.h"

enum Year{Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Okt, Nov, Dec};
enum Days{Janu = 31, Febr = 28, Apri = 30, Febru = 29};


_Bool Input_Control(Dates date)
{
	_Bool Valid = false;
	_Bool Leap = Leap_Year(date);

	if(date.year>=EARLIEST_YEAR)
	{
		if(date.year<=MAX_YEAR)
		{
			if((date.month==Apr)||(date.month==Jun)||(date.month==Sept)||(date.month==Nov))
			{
				if(date.day<=Apri)
					Valid = true;
			}
			if(date.month==Feb)
			{
				if(Leap)
				{
					if(date.day<=Febru)
					{
						Valid = true;
					}
				}
				if(date.day<=Febr)
				{
					Valid = true;
				}
			}
			else
			{
				if(date.day<=Janu)
					Valid = true;
			}
		}
	}
	else
	{
		Valid = false;
	}

	return Valid;
}

_Bool Leap_Year(Dates date){

	_Bool Leap_Year = false;

	int A = 4;
	int B = 100;
	int C = 400;




	if(date.year % A == 0)
	{
		if(date.year % B == 0)
		{
			if(date.year % C == 0)
			{
				Leap_Year = true;
			}
		}
		else
		{
			Leap_Year = true;
		}
	}

	if(Leap_Year)
	{
		printf("\n Leap year! February takes 29 days.");
	}

	if(!Leap_Year)
	{
		printf("\n Not a leap year! Februari takes 28 days.");
	}

	return Leap_Year;
}
