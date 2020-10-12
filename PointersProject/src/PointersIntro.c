/*
 *  PointersIntro.c
 *  Created on: 8 Oct 2020
 *  Author: Kjell Carlsson
 */


#include <stdio.h>
#include <string.h>

int main()
{
int   *ipnt, ival, ivar[5]={1,3,5,7,9};
float *fpnt, fval, fvar[3]={2.7, 3.14, 7.3};
char  *cpnt, cval, cvar[]="Kalle";
int k;

	setbuf(stdout, NULL);

	printf("\n Basic pointer handling \n");
	// Initial values for variables
	printf("\n Integer values        : ");
	for(k=0; k<5; k++){
		printf(" %d ", ivar[k]);
	}

	printf("\n Floating point values : ");
	for(k=0; k<3; k++){
		printf(" %3.2f ", fvar[k]);
	}
	printf("\n Text string           :  %s \n\n", cvar);

	// Pointers as address to array elements
	ipnt=&ivar[0];
	fpnt=&fvar[2];
	cpnt=cvar;
	printf("\n Pointer addressing    : ipnt->%d, fpnt->%3.2f, cpnt->%c",
			 *ipnt, *fpnt, *cpnt);

	// Pointer arithmetics
	ipnt++;
	fpnt=fpnt-1;
	cpnt=&cvar[0]+(strlen(cvar)/2);
	printf("\n Pointer arithmetic    : ipnt->%d, fpnt->%3.2f, cpnt->%c",
			*ipnt, *fpnt, *cpnt);

	// Pointers to memory contents
	ival=*ipnt;
	fval=*(fpnt-1);
	cval=*cpnt-32;
	printf("\n Memory contents       : ival= %d, fval= %3.2f, cval=  %c",
			ival, fval, cval);
return 0;
}
