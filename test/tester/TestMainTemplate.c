/*
 *  TestMainTemplate.c
 *  Created on: 8 October 2020
 *  Author: Kjell H Carlsson
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
// #include "<< PATH GOES HERE >>"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(<< TEST NAME GOES HERE >>)  	// Single test defined
{
    /// define your test by calling functions from test target
    << TEST CODE GOES HERE >>

    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertInteger(<<ACTUAL>>, <<EXPECTED>>, "<<ERROR MSG>>");
    /// or
    SimpleTest_AssertString(<<ACTUAL>>, <<EXPECTED>>, "<<ERROR MSG>>");
    /// or
    SimpleTest_AssertTrue(<<CONDITION>>, "<<ERROR MSG>>");
    SimpleTest_AssertFalse(<<CONDITION>>, "<<ERROR MSG>>");

}
SimpleTest_FinalizeTest()				// End of test

/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
void test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n", "Datesdiff");

    /// supply name of each test as parameter
    SimpleTest_RunTest(<< TEST NAME >>, "<< TEST NAME >>");	// Run test
    SimpleTest_RunTest(<< TEST NAME >>, "<< TEST NAME >>");	// Run test

}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
    test_batch();						// complete batch of tests will be run

    printf("\n\Tests completed: %d", SimpleTestCounter);	// tests run

    if( SimpleTestFailCounter == 0){
    	printf("\n All tests passed!"); 			// if batch is successful
    }
    else{
    	printf("\n Tests failed: %d", SimpleTestFailCounter); 	// number of failed tests
    }

    return 0;
}
