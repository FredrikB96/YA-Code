/*
 *  Keyboard_BitField.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>

// bitfield definition for an 8-bit port
typedef struct{
	unsigned int  row1 : 1;
	unsigned int  row2 : 1;
	unsigned int  row3 : 1;
	unsigned int  row4 : 1;
	unsigned int  cols : 4;
}PORT1;


// function prototypes
void writeport(PORT1 test);
PORT1 readport(void);

/* --------------------- Start of Main Program ------------------- */
int main()
{
	PORT1 kbport = {};
	unsigned char inpattern;
	int stop=0;

	setbuf(stdout, NULL);

	// init keyboard all rows enabled
	kbport.row1=1;
	kbport.row2=1;
	kbport.row3=1;
	kbport.row4=1;

	writeport(kbport);
	// repeat until any key pressed
	do{
		// read input from keyboard
		kbport = readport();
		inpattern = kbport.cols;

		// test if any key pressed
		if(inpattern != 0x0F){
			stop=1;
			puts("\n Key pressed!");
		}
	}while(!stop);

	return 0;
}

// simulated input from 4x4 keyboard
PORT1 readport(void)
{
int insignal=0, inbit[4], k;
PORT1 test = {};

	printf("\n\n Enter a 4-bit simulated input signal  ( 1 1 1 1 ) : "); fflush(stdout);
	for(k=0; k<4; k++){
		scanf(" %d", &inbit[k]);
	}

	for(k=0; k<4; k++){
		insignal=insignal*2+inbit[k];
	}
	test.cols=insignal;

return test;
}

// simulated output to 4x4 keyboard
void writeport(PORT1 test)
{
int k, rowstatus[4];

	rowstatus[0]=test.row1;
	rowstatus[1]=test.row2;
	rowstatus[2]=test.row3;
	rowstatus[3]=test.row4;

	printf("\n\n Initialization of keyboard \n");
	for(k=0; k<4; k++){
		printf("\n row%d - ", k+1);
		(rowstatus[k])? putchar('1'): putchar('0');
	}

}
