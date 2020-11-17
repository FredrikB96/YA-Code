/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>  FSMIntInput.c  <<<<<<<<<<<<<<<<<<<<<<<<<<<
 Subject     	: Full FSM implemented by function pointers
 Programmer  	: Kjell H Carlsson
 Last update	: 2020-10-21
 ==================================================================== */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// define event handler via a struct
// each event has an action and a new state
typedef struct eventAct{
	_Bool (*thisEvent)(char c);	// a func pnt to an event
	void (*action)(char c); 	// a func pnt to an action
	struct eventAct *newState;	// a pointer to next item in eventAct list
}Transition;

// every state is represented by an array of its valid events and actions
// this array is of unknown length, but is terminated by a NULL value
typedef Transition State[];

// list all events, actions and states for an application
// events are implemented as functions returning TRUE or FALSE
_Bool isneg(char c), isadigit(char c), isenter(char c);
_Bool isother(char c), isnotdigit(char c);

// actions are functions too
void kill(char c), negate(char c), putback(char c), store(char c);
void calc(char c);

// possible states of the FSM is (in order of appearance) as follows
extern State WANTSIGN, WANTDIGIT, FINISH;


// the state table
State WANTSIGN={
	/*	event			action		new state */
	{	isneg,			negate,			WANTDIGIT },
	{	isadigit,		putback,		WANTDIGIT },
	{	isenter,		putback,		FINISH	  },
	{	isother,		kill,			WANTSIGN  },
	{	NULL }
};

State WANTDIGIT={
	/*	event			action		new state */
	{	isadigit,		store,		WANTDIGIT  },
	{	isnotdigit,		kill,		WANTDIGIT  },
	{	isenter,		putback,	FINISH	  },
	{	NULL }
};

State FINISH={
	/*	event			action		new state */
	{	isenter,		calc,			NULL  },
	{	NULL }
};

// global variables used by FSM
int number = 0;
_Bool negflag = false, exitflag = false;

/* ================================================================== */
// A full FSM execution routine
int main()
{
char c;

	// init handles to the FSM state tables
	Transition *state = WANTSIGN, *temp=WANTSIGN;

	printf("\n int limits min=%d, max=%d", INT_MIN, INT_MAX);
	printf("\n Enter an integer value: ");  fflush(stdout);


	// stay within FSM until exitflag is encountered
	// read as long as there are chars in buffer
	while(!exitflag && (c=getchar())!= EOF){
		// go thru list of events for current state
		if(temp->thisEvent(c)){
			// perform an action if there is one
			if(temp->action != NULL)
				temp->action(c);

			// move pointers to next state
			temp = state = temp->newState;
		}
		// test if list of events is at end, if not new round
		else{
			ungetc(c, stdin);
			if( (++temp)->thisEvent == NULL)
				temp=state;
		}
	}
	printf("\n Entered (accepted) integer value %d", number);

	return 0;
}


// functions defining possible events
_Bool isneg(char c)
{
	return (c=='-')? true : false;
}

_Bool isadigit(char c)
{
	return (isdigit(c))? true : false;
}

_Bool isenter(char c)
{
	return (c=='\n')? true : false;
}

_Bool isother(char c)
{
	return (!(c=='-' || isdigit(c) || c=='\n'))? true : false;
}

_Bool isnotdigit(char c)
{
	return (!(isdigit(c) || c=='\n'))? true : false;
}


// functions defining actions depending on possible events
void kill(char c)
{
// dummy
}

void negate(char c)
{
	negflag=1;
}

void putback(char c)
{
	ungetc(c, stdin);
}

void store(char c)
{
	long int old_number = number;
	long int test_number = (long)number*10+(c-'0');
	double ratio = (double)test_number/old_number;
	long int diff;

	// test if limit broken, adjust
	if(ratio >= 10.0){
		if(!negflag){
			diff = test_number - INT_MAX;
		}
		else{
			diff = test_number - labs(INT_MIN);
		}
		number = (diff <= 0)? test_number: old_number;
	}

//	printf("Debug: diff %ld, ratio %8.5f \n", diff, ratio);
//	printf("DEBUG: test_number=%ld, number=%d\n\n", test_number, number);
}

void calc(char c)
{
	number=(negflag)? -number: number;
	exitflag=true;
}

