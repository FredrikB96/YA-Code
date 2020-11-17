/*
 *  StopWatch1_FSM.c
 *  Created on: 7 may 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>

#define TEST_1 {SS, SS, RESET, QUIT}
#define TEST_2 {SS, RESET, SS, SS, RESET, SS, RESET, QUIT}
#define TEST_3 {SS, RESET, SS, SSRESET, SS, SS, SSRESET,RESET, QUIT}

#define MAX 10  // Added

enum State {INIT, GO, HOLD};
enum Event {SS, RESET, SSRESET, QUIT}; // Added SSRESET

const char * convertStateToString(enum State temp);
const char * convertEventToString(enum Event temp);

int main()
{
	enum State current_state = INIT;
	enum State next_state;
	enum Event event;
	int events[] = TEST_3;
	int *event_pnt = events;

	int StoredValues[MAX] = {0,0,0,0,0,0,0,0,0,0};
	int i = 0; // Iteration value

	int values[MAX] = {1,2,3,4,5,6,7,8,9,10};

	printf("StopWatch runs a test \n");

	while( (event = *event_pnt) != QUIT){
		printf("In State %s got Event %s \n",
				convertStateToString(current_state), convertEventToString(event));

		switch(current_state){
			case INIT:
				switch(event){
				case SS:
					next_state = GO;
					printf("--- StopWatch starts ticking! \n");
					break;
				case RESET:
					printf("Ignoring event \n");
					break;
				default:
					printf("Ignoring event \n");
					break;
				}
			break;

			case GO:
				switch(event){
				case SS:
					next_state = HOLD;
					printf("---StopWatch pauses! \n");
					break;
				case RESET:
					printf("Ignoring event \n");
					break;
				default:
					printf("Ignoring event \n");
					break;
				}
			break;

			case HOLD:
				switch(event){
				case SS:
					next_state = GO;
					printf("--- StopWatch resumes ticking! \n");
					break;
				case RESET:
					next_state = INIT;
					printf("--- StopWatch resetting! \n");
					break;
				case SSRESET: // ADDED
					printf("----Stored: %d\n", values[i]);
					StoredValues[i] = values[i];
					i++;
					next_state = INIT;
					break;
				default:
					printf("Ignoring event \n");
					break;
				}
			break;
		}
		event_pnt++;
		current_state = next_state;
	}

	printf("\n Stored vales are: ");
	i=0;
	while(i<MAX)
	{
		printf(" %d", StoredValues[i]);
		i++;
	}

	printf("\n In State %s got Event %s \n", convertStateToString(current_state), convertEventToString(event));
	printf(" StopWatch test is now finished! \n");

	return 0;
}

const char * convertStateToString(enum State temp)
{
	switch(temp){
	case INIT:
		return "INIT";
		break;
	case GO:
		return "GO";
		break;
	case HOLD:
		return "HOLD";
		break;
	}
	return "";
}

const char * convertEventToString(enum Event temp)
{
	switch(temp){
	case SS:
		return "SS";
		break;
	case RESET:
		return "RESET";
		break;
	case SSRESET:
		return "SSRESET";
		break;
	case QUIT:
		return "QUIT";
		break;
	}
	return "";
}
