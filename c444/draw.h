/*
 * draw.h
 *
 *  Created on: 9 mrt. 2014
 *      Author: harm
 */

#ifndef DRAW_H_
#define DRAW_H_

#include <util/delay.h>
#include <math.h>

// Some effects can render on different axis
// for example send pixels along an axis
// for better readability, we use the following predefined constants
#define AXIS_X 0x78
#define AXIS_Y 0x79
#define AXIS_Z 0x7a

#define PLANE_Y0 0b00001111
#define PLANE_Y1 0b11110000
#define PLANE_Y2 0b00001111
#define PLANE_Y3 0b11110000


#define PLANE_X0 0b00010001
#define PLANE_X1 0b00100010
#define PLANE_X2 0b01000100
#define PLANE_X3 0b10001000

#define PI 3.14

extern unsigned char CUBE_SIZE;
extern unsigned char CUBE_BYTES;
extern volatile unsigned char cube[4][2];
extern volatile unsigned char fb[4][2];

void setvoxel(int x, int y, int z);
void clrvoxel(int x, int y, int z);
unsigned char inrange(int x, int y, int z);
void fill(unsigned char pattern);


// 9-feb-2014 Ready HKO
// Set a single voxel in the temporary cube buffer to ON
void tmpsetvoxel(int x, int y, int z);

// 9-feb-2014 Ready HKO
// Set a single voxel to OFF
void tmpclrvoxel(int x, int y, int z);

// Get the current status of a voxel
unsigned char getvoxel(int x, int y, int z);

// In some effect we want to just take bool and write it to a voxel
// this function calls the apropriate voxel manipulation function.
void altervoxel(int x, int y, int z, int state);

// Flip the state of a voxel.
// If the voxel is 1, its turned into a 0, and vice versa.
void flpvoxel(int x, int y, int z);

// Makes sure x1 is alwas smaller than x2
// This is usefull for functions that uses for loops,
// to avoid infinite loops
void argorder(int ix1, int ix2, int *ox1, int *ox2);

// 9-feb-2014 Ready HKO
// Sets all voxels along a X/Y plane at a given point
// on axis Z
void setplane_z (int z);

// 9-feb-2014 Ready HKO
// Clears voxels in the same manner as above
void clrplane_z (int z);

// 9-feb-2014 Ready HKO
void setplane_x (int x);

void clrplane_x (int x);

// 9-feb-2014 Ready HKO
void setplane_y (int y);


void clrplane_y (int y);

// 9-feb-2014 Ready HKO
void setplane (char axis, unsigned char i);

// 9-feb-2014 Ready HKO
void clrplane (char axis, unsigned char i);

// 9-feb-2014 Ready HKO
void tmpfill (unsigned char pattern);

// Draw a box with all walls drawn and all voxels inside set
void box_filled(int x1, int y1, int z1, int x2, int y2, int z2);

// Draw a hollow box with side walls.
void box_walls(int x1, int y1, int z1, int x2, int y2, int z2);

// 9-feb-2014 Ready HKO
// Draw a wireframe box. This only draws the corners and edges,
// no walls.
void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2);

// Returns a byte with a row of 1's drawn in it.
// byteline(2,5) gives 0b00111100
char byteline (int start, int end);

// Delay loop.
// This is not calibrated to milliseconds,
// but we had allready made to many effects using this
// calibration when we figured it might be a good idea
// to calibrate it.
void delay_ms(int x);

// Shift the entire contents of the cube along an axis
// This is great for effects where you want to draw something
// on one side of the cube and have it flow towards the other
// side. Like rain flowing down the Z axiz.
void shift (char axis, int direction);
void sinewave();
void ripples (int iterations, int delay);
void sidewaves (int iterations, int delay);
void spheremove (int iterations, int delay);
float distance2d (float x1, float y1, float x2, float y2);
float distance3d (float x1, float y1, float z1, float x2, float y2, float z2);
double map(double in, double inMin, double inMax, double outMin, double outMax);
void sine (int iterations, int delay);
void setColumn(int x, int y);
void clrColumn(int x, int y);

#endif /* DRAW_H_ */
