/*
 *  Inport_Outport_Union.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>

// union definition for an 8-bit programmable port
typedef union{
	unsigned char inport;
	unsigned char outport;
}PORTX;

PORTX readport();
void writeport(PORTX);

/* --------------------- Start of Main Program ------------------- */
int main()
{
PORTX port = {};
unsigned char inpattern, outpattern=0xF0;

	setbuf(stdout, NULL);

	// init and send output pattern
	port.outport = outpattern;
	writeport(port);

	// read input pattern from port
	port = readport();
	inpattern = port.inport;

	// negate insignal on outport
	port.outport = ~inpattern;
	writeport(port);

return 0;
}

// simulated input from an 8-bit inport
PORTX readport()
{
int insignal=0, inbit[8], k;
PORTX test = {};

	printf("\n Enter an 8-bit input signal  :  ");
	for(k=0; k<8; k++){
		scanf(" %d", &inbit[k]);
	}

	for(k=0; k<8; k++){
		insignal = (insignal<<1)+inbit[k];
	}
	test.inport = insignal;

return test;
}

// simulated output to an 8-bit outport
void writeport(PORTX test)
{
int outbit[8], k;
unsigned char mask = 0x80;

	// shift out signal bit by bit
	for(k=7; k>=0; k--){
		outbit[k] = ((test.outport & mask) != 0)? 1: 0;
		mask=mask >> 1;
	}

	printf("\n Simulated 8-bit output signal: ");
	for(k=7; k>=0; k--){
		printf(" %d", outbit[k]);
	}
}
