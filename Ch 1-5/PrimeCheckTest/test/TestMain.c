/*
 *  TestMainTemplate.c
 *  Created on: 8 October 2020
 *  Author: Kjell H Carlsson
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
#include "..\\src\PrimeCheck.h"

extern uint16_t prime_count;

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(Prime_Test1)  	// Single test defined
{
    /// define your test by calling functions from test target
	uint32_t start_value = 11321;
	uint32_t temp_value = handle_even_factors(start_value);
	handle_odd_factors(temp_value, 1);

    /// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(prime_count, 1, "Test value IS a Prime!");

}
SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(No_Prime_Test1)  	// Single test defined
{
    /// define your test by calling functions from test target
	uint32_t start_value = 32648;
	uint32_t temp_value = handle_even_factors(start_value);
	handle_odd_factors(temp_value, 1);
	const char* msg = create_output_msg();

    /// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertString(msg, "No prime number", "Tested value is NOT a prime!");

}
SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(Prime_Test2)  	// Single test defined - should fail!
{
    /// define your test by calling functions from test target
	uint32_t start_value = 31;
	uint32_t temp_value = handle_even_factors(start_value);
	handle_odd_factors(temp_value, 1);

    /// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertFalse((prime_count != 1), "Test number IS a Prime!");

}
SimpleTest_FinalizeTest()

/// supply name of your test as parameter
SimpleTest_CreateTest(No_Prime_Test2)  	// Single test defined
{
    /// define your test by calling functions from test target
	uint32_t start_value = 821238;
	uint32_t temp_value = handle_even_factors(start_value);
	handle_odd_factors(temp_value, 1);

    /// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertTrue((prime_count != 1), "Test number is NOT a Prime!");

}
SimpleTest_FinalizeTest()				// End of test



/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
void test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n\n", "PrimeCheck");

    /// supply name of each test as parameter
    SimpleTest_RunTest(Prime_Test1, "Prime_Test1");			// Run test
    SimpleTest_RunTest(No_Prime_Test1, "No_Prime_Test1");	// Run test
    SimpleTest_RunTest(Prime_Test2, "Prime_Test2");			// Run test
    SimpleTest_RunTest(No_Prime_Test2, "No_Prime_Test2");	// Run test

}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
    test_batch();												// complete batch of tests will be run

    printf("\n Tests completed: %d", SimpleTestCounter);		// tests run

    if( SimpleTestFailCounter == 0){
    	printf("\n All tests passed!"); 						// if batch is successful
    }
    else{
    	printf("\n Tests failed: %d", SimpleTestFailCounter); 	// number of failed tests
    }

    return 0;
}
