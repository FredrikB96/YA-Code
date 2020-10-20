/*
 ============================================================================
 Name        : Personnr_Assignment.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Personnr_Header.h"

int main(void) {

	// Declaring variables needed
	int Multiply[MAX_INT];
	int sum[MAX_INT];
	char User_Input[MAX_INT];
	_Bool Valid = false;
	_Bool Accepted = true;
	_Bool Leap = false;
	Age user;

	setbuf(stdout,NULL);
	// Declaring pointers and assigning pointers to correct variable
	_Bool *Aptr = &Accepted;
	_Bool *Lptr = &Leap;

	do{
		printf("\n Enter age by format: XXXXXX-XXXX ");
		fgets(User_Input,MAX_INT,stdin);

		int length = strlen(User_Input);
		if((length==EXPECTED)||(length == EXPECTED+1))
		{
			Input_Control(User_Input,Aptr);

			if(Accepted)
			{
				user = Struct_Saving(User_Input);
				Valid = Date_Control(user,Lptr);

				if(Valid)
				{

				}
			}
			else if(!Accepted)
			{
				Accepted = true;
				printf("\n Can't accept letters or special characters with exemption of '-' character");
			}
		}

	}while(!Valid);



	return EXIT_SUCCESS;
}
