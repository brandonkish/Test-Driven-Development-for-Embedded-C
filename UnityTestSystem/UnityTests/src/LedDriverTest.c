#include "..\..\UnityTestSrc\h\unity_fixture.h"
#include <stdint.h>
#include "..\..\ledDriver.h"

TEST_GROUP(LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(LedDriver)
{
	LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{

}

//Test that the leds turn off
TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;					//Init all leds to off
	LedDriver_Create(&virtualLeds);					//Create leds
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);		//Test that leds were created and init
}

//Test that the first led turns on
TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);							//Turn led 1 on
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);		//Test led 1 is on
}

//Turn first led off
TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);							//Turn led 1 on
	LedDriver_TurnOff(1);							//Turn led 1 off
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

//Turn multiple leds on
TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);							//Turn on led 9
	LedDriver_TurnOn(8);							//Turn on led 8
	TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);	//Test led 8 & 9 are on
}

TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();							//Turn all leds on
	LedDriver_TurnOff(8);							//Turn off led 8
	TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLeds);	//Test if led 9 is on and led 8 is off
}

//Turn on all leds
TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();							//Turn all leds on
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);	//Test all leds are on
}

//Turn on all leds
TEST(LedDriver, AllOff)
{
	LedDriver_TurnAllOn();							//Turn all leds on
	LedDriver_TurnAllOff();							//Turn all leds off
	TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);	//Test all leds are on
}

//Test if the memeory is not readable
TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;							//Turn on all leds
	LedDriver_TurnOn(8);							//Turn on led 8
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);	

}

//Test that nothing happens if the led values when turning the led on
TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
	LedDriver_TurnOn(-1);							//Test for out of bounds led -1
	LedDriver_TurnOn(0);							//Test for out of bounds led 0
	LedDriver_TurnOn(17);							//Test for out of bounds led 17
	LedDriver_TurnOn(3141);							//Test for out of bounds led 3141
	TEST_ASSERT_EQUAL_HEX16(0x0, virtualLeds);

}

//Test that nothing happens if the led values when turning the led off
TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
	LedDriver_TurnAllOn();							//Turn all leds on
	LedDriver_TurnOff(-1);							//Test for out of bounds led -1
	LedDriver_TurnOff(0);							//Test for out of bounds led 0
	LedDriver_TurnOff(17);							//Test for out of bounds led 17
	LedDriver_TurnOff(3141);						//Test for out of bounds led 3141
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);

}

//Test that RuntimeErrors are being recorded correctly
TEST(LedDriver, OutOfBoundsProducesRuntimeError)
{
	LedDriver_TurnOn(-1);											//Send an out of bounds value to the "LedDriver_TurnOn()" function to generate an error
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",		//Test that the last runtime error string recieved matches an out-of-bounds
		RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());		//Test that the parameter passed to the ErrorRuntime matches that of a out-of-bounds error
}

//TODO: Decide what to do at runtime
IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
	/* TODO: what should we do during runtime */
}

TEST(LedDriver, IsOn)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

TEST(LedDriver, OutOfBoundsLedsAreAlwaysOff)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(0));
	TEST_ASSERT_FALSE(LedDriver_IsOn(17));

}

TEST(LedDriver, IsOff)
{
	TEST_ASSERT_TRUE(LedDriver_IsOff(12));
	LedDriver_TurnOn(12);
	TEST_ASSERT_FALSE(LedDriver_IsOff(12));
	TEST_ASSERT_FALSE(LedDriver_IsOff(12));

}