/*
 * Datesdiff.c
 *
 *  Created on: 6 okt. 2020
 *      Author: Benny
 */

#include "header.h"

Dates datediff (Dates d1, Dates d2){
	Dates diff;

	if(d1.year>=d2.year)
	{
		diff.year = d1.year - d2.year;
	}
	else if (d1.year<d2.year)
	{
		diff.year = d2.year - d1.year;
	}
	if (d1.month>=d2.month)
	{
		diff.month = d1.month - d2.month;
	}
	if (d1.month<d2.month)
	{
		diff.month = d2.month - d1.month;
	}
	if (d1.day>=d2.day)
	{
		diff.day = d1.day - d2.day;
	}
	if (d1.day<d2.day)
	{
		diff.day = d2.day - d1.day;
	}
	return diff;
}
