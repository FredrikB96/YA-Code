/*
 * Personnr_Functions.c
 *
 *  Created on: 20 okt. 2020
 *      Author: Benny
 */


#include "Personnr_Header.h"

void divider(char *Input,int length)
{
	char temp[MAX_INT];
	_Bool Found = false;
	char *Cpntr = Input;

	for(int i=0;*Input !='\n';i++) // Checks if user have entered '-' character
	{
		if(*Input=='-')
		{
			Found = true;
		}
		Input++;
	}

	Input = Cpntr; // resets pointer

	if(!Found) // If '-' is not found it will insert it at correct position
	{
		int i;
		if(length<LONGEST && length>SEVEN+1) // If input length is as expected then continue
		{

			for(i=0;*Input !='\n';i++)
			{
				if(length == MAX_AGE+LAST_FOUR) // if user input has 12 digits ie: 198801031033 then do this
				{
					if(i==SEVEN+1)
					{
						temp[i] = '-';
					}
					else
					{
						temp[i] = *Input;
						Input++;
					}
				}
				if(length == EXPECTED) // if user input has 10 digits ie: 8101031033 then do this
				{
					if(i==SEVEN-1)
					{
						temp[i] = '-';
					}
					else
					{
						temp[i] = *Input;
						Input++;
					}
				}
			}
			temp[i] = '\n';
			temp[i+1] = '\0';
			Input = Cpntr;

			length = strlen(temp);
			for(i=0;i<length;i++)
			{
				*Input = temp[i];
				Input++;
			}
			*Input = '\0';


		}
	}

}

void remover(char *Input)
{
	char temp[LONGEST];
	char *Cptr;

	Cptr = Input; // safety pointer to reset input pointer when we moved it
	Input++; // Moves forward Input pointer twice to remove the first 2 digits
	Input++;

	for(int i=0;*Input!='\0';i++)
	{
		temp[i] = *Input; // Stores the input in temp char to enable write over User_input in main
		Input++;
	}

	Input = Cptr; // Resets pointer

	for(int i=0;*Input!='\0';i++)
	{
		*Input = temp[i]; // stores over the Input from main to remove the first two digits in the User_Input array in main.
		Input++;
	}

	*Input = '\0';
}

void Input_Control(char Input[],_Bool *Aptr)
{
	// Goes thru the Input array after letters
	// Assigning the boolean Accepted from main to false if found
	char temp;
	int found = 0; //  New because program must have - to function
	for(int i=0;temp !='\n';i++)
	{

		temp = Input[i];
		if((temp <'0'||temp >'9')&&temp !='-'&&temp !='\n')
		{
			*Aptr = false;
		}
		if(temp == '-')  // if found - character add one to counter
			found++;
	}
	if(found>1||found<1)
		// if we found - character check counter to see if its more than 1,then say we can only have one used, if not found ask for one
	{
		*Aptr = false;
		if(found>1)
		{
		printf("\n Can't have more than one '-' character, please enter as advised");
		}
		{
		printf("\n Can't find '-' character, please enter as advised");
		}
	}
}

Age Struct_Saving(char Input[]){

	Age user;

	// Assigning pointers to first positions in arrays
	int *Yptr = &user.year[0];
	int *Mptr = &user.month[0];
	int *Dptr = &user.day[0];
	int *Lptr = &user.last[0];
	int *Cptr = &user.control;

	char temp;

	for(int i=0;temp !='\n';i++){
		temp = Input[i];

		if(i<EVEN)
		{
		Char_To_Struct(temp, Yptr); // Saves down char input to struct
		Yptr++; // Moving pointer forward
		}
		if(i<FOUR && i>=EVEN)
		{
			Char_To_Struct(temp, Mptr);
			Mptr++;
		}
		if(i<SEVEN && i>=FOUR)
		{
			Char_To_Struct(temp, Dptr);
			Dptr++;
		}
		if(i>=SEVEN && i<MAX_AGE)
		{
			Char_To_Struct(temp, Lptr);
			Lptr++;
		}
		if(i==MAX_AGE)
		{
			Char_To_Struct(temp,Cptr);
		}

	}

	return user;
}

void Char_To_Struct(char Input, int *Iptr)
{
	int temp = Input - '0'; // Converts to int from char
	*Iptr = temp;
}

