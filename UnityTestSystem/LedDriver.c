#include "LedDriver.h"
#include <stdint.h>
#include "RuntimeError.h"
#include <stdbool.h>

static uint16_t * ledsAddress;				// Address of LED registry
static uint16_t ledsImage;					// Holds current state of leds

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

// Init LEDs
void LedDriver_Create(uint16_t  * address)
{
	ledsAddress = address;					// Update LED address
	ledsImage = ALL_LEDS_OFF;
	*ledsAddress = ledsImage;// Turn LEDs off
}



void LedDriver_Destroy(void)
{

}

//Turn all leds on
void LedDriver_TurnAllOn(void)
{
	ledsImage = ALL_LEDS_ON;
	*ledsAddress = ledsImage;
}

//Turn all leds off
void LedDriver_TurnAllOff(void)
{
	ledsImage = ALL_LEDS_OFF;
	*ledsAddress = ledsImage;
}

//Convert a number to a bit
static uint16_t convertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static bool IsLedOutOfBounds(int ledNumber)
{
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}

// Turn on a LED
void LedDriver_TurnOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
		return;
	}
		
	setLedImageBit(ledNumber);
	*ledsAddress = ledsImage;
}

static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~convertLedNumberToBit(ledNumber);
}

//Turn off a LED
void LedDriver_TurnOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
		return;
	}

	ledsImage &= ~convertLedNumberToBit(ledNumber);
	*ledsAddress = ledsImage;
}

bool LedDriver_IsOn(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return false;

	return ledsImage & (convertLedNumberToBit(ledNumber));
}

bool LedDriver_IsOff(int ledNumber)
{
	bool offResult = !LedDriver_IsOn(ledNumber);
	return offResult;
}