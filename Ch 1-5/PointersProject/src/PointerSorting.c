/*
 * PointerSorting.c
 * Created on: 8 Oct 2020
 * Author: Kjell Carlsson
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 40
#define MOD 100

/* ----- function prototypes ----- */
void pnt_sort(int ifield[], int n);
void print_out(int *numpnt, int n);


/* -------------------- Start of Main Program -------------------- */
int main()
{
int num[MAX], n, k;

srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Function parameters using pointers \n");

	do{
		printf("\n Enter number of random values(max %d): ", MAX);
		scanf(" %d", &n);
	}while(!(n>0 && n<=MAX));

	puts("\n Unsorted random values");
	for(k=0; k<n; k++){
		num[k]=rand() % MOD;
		printf("  %2d", num[k]);
	}

	pnt_sort(num, n);
	puts("\n\n Sorted random numbers");
	print_out(num, n);

return 0;
}

/********************** Function pnt_sort **************************
	Sort an array of n integers by using pointers
	input  - unsorted array, number of integers
	output - none
  -----------------------------------------------------------------*/
void pnt_sort(int ifield[], int n)
{
int *ip, *jp, *min, temp;

	for (ip=ifield; ip<&ifield[n-1]; ip++){
		min=ip;

		for (jp=ip+1; jp<&ifield[n]; jp++){
			if (*min > *jp )
				min=jp;
		}
		temp=*ip;
		*ip=*min;
		*min=temp;
	}
}

/********************** Function print_out **************************
	Presents an array of n integers to console using pointers
	input  - array of integers, number of integers
	output - none
  -----------------------------------------------------------------*/
void print_out(int *numpnt, int n)
{
int *i;
	 for (i=numpnt; i<numpnt+n; i++){
		printf(" %3d", *i);
	 }
}