_Bool Date_Control(Age user,_Bool *Lptr){

	// Enumiration to help with control of correct number of days in month
	enum months {Jan = 1,Feb,Mars,April,May,June,July,Aug,Sept,Oct,Nov,Dec};
	enum Days{Janu = 31, Febr = 28, Apri = 30, Febru = 29};

	_Bool Valid = false;
	int Corrected = Year_Corrected(user); // Converts two digit year input to four year input

	Leap_Year(Corrected,Lptr);  // Checks for leap year
	char temp_Cmonth[LAST_FOUR];
	char temp_Cday[LAST_FOUR];
	int temp_day;
	int temp_month;
	int p = 0;

	for(int i=0;i<EVEN;i++) // Converts the month and day to char from int to enable the atoi function
	{
		temp_Cmonth[p] = user.month[i] +'0';
		temp_Cday[p] = user.day[i] +'0';
		p++;
	}

	temp_Cday[p] = '\n'; // Assigning end of string character to the variable
	temp_Cmonth[p] = '\n';

	temp_day = atoi(temp_Cday); // Converts back to int from char, was needed to do this since we store the value in an array
	temp_month = atoi(temp_Cmonth);

	if((temp_month==April)||(temp_month==June)||(temp_month==Sept)||(temp_month==Nov)) // Control for number of days in the month
	{
		if(temp_day<=Apri)
		{
			Valid = true;
		}
	}
	if(temp_month==Feb)
	{
		if(*Lptr == true) // if leap ýear was found, the it should be 29 days in february
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

	for(int i=0;i<EVEN;i++) // Converts int to char then using atoi to convert back to int, to get the array of numbers to a single variable
	{
		user_year[i] = user.year[i] + '0';
	}
	user_year[2] = '\n';
	int temp_year = atoi(user_year);


	char Correct_Year[5];
	if(temp_year < START) // if user year are below 21 then the user must be born 00 and forward, so we assign 20 to the start
	{
		Correct_Year[0] = '2';
		Correct_Year[1] = '0';
	}
	if(temp_year > START) // If user year are above 21 the  user are born above 1921 and under 00 so we assign 19 to the start
	{
		Correct_Year[0] = '1';
		Correct_Year[1] = '9';
	}
	int p = EVEN;
	for(int i=0;i<EVEN;i++) // Converts back to char to use atoi
	{
		Correct_Year[p] = user.year[i] + '0';
		p++;
	}
	Correct_Year[p] = '\n';

	int Corrected_Year = 0;
	Corrected_Year = atoi(Correct_Year);

	return Corrected_Year; // Returns the four digit year
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
	for(int i=0;i<MAX_AGE-ODD;i++) // Will multiply each digit with either 2 or 1
	{
		if(i<EVEN) // if i is less then 2 then its the year digits we are using
		{
			if((i % EVEN)==0) // If i are even then we should multiply by 2
			{
				*Sum = *Aptr * EVEN;
				Aptr++;
				Sum++;
			}
			else // If i is odd then multiply with 1
			{
				*Sum = *Aptr * ODD;
				Aptr++;
				Sum++;
			}
		}
		if(i>=EVEN && i<=LAST_FOUR) // If i are 2 or above but less than 4 then we should use month digits
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
		if(i>LAST_FOUR && i<SEVEN-1) // if i are above 3 and less than 6 we should use the day digits
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
		if(i>=SEVEN-1 && i<MAX_AGE) // if i are above 6 then it is the last 3 digits we should use
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

	for(int i=0;i<MAX_AGE-ODD;i++) // Adding each digit in the array together to each other
	{
		if(*Sum>=10)
		{
			value += *Sum - 9; // if the variable to be added are above 10 then we remove 9 to get the correct value (ie 14 = 1 + 4 = 5// 14 - 9 = 5)
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

	int temp = Sum % MAX_AGE; // Divides by 10 until not possible longer
	int result = MAX_AGE - temp; // removing the remainder from 10 to get the control value

	if(result>=10)  // If result still are above 10 we remove 10 to get the correct value as control value
	{
		result -= MAX_AGE;
	}

	if(result==Control)
	{
		Correct= true;
	}

	return Correct;
}
