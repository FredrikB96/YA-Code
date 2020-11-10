/*
 *  GeneralConverter.c
 *  Created on: 20 okt. 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>

// the function prototype looks like this
void array_func (
	float vec[],
	float(*const funcpnt) (float, float),
	float conv,
	int n
)
// the function body looks like this
{
	// as long as there are items in the list - convert
	while(n>0){
		vec[--n] = funcpnt(vec[n], conv);
	}
}

#define ARRAY_SIZE 5

// other function prototypes
float offset(float val, float conv);
float scale(float val, float conv);
void fahr_to_cels(float temp[], int n);

/* -------------------- Start of Main Program ---------------- */
int main()
{
	float temp[ARRAY_SIZE]={100.0, 75.3, 32.0, 0.0, -11.3};

	printf("\n Old temps in Fahrenheit:");
	for(int k=0; k<ARRAY_SIZE; k++){
		printf(" %5.1f", temp[k]);
	}
	// call conversion function
	fahr_to_cels(temp, ARRAY_SIZE);

	printf("\n New temps in Celsius   :");
	for(int k=0; k<ARRAY_SIZE; k++){
		printf(" %5.1f", temp[k]);
	}

return 0;
}


/* -------------------- function offset ---------------------
 adds a constant offset to a value
 input  - base value, offset
 output - adjusted value
 ----------------------------------------------------------- */
float offset(float val, float conv)
{
	return(val+conv);
}

/* -------------------- function scale ----------------------
 multiplies a value by a fixed constant
 input  - base value, convert constant
 output - converted value
----------------------------------------------------------- */
float scale(float val, float conv)
{
	return(val*conv);
}


/* ---------------------- fahr_to_cels ------------------------
 converts temperatures in F to C, via call to general function
 input  - array of floats, number of values
 output - indirect new values in array
------------------------------------------------------------- */
void fahr_to_cels(float temp[], int n)
{
	array_func(temp, offset, -32.0, n);
	array_func(temp, scale, 5.0/9.0, n);
}
