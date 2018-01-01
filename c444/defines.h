/*
 * defines.h
 *
 *  Created on: 27 dec. 2017
 *      Author: harm
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define F_CPU 16000000UL

// Delay constants
#define DELAY			50		// Delay within animations, milliseconds
#define DELAY_LOOP		1000		// Delay between two animations, milliseconds
#define DEBOUNCE_TIME	1000		// microseconds

#define CUBE_SIZE		4		// dimension of cube
#define EFFECTS_TOTAL	13		// number of animations

#define HIGH				0b0000111111111111		// 16 bits on
#define LOW				0x00		// 16 bits off
#define BIT(x)	(1 << (x)) 		// BIT(x) is used to set the bit position

#define LAYER_PORT	PORTB
#define LAYER_DDR	DDRB
#define LAYER0		PB0
#define LAYER1		PB1
#define LAYER2		PB2
#define LAYER3		PB3

#endif /* DEFINES_H_ */
