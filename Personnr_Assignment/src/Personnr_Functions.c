/*
 * Personnr_Functions.c
 *
 *  Created on: 20 okt. 2020
 *      Author: Benny
 */


#include "Personnr_Header.h"


void Input_Control(char Input[],_Bool *Aptr)
{
	int size = strlen(Input);

	char temp;
	for(int i=0;temp !='\n';i++)
	{
		temp = Input[i];
		if((temp <'0'||temp >'9')&&temp !='-'&&temp !='\n')
		{
			*Aptr = false;
		}
	}
}

Age Struct_Saving(char Input[]){
	// year,month,day bools are needed to control if we saved year,month and day variables
	_Bool year = false;
	_Bool month = false;
	_Bool day = false;
	_Bool Last_four = false;

	Age user;

	int digits = 0;
	int position = 0;
	char temp;


	for(int i=0;!year;i++)
	{
		temp = Input[position];
		position++;
		if((temp >='0'&&temp<='9')&&!year)
		{
			int age = temp -'0';
			user.year[digits] = age;
			digits++;
			if(digits>1)
			{
				year = true;
				digits=0;
			}
		}
	}

	for(int i=0;!month;i++)
	{
		temp = Input[position];
		position++;
		if((temp >='0'&&temp<='9')&&(year)&&!month)
		{
			int Month = temp -'0';
			user.month[digits] = Month;
			digits++;
			if(digits>1)
			{
				month = true;
				digits=0;
			}
		}
	}
	for(int i=0;!day;i++)
	{
		temp = Input[position];
		position++;
		if((temp >='0'&&temp<='9')&&(year)&&(month)&&!day)
		{
			int Day = temp -'0';
			user.day[digits] = Day;
			digits++;
			if(digits>1)
			{
				day = true;
				digits=0;
			}
		}
	}

	for(int i=0;!Last_four;i++)
	{
		temp = Input[position];
		position++;
		if(temp >='0'&&temp <='9')
		{
			int last = temp - '0';
			if(digits<LAST_FOUR)
			{
				user.last[digits] = last;
				digits++;
			}
			else {
				user.control = last;
				Last_four = true;
			}
		}
	}

	return user;
}

_Bool Date_Control(Age user,_Bool *Lptr){

	enum months {Jan = 1,Feb,Mars,April,May,June,July,Aug,Sept,Oct,Nov,Dec};
	enum Days{Janu = 31, Febr = 28, Apri = 30, Febru = 29};

	_Bool Valid = false;
	int Corrected = Year_Corrected(user);

	Leap_Year(Corrected,Lptr);
	char temp_Cmonth[LAST_FOUR];
	char temp_Cday[LAST_FOUR];
	int temp_day;
	int temp_month;
	int p = 0;

	for(int i=0;i<EVEN;i++)
	{
		temp_Cmonth[p] = user.month[i] +'0';
		temp_Cday[p] = user.day[i] +'0';
		p++;
	}

	temp_Cday[p] = '\n';
	temp_Cmonth[p] = '\n';

	temp_day = atoi(temp_Cday);
	temp_month = atoi(temp_Cmonth);

	if((temp_month==April)||(temp_month==June)||(temp_month==Sept)||(temp_month==Nov))
	{
		if(temp_day<=Apri)
		{
			Valid = true;
		}
	}

	if(temp_month==Feb)
	{
		if(*Lptr == true)
		{
			if(temp_day<=Febru)
			{
				Valid = true;
			}
		}
		if(temp_day<=Febr)
		{
			Valid = true;
		}
	}

	else
	{
		if(temp_day<=Janu)
			Valid = true;
	}
	return Valid;
}

int Year_Corrected(Age user)
{
	char user_year[LAST_FOUR];

	for(int i=0;i<EVEN;i++)
	{
		user_year[i] = user.year[i] + '0';
	}
	user_year[2] = '\n';
	int temp_year = atoi(user_year);


	char Correct_Year[5];
	if(temp_year < START)
	{
		Correct_Year[0] = '2';
		Correct_Year[1] = '0';
	}
	if(temp_year > START)
	{
		Correct_Year[0] = '1';
		Correct_Year[1] = '9';
	}
	int p = 2;
	for(int i=0;i<EVEN;i++)
	{
		Correct_Year[p] = user.year[i] + '0';
		p++;
	}
	Correct_Year[p] = '\n';

	int Corrected_Year = 0;
	Corrected_Year = atoi(Correct_Year);

	return Corrected_Year;
}

void Leap_Year(int Year,_Bool *Lptr)
{

	int A = 4;
	int B = 100;
	int C = 400;

	if(Year % A == 0)
	{
		if(Year % B == 0)
		{
			if(Year % C == 0)
			{
				*Lptr = true;
			}
		}
		else
		{
			*Lptr = true;
		}
	}


}

void Multiply(int *Aptr, int *Mptr, int *Dptr,int *Lptr, int *Sum)
{
	for(int i=0;i<MAX_AGE-ODD;i++)
	{
		if(i<EVEN)
		{
			if((i % EVEN)==0)
			{
				*Sum = *Aptr * EVEN;
				Aptr++;
				Sum++;
			}
			else
			{
				*Sum = *Aptr * ODD;
				Aptr++;
				Sum++;
			}
		}
		if(i>=EVEN && i<=LAST_FOUR)
		{
			if((i % EVEN)==0)
			{
				*Sum = *Mptr * EVEN;
				Mptr++;
				Sum++;
			}
			else
			{
				*Sum = *Mptr * ODD;
				Mptr++;
				Sum++;
			}
		}
		if(i>LAST_FOUR && i<6)
		{
			if((i % EVEN)==0)
			{
				*Sum = *Dptr * EVEN;
				Dptr++;
				Sum++;
			}
			else
			{
				*Sum = *Dptr * ODD;
				Dptr++;
				Sum++;
			}

		}
		if(i>=6 && i<MAX_AGE)
		{
			if((i % EVEN)==0)
			{
				*Sum = *Lptr * EVEN;
				Lptr++;
				Sum++;
			}
			else
			{
				*Sum = *Lptr * ODD;
				Lptr++;
				Sum++;
			}
		}
	}
}

int Add(int *Sum)
{
	int value = 0;

	for(int i=0;i<MAX_AGE-ODD;i++)
	{
		if(*Sum>=10)
		{
			value += *Sum - 9;
			Sum++;
		}
		else
		{
			value += *Sum;
			Sum++;
		}
	}

	return value;
}

_Bool control(int Control,int Sum)
{
	_Bool Correct = false;

	int temp = Sum % MAX_AGE;
	int result = MAX_AGE - temp;

	if(result>=10)
	{
		result -= MAX_AGE;
	}

	if(result==Control)
	{
		Correct= true;
	}

	return Correct;
}
