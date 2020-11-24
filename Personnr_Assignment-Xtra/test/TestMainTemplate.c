/*
 *  TestMainTemplate.c
 *  Created on: 8 October 2020
 *  Author: Kjell H Carlsson
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
#include "..\src\Personnr_header.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(Divider_Test)  	// Single test defined
{

	char Test_Array1[LONGEST] = {'1','9','9','6','0','1','0','3','1','0','3','3','\n','\0'};

	int length = strlen(Test_Array1);

	char *pntr = &Test_Array1[0];

	divider(pntr,length);

	SimpleTest_AssertString(Test_Array1, "19960103-1033", "Divider didn't work on 12 digits");



//    /// assert that the outcome of your call matches expected outcome
//    SimpleTest_AssertInteger(<<ACTUAL>>, <<EXPECTED>>, "<<ERROR MSG>>");
//    /// or


    /// or 
//    SimpleTest_AssertTrue(<<CONDITION>>, "<<ERROR MSG>>");
//    SimpleTest_AssertFalse(<<CONDITION>>, "<<ERROR MSG>>");

}
SimpleTest_FinalizeTest()				// End of test

/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
void test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n", "<< TARGET NAME >>");

    /// supply name of each test as parameter
    SimpleTest_RunTest(Divider_Test, "Divider Test");	// Run test

}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
    test_batch();						// complete batch of tests will be run

    printf("\nTests completed: %d", SimpleTestCounter);	// tests run

    if( SimpleTestFailCounter == 0){
    	printf("\n All tests passed!"); 			// if batch is successful
    }
    else{
    	printf("\n Tests failed: %d", SimpleTestFailCounter); 	// number of failed tests
    }

    return 0;
}
