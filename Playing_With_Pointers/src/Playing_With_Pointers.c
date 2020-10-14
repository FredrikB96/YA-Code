/*
 ============================================================================
 Name        : Playing_With_Pointers.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "header.h"

int main(void) {

	setbuf(stdout,NULL);

	// DECLARING THE VARIABLES
	char User_FirstName[MAX_INPUT];
	char User_LastName[MAX_INPUT];
	int User_Age;

	char Relative_FirstName[MAX_INPUT];
	char Relative_LastName[MAX_INPUT];
	int Relative_Age;

	char Input[TOTAL_INPUT_LENGTH];
	_Bool Valid = false;

	// CREATING AND DECLARING POINTERS
	// POINTER NAMES ARE DEFINED FOLLOWING EX: Relative_FirstName becomes RelaviveFirstpointer, then shortened RFptr.
	// Relative_LastName becomes RelativeLastpointer(RLptr)

	char *RFptr = Relative_FirstName;
	char *RLptr = Relative_LastName;
	int *RAptr = Relative_Age;

	char *UFptr = User_FirstName;
	char *ULptr = User_LastName;
	int *UAptr = User_Age;

	char *IPptr = Input;

	// START OF PROGRAM
	do{

		printf("Enter your relatives first name and last name, followed by his/hers age\n");
		fgets(Input,TOTAL_INPUT_LENGTH, stdin);

		Valid = Input_Control(&IPptr,&RFptr,&RLptr,&RAptr);
	}while(!Valid);

	return EXIT_SUCCESS;
}



_Bool Input_Control(char *IPCptr,char *FNptr,char *LNptr,int *Age)
{
	// DECLARING THE VARIABLES TO BE USED IN THIS FUNTION
	_Bool Valid = false;
	_Bool First_Name = false;

	int size = strlen(*IPCptr);
	int p = 0;
	int k = 0;
	int tempAge[3];

	// SPLITTING THE INPUT ARRAY TO FIRST NAME, LAST NAME AND AGE
	// USING POINTERS ONLY, IPCptr = Input VARIABLE FROM MAIN
	for(int i =0;i<size;i++)
	{
		if(isdigit(IPCptr[i]))
		{
			tempAge[k] = IPCptr[i];
			p++;
		}
		if(isalpha(IPCptr[i]))
		{
			if(!First_Name)
			{
				*FNptr = IPCptr[i];
				k++;
			}
			else
			{
				*LNptr = IPCptr[i];
			}
		}
		if(IPCptr == ' ')
		{
			First_Name = true;
		}

	}

	return Valid;
}
