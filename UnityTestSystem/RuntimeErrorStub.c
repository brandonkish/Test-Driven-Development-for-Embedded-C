#include "RuntimeErrorStub.h"

//Store last error's parameters
static const char * message = "No Error";
static int parameter = -1;
static const char * file = 0;
static int line = -1;

//Reset the error in memory
void RuntimeErrorStub_Reset(void)
{
	message = "No Error";
	parameter = -1;
}

//Return the message of the last error
const char * RuntimeErrorStub_GetLastError(void)
{
	return message;
}

//Set a runtime error in memory
void RuntimeError(const char * m, int p, const char * f, int l)
{
	message = m;
	parameter = p;
	file = f;
	line = l;
}

//Return the last error's parameter
int RuntimeErrorStub_GetLastParameter(void)
{
	return parameter;
}