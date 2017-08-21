/*
UNITY TEST FILE
*/



#include "UnityTestSrc\unity.h"
#include "myTests.h"


void setUp(void)
{
	/* This is run before EACH TEST */

}

void tearDown(void)
{
}

//A test that will always pass
void testWillAlwaysPass(void)
{
	TEST_ASSERT_EQUAL_INT(42, 42);
}

void testWillAlwaysFail(void)
{
	TEST_ASSERT_EQUAL_INT(42, 0);
}