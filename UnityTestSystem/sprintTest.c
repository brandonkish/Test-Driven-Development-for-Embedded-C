/*
UNITY TEST FILE
*/

#include <stdio.h>
#include <string.h>

#include "UnityTestSrc\h\unity.h"
#include "UnityTestSrc\h\unity_fixture.h"

/*
Not sure what this command is doing. I beleive it
is used as a "bookmark" if you will so a pointer can
be referenced here for the sprintf group. This is
an assumption at this point.
*/
TEST_GROUP(sprintf);


//Resulting string buffer
static char output[100];

//A pointer to a string of type "Const Char" so basically hardcoded string
static const char * expected;

/*
The TEST_SETUP is ran right before every test that
has the same specified group name. So all
tests that have the "sprintf" group name associated
with them will have this function ran right before
each one is executed. This is useful to reduce
executed code. So variables can be re-initalized
before each test run.
*/
TEST_SETUP(sprintf)
{
	memset(output, 0xaa, sizeof output);
	expected = "";
}

/*
The TEST_TEAR_DOWN function is ran right after each test is executed
that has the same specified group name. So all tests
that have the "sprintf" group name associated
with them will have this function ran right after
each one is exectued. i.e. disposing of objects
Useful for reducing repeated code.
*/
TEST_TEAR_DOWN(sprintf)
{

}

/*
Moves the "expected" pointer to the new "const char" string
*/
static void expect(const char * s) 
{
	expected = s;
}

/*
Compares the "const char" string that the expected pointer is pointing to
to the output buffer to determine if they match. it brings in the number
of characters that were written to the buffer as a result of the generated
string returned.
*/
static void given(int charsWritten)
{
	TEST_ASSERT_EQUAL(strlen(expected), charsWritten);				//compares the lengths of the expected string to the charsWritten to the buffer
	TEST_ASSERT_EQUAL_STRING(expected, output);						//Compares teh two strings to see if they are equal
	TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);	//Checks the end of the string to test if there was a buffer overflow or errornus data
}

/*
This is a test in the sprintf group. Its name is "test1". This test was called using the
RUN_TEST_CASE comamnd inside of the TEST_GROUP_RUNNER command in the "sprintTestRunner.c"
file. Tests that sprintf returns the same string value that is passed into it into the
buffer.
*/
TEST(sprintf, test1)
{
	expect("hey");													//sets the "expected" pointer to the const string "hey" in memory
	given(sprintf(output, "hey"));									//sprintf returns the number of chars writtin to the buffer for the "hey" const char string
}

/*
This is a test in the sprintf group. Its name is "test2". This test was called using the
RUN_TEST_CASE comamnd inside of the TEST_GROUP_RUNNER command in the "sprintTestRunner.c"
file. This tests sprintf for string replacement to verify that the resulting string is
infact correctly inserting the "World" string into the input string.
*/
TEST(sprintf, test2)
{
	expect("Hello World\n");
	given(sprintf(output, "Hello %s\n", "World"));
}