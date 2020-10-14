/*
 *  TestMainTemplate.c
 *  Created on: 8 October 2020
 *  Author: Kjell H Carlsson
 */
#include <stdio.h>

//#include "Test_Header.h"
#include "SimpleCTester.h"
/// supply path to .h file holding function headers of your test target
#include "header.h"


SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(DatesdiffTest)  	// Single test defined
{
	/// define your test by calling functions from test target
	//  << TEST CODE GOES HERE >>
	Dates Ref_Date ={1600,9,15};


	Dates Test_Date ={2020,2,29};

	Dates Correct_Result={420,7,14};

	Dates temp = datediff(Ref_Date,Test_Date);

	/// assert that the outcome of your call matches expected outcome
	/// Predefined "functions" from the header filed called " SimpleCTester "
	SimpleTest_AssertInteger(temp.year, Correct_Result.year, "Got back the wrong year of date 1");
	SimpleTest_AssertInteger(temp.month, Correct_Result.month , "Got back the wrong month of date 1");
	SimpleTest_AssertInteger(temp.day, Correct_Result.day , "Got back the wrong day of date 1");

	Dates Test_Date1 ={1850,11,14};
	Dates Correct_Result1={250,2,1};
	Dates temp1 = datediff(Ref_Date,Test_Date1);

	SimpleTest_AssertInteger(temp1.year, Correct_Result1.year, "Got back the wrong year of date 2");
	SimpleTest_AssertInteger(temp1.month, Correct_Result1.month , "Got back the wrong month of date 2");
	SimpleTest_AssertInteger(temp1.day, Correct_Result1.day , "Got back the wrong day of date 2");

	Dates Test_Date2 ={2030,9,4};
	Dates Correct_Result2={430,0,11};
	Dates temp2 = datediff(Ref_Date,Test_Date2);

	SimpleTest_AssertInteger(temp2.year, Correct_Result2.year, "Got back the wrong year of date 3");
	SimpleTest_AssertInteger(temp2.month, Correct_Result2.month , "Got back the wrong month of date 3");
	SimpleTest_AssertInteger(temp2.day, Correct_Result2.day , "Got back the wrong day of date 3");
}
SimpleTest_FinalizeTest()				// End of test

/// Repeat the pattern above for all your tests for test target

SimpleTest_CreateTest(LeapYearTest)  	// Single test defined
{

	Dates Leap={2020,2,29};
	Dates Date={1900,3,30};

	_Bool Valid1 = Leap_Year(Leap);
	_Bool Valid2 = Leap_Year(Date);

	SimpleTest_AssertTrue(Valid1, " Did not detect Leap Year");
	SimpleTest_AssertFalse(Valid2, " Did detect Leap Year");

}
SimpleTest_FinalizeTest()				// End of test

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
void test_batch()
{
	/// supply info for presentation of outcome of test batch
	printf("\n Running tests for %s \n", "Datesdiff");

	/// supply name of each test as parameter
	SimpleTest_RunTest(DatesdiffTest, " Datesdiff ");	// Run test
	SimpleTest_RunTest(LeapYearTest, " Leap_Year ");	// Run test

	//SimpleTest_RunTest(Datesdiff, "<< TEST NAME >>");	// Run test

}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
	test_batch();						// complete batch of tests will be run

	printf("\n Tests completed: %d", SimpleTestCounter);	// tests run

	if( SimpleTestFailCounter == 0){
		printf("\n All tests passed!"); 			// if batch is successful
	}
	else{
		printf("\n Tests failed: %d", SimpleTestFailCounter); 	// number of failed tests
	}

	return 0;
}
