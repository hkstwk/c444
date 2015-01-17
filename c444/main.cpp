/*
 * main.cpp
 *
 *  Created on: 4 mrt. 2014
 *      Author: harm
 */

#include "main.h"


// Total number of effects to loop through in main()
int EFFECTS_TOTAL=13;
unsigned char HIGH = 0x00;
unsigned char LOW = 0xff;

// Variable indicating value of current layer
volatile unsigned char current_layer = 0;

// Some of the functions are created to be portable
// These functions will work on cubes of different sizes by
// changing this constant
//#define CUBE_SIZE 4
//#define CUBE_BYTES 2
unsigned char CUBE_SIZE = 4;
unsigned char CUBE_BYTES = 2;

// Cube buffer
// Data from this array is loaded onto the cube for each duty cycle
//volatile unsigned char cube[CUBE_SIZE][CUBE_BYTES];
volatile unsigned char cube[4][2];
volatile unsigned char fb[4][2];


// Main loop
int main (void)
{
	// This function initiates IO ports, timers and interrupts
	ioinit();

	// Do awesome effects. Loop forever.
	while (1)
	{
		// Show the effects in a predefined order
		for (int i=EFFECTS_TOTAL-1; i>=0; i--)
		{
			launch_effect(i);
		}
	}
	return 1;
}


void setpins()
{
	    // Set pins 4-20 for current layer
	    if (((cube[current_layer][0]) & (1 << 0)) != 0)
	    	PORTD |= BIT(4);
	    else
	    	PORTD &= ~BIT(4);

	    if (((cube[current_layer][0]) & (1 << 1)) != 0)
	    	PORTD |= BIT(5);
	    else
	    	PORTD &= ~BIT(5);

	    if (((cube[current_layer][0]) & (1 << 2)) != 0)
	    	PORTD |= BIT(6);
	    else
	    	PORTD &= ~BIT(6);

	    if (((cube[current_layer][0]) & (1 << 3)) != 0)
	    	PORTD |= BIT(7);
	    else
	    	PORTD &= ~BIT(7);

	    if (((cube[current_layer][0]) & (1 << 4)) != 0)
	    	PORTB |= BIT(0);
	    else
	    	PORTB &= ~BIT(0);

	    if (((cube[current_layer][0]) & (1 << 5)) != 0)
	    	PORTB |= BIT(1);
	    else
	    	PORTB &= ~BIT(1);

	    if (((cube[current_layer][0]) & (1 << 6)) != 0)
	    	PORTB |= BIT(2);
	    else
	    	PORTB &= ~BIT(2);

	    if (((cube[current_layer][0]) & (1 << 7)) != 0)
	    	PORTB |= BIT(3);
	    else
	    	PORTB &= ~BIT(3);

	    if (((cube[current_layer][1]) & (1 << 0)) != 0)
	    	PORTB |= BIT(4);
	    else
	    	PORTB &= ~BIT(4);

	    if (((cube[current_layer][1]) & (1 << 1)) != 0)
	    	PORTB |= BIT(5);
	    else
	    	PORTB &= ~BIT(5);

	    if (((cube[current_layer][1]) & (1 << 2)) != 0)
	    	PORTC |= BIT(0);
	    else
	    	PORTC &= ~BIT(0);

	    if (((cube[current_layer][1]) & (1 << 3)) != 0)
	    	PORTC |= BIT(1);
	    else
	    	PORTC &= ~BIT(1);

	    if (((cube[current_layer][1]) & (1 << 4)) != 0)
	    	PORTC |= BIT(2);
	    else
	    	PORTC &= ~BIT(2);

	    if (((cube[current_layer][1]) & (1 << 5)) != 0)
	    	PORTC |= BIT(3);
	    else
	    	PORTC &= ~BIT(3);

	    if (((cube[current_layer][1]) & (1 << 6)) != 0)
	    	PORTC |= BIT(4);
	    else
	    	PORTC &= ~BIT(4);

	    if (((cube[current_layer][1]) & (1 << 7)) != 0)
	    	PORTC |= BIT(5);
	    else
	    	PORTC &= ~BIT(5);

}

ISR(TIMER1_COMPA_vect)
{
	// all layers off
    for (int i=0; i<4; i++)
    {
      LAYER_SELECT |= (1 << i); // set the bit of current layer (inactive high!)
    }

    // call function setpins() to set/unset the relevant pins
    setpins();

    // Activate current_layer by pulling the pin low (clearing the bit)
    LAYER_SELECT &= ~(1 << current_layer);

 	// Increment the current_layer counter so that the next layer is
    // drawn the next time this function runs.
    current_layer++;

    // We want to count from 0-3, so set it to 0 when it reaches 4.
    if (current_layer == 4)
    	current_layer = 0;
}

void ioinit()
{
	// Set all ports to output and pull all pins low.
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
	PORTB = 0x00; // all pins low
	PORTC = 0x00; // all pins low
	PORTD = 0x00; // all pins low. PORTD0 to PORTD3 are layer pins. They are pulled high (off) at end of ioinit()

	// Set timer 1 at 1.3kHz as frame buffer interrupt
	// using 256 prescaler and arduino clock frequency of 1.6MHz
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0;
	TCNT1 = 0;  // initialize counter to 0
	OCR1A = 47; // compare match register = ((16*10^6) / (256*1300)) - 1 (must be <65536)
	//OCR1A = 16384; // somewhat slower, so you can see the effect. Uncomment this one, and comment the line above.

	// Turn on CTC mode
	TCCR1B |= (1 << WGM12);

	// Set CS12 bit for 256 prescaler
	TCCR1B |= (1 << CS12);

	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	//
	sei();

	// Set all layer pins HIGH expect layer 0 (top layer)
	PORTD |= (1 << 0) | (1 << 1)| (1 << 2) | (1 << 3) ; // pull pins  1 -  3 high (layers off)

	// Setup led pins as output and pull high (on)
	fill(HIGH);
}


