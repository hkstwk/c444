/*
 * main.h
 *
 *  Created on: 4 mrt. 2014
 *      Author: harm
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "draw.h"
#include "effect.h"
#include "launch_effect.h"


// Framebuffer
// Animations that take a lot of time to compute are temporarily
// stored to this array, then loaded into cube[8][8] when the image
// is ready to be displayed
//volatile unsigned char fb[CUBE_SIZE][CUBE_BYTES];

// Constant LAYER_SELECT is set to PORTD.
// Only first for bits of PORTD are used as layer pin
#define LAYER_SELECT PORTD

// BIT(x) is used to set the bit position
// Example to set a bit: PORTB |= BIT(0);
// Example to unset a bit: PORTB &= ~BIT(0);
#define BIT(x)	(1 << (x)) // bit position

#define F_CPU 16000000UL

void ioinit (void);
void test (void);
void setpins (void);

#endif /* MAIN_H_ */
