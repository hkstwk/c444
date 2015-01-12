/*
 * effect.cpp
 *
 *  Created on: 14 mrt. 2014
 *      Author: harm
 */

#include "effect.h"


// Test all voxels by turning on one after the other in ascending order.
// Wait a little when all are lit...
// and then turning them all off in descending order.
void effect_test_all_voxels(int miliseconds, int ptime)
{
	for (int z=3; z>=0; z--)
	{
		for (int x=0; x<4; x++)
		{
			for (int y=0; y<4; y++)
			{
				setvoxel(x,y,z);
				delay_ms(miliseconds);
			}
		}
	}
	delay_ms(ptime);
	for (int z=0; z<4; z++)
	{
		for (int x=3; x>=0; x--)
		{
			for (int y=3; y>=0; y--)
			{
				clrvoxel(x,y,z);
				delay_ms(miliseconds);
			}
		}
	}
	delay_ms(ptime);
}

// Creates a wireframe box that shrinks or grows out from the center of the cube.
void effect_box_woopwoop (int delay, int grow)
{
	int i,ii;

	fill(0x00);
	for (i=0;i<2;i++)
	{
        ii = i;
        if (grow > 0)
            ii = 1-i;

		box_wireframe(2+ii,2+ii,2+ii,1-ii,1-ii,1-ii);
		delay_ms(delay);
		fill(0x00);
	}
}

// Draw a plane on one axis and send it back and forth once.
void effect_planboing (int plane, int miliseconds)
{
  int i;
  for (i=0;i<CUBE_SIZE;i++)
  {
    fill(0x00);
    setplane(plane, i);
    delay_ms(miliseconds);
  }

  for (i=CUBE_SIZE-1;i>=0;i--)
  {
   fill(0x00);
   setplane(plane,i);
   delay_ms(miliseconds);
  }
}

// Test all voxesl one by one
void effect_test_all_voxels_one_by_one(int miliseconds)
{
  for (int z=0; z<CUBE_SIZE; z++)
    for (int y=0; y<CUBE_SIZE; y++)
      for (int x=0; x<CUBE_SIZE; x++)
      {
        setvoxel(x,y,z);
        delay_ms(miliseconds);
        clrvoxel(x,y,z);
      }
}
// Light all leds and delay for some time
void effect_all_leds_on(int miliseconds)
{
    fill(0xff);
    delay_ms(miliseconds);
}

