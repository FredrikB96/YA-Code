/*
 * SimpleCTester.h
 * Created on: 8 October 2020
 * Author: Kjell H Carlsson
 */

#ifndef SRC_SIMPLECTESTER_H_
#define SRC_SIMPLECTESTER_H_

/********************************* Includes **********************************/
#include <string.h>
#include <stdio.h>

/**************************** Constants and Types ****************************/
#define TRUE 1
#define FALSE 0

/********************************* Variables *********************************/
extern int SimpleTestCounter;
extern int SimpleTestFailCounter;


/***************************** Exported Macro Functions ****************************/
#define SimpleTest_AssertInteger(IntA, IntB, Message) { if(IntA != IntB) { ++SimpleTestFailCounter; return Message; } }
#define SimpleTest_AssertString(StringA, StringB, Message) { if (strcmp(StringA, StringB) != 0) { ++SimpleTestFailCounter; return Message; } }
#define SimpleTest_AssertTrue(Condition, Message) { if(Condition != TRUE) { ++SimpleTestFailCounter; return Message; } }
#define SimpleTest_AssertFalse(Condition, Message) { if(Condition != FALSE) { ++SimpleTestFailCounter; return Message; } }

#define SimpleTest_Initialize() int SimpleTestCounter = 0u; int SimpleTestFailCounter = 0u;
#define SimpleTest_CreateTest(Name) static char* Name(void) {
#define SimpleTest_FinalizeTest() return NULL; }
#define SimpleTest_RunTest(test, Name) {char *message = test(); printf("\n * Test no %d: %s ", ++SimpleTestCounter, Name); if(message) { printf("FAILED %s\n\n", message); }else{ printf("passed\n\n"); } }


#endif /* SRC_SIMPLECTESTER_H_ */


