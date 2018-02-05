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

#include "USART.h"

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

// Mode of operation: SERIAL_MODE or AVR_MODE
// Button on PD4 is used to switch between mode
volatile unsigned char mode;
volatile unsigned char last_mode;

// NEW functionality for button toggling between AVR and SERIAL mode
#define BUTTON_PORT	PORTD
#define BUTTON_DDR	DDRD
#define BUTTON		PD2
#define AVR_LED		PD5

void initButton(){
	BUTTON_DDR  &= ~(1 << BUTTON); // Set button pin to input by clearing the bit. Safety precaution
	BUTTON_PORT |=  (1 << BUTTON); // enable pull up resistor for button input pin
	BUTTON_DDR  |=  (1 << AVR_LED); // Set AVR_LED pin to OUTPUT by clearing the bit.
	BUTTON_PORT |=  (1 << AVR_LED);
}

void initInterrupt0(void){
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC00);
	sei();
}

ISR(INT0_vect){
	if (bit_is_clear(PIND,BUTTON)){
		BUTTON_PORT ^= (1 << AVR_LED);
		if (mode == AVR_MODE)
			mode = SERIAL_MODE;
		else
			mode = AVR_MODE;
	}
}


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
	initInterrupt0();
	initButton();

	// Serial Communication setup
	char serialCharacter;
	initUSART();
	printString("Hello world!\r\n");

	// Set Mode of Operation.
	mode = AVR_MODE;
	last_mode = SERIAL_MODE;

	// Do awesome effects. Loop forever.
	while (1)
	{
		if (mode == SERIAL_MODE){
			serialCharacter = receiveByte();
			printBinaryByte(serialCharacter);
		}

		else{ // Must be AVR_MODE
			//Show the effects in a predefined order
			for (int i=EFFECTS_TOTAL-1; i>=0; i--)
			{
				launch_effect(i);
			}
//			launch_effect(0);
		}
	}
	return 1;
}
