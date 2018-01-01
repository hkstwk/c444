/*
 * effect.h
 *
 *  Created on: 14 mrt. 2014
 *      Author: harm
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include <util/delay.h>
#include <math.h>
#include <stdlib.h>
#include "draw.h"

//extern unsigned char CUBE_SIZE;
//extern volatile unsigned char CUBE_BYTES;
extern volatile unsigned char cube[4][2];
extern volatile unsigned char fb[4][2];

void effect_test_all_voxels(int miliseconds, int ptime);
void effect_test_all_voxels_one_by_one(int miliseconds);
void effect_test (void);
void effect_all_leds_on(int miliseconds);
void effect_planboing (int plane, int miliseconds);
void effect_wireframe_box(int iterations, int miliseconds);
void effect_rain (int iterations);
void effect_sine(int iteration, int miliseconds);
void effect_sidewaves(int iteration, int miliseconds);
void effect_spheremove(int iteration, int miliseconds);
void effect_box_woopwoop (int delay, int grow);
void effect_sendvoxel_z (unsigned char x, unsigned char y, unsigned char z, int delay);
void effect_sendvoxels_rand_z (int iterations, int delay, int wait);
void effect_sendplane_rand_z (unsigned char z, int delay, int wait);
void effect_rotating_column(int iterations, int ms, int direction);
void effect_spinning(int iterations, int ms, int direction);
void effect_runningPlanes(int iterations, int ms, int direction);
void effect_sinewave(int iterations, int ms);

#endif /* EFFECT_H_ */
