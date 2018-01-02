/*
 * main.cpp
 *
 *  Created on: 4 mrt. 2014
 *      Author: harm
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "shift_register.h"
#include "timer.h"
#include "defines.h"
#include "init.h"

#include "draw.h"
#include "effect.h"
#include "launch_effect.h"

// 16-bits storage for anode side of the leds. I use a two byte unsigned integer type to do the job
volatile uint16_t ledPins;
volatile uint16_t previousLedPins;
volatile uint8_t currentLayer;

// Cube buffer
// Data from this array is loaded onto the cube for each duty cycle
//volatile unsigned char cube[CUBE_SIZE][CUBE_BYTES];
volatile unsigned char CUBE_BYTES;
volatile unsigned char cube[4][2];
volatile unsigned char fb[4][2];
volatile uint16_t cube444[4];


// Main loop
int main (void)
{
    LAYER_DDR |= (1 << LAYER0) | (1 << LAYER1) | (1 << LAYER2) | (1 << LAYER3);

    previousLedPins = 0xAB;

    // initialize layer 0; other layers off.
    currentLayer = 0;
    LAYER_PORT = (1 << currentLayer);

	// This function initiates IO ports, timers and interrupts
	ioinit();
	initTimer1();

	// Do awesome effects. Loop forever.
	while (1)
	{
		fill(LOW);
		// Show the effects in a predefined order
		for (int i=EFFECTS_TOTAL-1; i>=0; i--)
		{
			launch_effect(i);
		}
//		launch_effect(4);
	}
	return 1;
}
