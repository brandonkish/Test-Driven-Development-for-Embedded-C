#pragma once

#include <stdint.h>
#include <stdbool.h>

extern void LedDriver_Create ( uint16_t * address );
extern void LedDriver_Destroy ( void );
void LedDriver_TurnOn ( int ledNumber );
void LedDriver_TurnOff ( int ledNumber );
void LedDriver_TurnAllOn ( void );
void LedDriver_TurnAllOff ( void );
bool LedDriver_IsOn(int ledNumber);
bool LedDriver_IsOff(int ledNumber);