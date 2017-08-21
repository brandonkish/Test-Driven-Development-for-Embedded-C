// UnityTestSystem.cpp : Defines the entry point for the console application.
//

#include "UnityTestSrc\h\unity_fixture.h"
#include <stdio.h>		//Must be included for Unity to work correctly
#include <setjmp.h>		//Must be included for Unity to work correctly

//Runs all unit tests
void RunAllTests(void)
{
	/* 
	Runs the specified group which is specified by the
	"TEST_GROUP_RUNNER" function inside of "sprintTestRunner.C
	*/
	RUN_TEST_GROUP(sprintf);
	RUN_TEST_GROUP(LedDriver);
}

//Main Function
int main(int argc, const char * argv[])
{

	//Points to function that tells unity which tests to run
	//Accepts runtime arguments
	UnityMain(argc, argv, RunAllTests);
    return 0;
}