// Wireframebox whoop whoop
void effect_wireframe_box(int iterations, int miliseconds)
{
    // Full box downn to origin (0,0,0)
    box_wireframe(0,0,0,3,3,3);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,2,2,2);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,1,1,1);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,0,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,1,1,1);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,2,2,2);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,0,3,3,3);
    delay_ms(miliseconds);
    fill(0x00);

    // Full box downn to (x,y,z) = (3,0,0)
    box_wireframe(0,3,3,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,2,2,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,1,1,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(3,0,0,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,1,1,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,2,2,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,3,3,3,0,0);
    delay_ms(miliseconds);
    fill(0x00);

    // Full box downn to (x,y,z) = (3,3,0)
    box_wireframe(0,0,3,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,1,2,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,2,1,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(3,3,0,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,2,1,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,1,2,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,0,3,3,3,0);
    delay_ms(miliseconds);
    fill(0x00);

    // Full box downn to (x,y,z) = (0,3,0)
    box_wireframe(3,0,3,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,1,2,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,2,1,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(0,3,0,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(1,2,1,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(2,1,2,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
    box_wireframe(3,0,3,0,3,0);
    delay_ms(miliseconds);
    fill(0x00);
}

void effect_rain (int iterations)
{
	int i, ii;
	int rnd_x;
	int rnd_y;
	int rnd_num;

	for (ii=0;ii<iterations;ii++)
	{
		rnd_num = rand()%4;

		for (i=0; i < rnd_num;i++)
		{
			rnd_x = rand()%4;
			rnd_y = rand()%4;
			setvoxel(rnd_x,rnd_y,0);
		}

		delay_ms(100);
		shift(AXIS_Z, 1);
	}
}

void effect_test (void)
{

	int x,y,z,i;

	for (i=0;i<1000;i++)
	{
		x = sin(i/4)*2+2;
		y = cos(i/4)*2+2;
                z = tan(i/4)*2+2;

		setvoxel(x,y,z);
		setvoxel(x,y,z);
		delay_ms(200);
		fill(0x00);
	}

}

void effect_sine(int iteration, int miliseconds)
{
    sine(iteration,miliseconds);
}

void effect_sidewaves(int iteration, int miliseconds)
{
    sidewaves(iteration,miliseconds);
}

void effect_spheremove(int iteration, int miliseconds)
{
    //spheremove(iteration,miliseconds);
}

// Send a voxel flying from one side of the cube to the other
// If its at the bottom, send it to the top..
void effect_sendvoxel_z (unsigned char x, unsigned char y, unsigned char z, int delay)
{
	int i, ii;
	for (i=0; i<4; i++)
	{
		if (z == 3)
		{
			ii = 3-i;
			clrvoxel(x,y,ii+1);
		} else
		{
			ii = i;
			clrvoxel(x,y,ii-1);
		}
		setvoxel(x,y,ii);
		delay_ms(delay);
	}
}

// For each coordinate along X and Y, a voxel is set either at level 0 or at level 7
// for n iterations, a random voxel is sent to the opposite side of where it was.
void effect_sendvoxels_rand_z (int iterations, int delay, int wait)
{
	unsigned char x, y, last_x = 0, last_y = 0, i;

	fill(0x00);

	// Loop through all the X and Y coordinates
	for (x=0;x<4;x++)
	{
		for (y=0;y<4;y++)
		{
			// Then set a voxel either at the top or at the bottom
            // rand()%2 returns either 0 or 1. multiplying by 7 gives either 0 or 7.
            setvoxel(x,y,((rand()%2)*3));
		}
	}

	for (i=0;i<iterations;i++)
	{
		// Pick a random x,y position
		x = rand()%4;
		y = rand()%4;
		// but not the sameone twice in a row
		if (y != last_y && x != last_x)
		{
			// If the voxel at this x,y is at the bottom
			if (getvoxel(x,y,0))
			{
				// send it to the top
				effect_sendvoxel_z(x,y,0,delay);
			} else
			{
				// if its at the top, send it to the bottom
				effect_sendvoxel_z(x,y,3,delay);
			}
			delay_ms(wait);

			// Remember the last move
			last_y = y;
			last_x = x;
		}
	}

}

// Send all the voxels from one side of the cube to the other
// Start at z and send to the opposite side.
// Sends in random order.
void effect_sendplane_rand_z (unsigned char z, int delay, int wait)
{
	unsigned char loop = 16;
	unsigned char x, y;

	fill(0x00);

	setplane_z(z);

	// Send voxels at random untill all 16 have crossed the cube.
	while(loop)
	{
		x = rand()%4;
		y = rand()%4;
		if (getvoxel(x,y,z))
		{
			// Send the voxel flying
			effect_sendvoxel_z(x,y,z,delay);
			delay_ms(wait);
			loop--; // one down, loop-- to go. when this hits 0, the loop exits.
		}
	}
	delay_ms(1000);
}

void effect_rotating_column(int iterations, int ms, int direction)
{
	if (direction == CLOCKWISE) {
		while (iterations--){
				for (int x=0; x<CUBE_SIZE; x++){
						setColumn(x,0);
						delay_ms(ms);
						clrColumn(x,0);
				}
				for (int y=1; y<CUBE_SIZE; y++){
					setColumn(3,y);
					delay_ms(ms);
					clrColumn(3,y);
				}
				for (int x=CUBE_SIZE-2; x>=0; x--){
					setColumn(x,3);
					delay_ms(ms);
					clrColumn(x,3);
				}
				for (int y=CUBE_SIZE-2; y>0; y--){
					setColumn(0,y);
					delay_ms(ms);
					clrColumn(0,y);
				}
		}
	}
	else if (direction == COUNTERCLOCKWISE){
		while (iterations--){
				for (int y=0; y<CUBE_SIZE; y++){
						setColumn(0,y);
						delay_ms(ms);
						clrColumn(0,y);
				}
				for (int x=1; x<CUBE_SIZE; x++){
					setColumn(x,3);
					delay_ms(ms);
					clrColumn(x,3);
				}
				for (int y=CUBE_SIZE-2; y>=0; y--){
					setColumn(3,y);
					delay_ms(ms);
					clrColumn(3,y);
				}
				for (int x=CUBE_SIZE-2; x>0; x--){
					setColumn(x,0);
					delay_ms(ms);
					clrColumn(x,0);
				}
		}
	}
}

void effect_spinning(int iterations, int ms, int direction){
	while (iterations--){
		for (int i=0; i<6; i++){
			fill(0x00);
			if (direction == CLOCKWISE){
				setDiagonal(i);
			}
			else if (direction == COUNTERCLOCKWISE){
				setDiagonal(5-i);
			}
			delay_ms(ms);
		}
	}
}

void effect_runningPlanes(int iterations, int ms, int direction){
	while (iterations--){
		setplane(AXIS_X,0);
		delay_ms(ms);
		fill(0x00);

		if (direction == CLOCKWISE){
			setplane(AXIS_Y,0);
		}
		else if (direction == COUNTERCLOCKWISE){
			setplane(AXIS_Y,3);
		}
		delay_ms(ms);
		fill(0x00);

		setplane(AXIS_X,3);
		delay_ms(ms);
		fill(0x00);

		if (direction == CLOCKWISE){
			setplane(AXIS_Y,3);
		}
		else if (direction == COUNTERCLOCKWISE){
			setplane(AXIS_Y,0);
		}
		delay_ms(ms);
		fill(0x00);
	}
}
