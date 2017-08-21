#include "..\..\UnityTestSrc\h\unity.h"
#include "..\..\UnityTestSrc\h\unity_fixture.h"


/*
This file houses all of the test groups. It does not house the
tests themselves. It keeps track of which tests belong to which
group.

"TEST_GROUP_RUNNER" specifies the group name
"RUN_TEST_CASE" specifies the test that is associated with
the specified group. So you pass the group name, and then the
name of the test into "RUN_TEST_CASE".

This file is more for easy organization. The actual tests being
run are found in "sprintTest.c"
*/

TEST_GROUP_RUNNER(sprintf)
{
	//The RUN_TEST_CASE command runs the specified tests in the group
	RUN_TEST_CASE(sprintf, test1);
	RUN_TEST_CASE(sprintf, test2);
}

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLedOne);
	RUN_TEST_CASE(LedDriver, TurnOffLedOne);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
	RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, AllOn);
	RUN_TEST_CASE(LedDriver, AllOff);
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadable);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOnDoesNoHarm);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffDoesNoHarm);
	RUN_TEST_CASE(LedDriver, OutOfBoundsProducesRuntimeError);
	RUN_TEST_CASE(LedDriver, OutOfBoundsToDo);
	RUN_TEST_CASE(LedDriver, IsOn);
	RUN_TEST_CASE(LedDriver, OutOfBoundsLedsAreAlwaysOff);
	RUN_TEST_CASE(LedDriver, IsOff);
}