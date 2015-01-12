/*
 * draw.cpp
 *
 *  Created on: 9 mrt. 2014
 *      Author: harm
 */

#include "draw.h"

volatile unsigned char yplanes[] = { PLANE_Y0, PLANE_Y1, PLANE_Y2, PLANE_Y3 };
volatile unsigned char xplanes[] = { PLANE_X0, PLANE_X1, PLANE_X2, PLANE_X3 };

int spinArray[6][2] = {
	0b00100001,
	0b10000100,
	0b00100010,
	0b01000100,
	0b01000100,
	0b00100010,
	0b01001000,
	0b00010010,
	0b11000000,
	0b00000011,
	0b00110000,
	0b00001100
};

// draw.cpp
// 9-feb-2014 Ready HKO
// Set a single voxel to ON
void setvoxel(int x, int y, int z)
{
	if (inrange(x,y,z))
        {
          switch (y)
          {
            case 0:
		cube[z][0] |= (1 << x);
                break;

            case 1:
		cube[z][0] |= (1 << (x+4));
                break;

            case 2:
        cube[z][1] |= (1 << x);
                break;

            case 3:
		cube[z][1] |= (1 << (x+4));
                break;

            default:
                break;
          }
        }
}

// 9-feb-2014 Ready HKO
// Fill a value into all 64 byts of the cube buffer
// Mostly used for clearing: fill(0x00)
// or setting all on: fill(0xff)
void fill (unsigned char pattern)
{
	for (int z=0;z<CUBE_SIZE;z++)
	{
		for (int y=0;y<CUBE_BYTES;y++)
		{
			cube[z][y] = pattern;
		}
	}
}

// 9-feb-2014 Ready HKO
// Set a single voxel to OFF
void clrvoxel(int x, int y, int z)
{
	if (inrange(x,y,z))
        {
          switch (y)
          {
            case 0:
		cube[z][0] &= ~(1 << x);
                break;

            case 1:
		cube[z][0] &= ~(1 << (x+4));
                break;

            case 2:
                cube[z][1] &= ~(1 << x);
                break;

            case 3:
		cube[z][1] &= ~(1 << (x+4));
                break;

            default:
                break;
          }
        }
}

// 9-feb-2014 Ready HKO
// This function validates that we are drawing inside the cube.
unsigned char inrange(int x, int y, int z)
{
	if (x >= 0 && x < CUBE_SIZE && y >= 0 && y < CUBE_SIZE && z >= 0 && z < CUBE_SIZE)
	{
		return 1;
	} else
	{
		// One of the coordinates was outside the cube.
		return 0;
	}
}

// 9-feb-2014 Ready HKO
// Set a single voxel in the temporary cube buffer to ON
void tmpsetvoxel(int x, int y, int z)
{
	if (inrange(x,y,z))
	{
		switch (y)
		{
		case 0:
			cube[z][0] |= (1 << x);
			break;

		case 1:
			cube[z][0] |= (1 << (x+4));
			break;

		case 2:
			cube[z][1] |= (1 << x);
			break;

		case 3:
			cube[z][1] |= (1 << (x+4));
			break;

		default:
			break;
		}
	}
}


// 9-feb-2014 Ready HKO
// Set a single voxel to OFF
void tmpclrvoxel(int x, int y, int z)
{
	if (inrange(x,y,z))
        {
          switch (y)
          {
            case 0:
		cube[z][0] &= ~(1 << x);
                break;

            case 1:
		cube[z][0] &= ~(1 << (x+4));
                break;

            case 2:
                cube[z][1] &= ~(1 << x);
                break;

            case 3:
		cube[z][1] &= ~(1 << (x+4));
                break;

            default:
                break;
          }
        }
}


// Get the current status of a voxel
unsigned char getvoxel(int x, int y, int z)
{
	if (inrange(x,y,z))
	{
        switch (y)
        {
          case 0:
      		if (cube[z][0] & (1 << x))
      		{
      			return 1;
      		} else
      		{
      			return 0;
      		}
            break;

          case 1:
			if (cube[z][0] & (1 << (x+4)))
			{
				return 1;
			} else
			{
				return 0;
			}
			break;

          case 2:
      		if (cube[z][1] & (1 << x))
      		{
      			return 1;
      		} else
      		{
      			return 0;
      		}
            break;

          case 3:
			if (cube[z][1] & (1 << (x+4)))
			{
				return 1;
			} else
			{
				return 0;
			}
			break;

          default:
        	  return 0;
              break;
        }
	}
	return 0;
}

// In some effect we want to just take bool and write it to a voxel
// this function calls the apropriate voxel manipulation function.
void altervoxel(int x, int y, int z, int state)
{
	if (state == 1)
	{
		setvoxel(x,y,z);
	} else
	{
		clrvoxel(x,y,z);
	}
}

// Flip the state of a voxel.
// If the voxel is 1, its turned into a 0, and vice versa.
void flpvoxel(int x, int y, int z)
{
	if (inrange(x, y, z))
		cube[z][y] ^= (1 << x);
}

// Makes sure x1 is alwas smaller than x2
// This is useful for functions that uses for loops,
// to avoid infinite loops
void argorder(int ix1, int ix2, int *ox1, int *ox2)
{
	if (ix1>ix2)
	{
		int tmp;
		tmp = ix1;
		ix1= ix2;
		ix2 = tmp;
	}
	*ox1 = ix1;
	*ox2 = ix2;
}

// 9-feb-2014 Ready HKO
// Sets all voxels along a X/Y plane at a given point
// on axis Z
void setplane_z (int z)
{
	int i;
	if (z>=0 && z<CUBE_SIZE)
	{
		for (i=0;i<CUBE_BYTES;i++)
			cube[z][i] = 0xff;
	}
}

// 9-feb-2014 Ready HKO
// Clears voxels in the same manner as above
void clrplane_z (int z)
{
	int i;
	if (z>=0 && z<CUBE_SIZE)
	{
		for (i=0;i<CUBE_BYTES;i++)
			cube[z][i] = 0x00;
	}
}

// 9-feb-2014 Ready HKO
void setplane_x (int x)
{
	int z;

	if (x>=0 && x<CUBE_SIZE)
	{
		for (z=0;z<CUBE_SIZE;z++)
		{
                  cube[z][0] = xplanes[x];
                  cube[z][1] = xplanes[x];
		}
	}
}

void clrplane_x (int x)
{

}

// 9-feb-2014 Ready HKO
void setplane_y (int y)
{
	int z;
        unsigned char bytetmp;
        if ((y == 0) || (y == 1)) bytetmp=0;
        if ((y == 2) || (y == 3)) bytetmp=1;

        if (y>=0 && y<CUBE_SIZE)
	{
            for (z=0;z<CUBE_SIZE;z++)
            {
                cube[z][bytetmp]=yplanes[y];

            }
        }
}


void clrplane_y (int y)
{

}

// 9-feb-2014 Ready HKO
void setplane (char axis, unsigned char i)
{
    switch (axis)
    {
        case AXIS_X:
            setplane_x(i);
            break;

       case AXIS_Y:
            setplane_y(i);
            break;

       case AXIS_Z:
            setplane_z(i);
            break;
    }
}

// 9-feb-2014 Ready HKO
void clrplane (char axis, unsigned char i)
{
    switch (axis)
    {
        case AXIS_X:
            clrplane_x(i);
            break;

       case AXIS_Y:
            clrplane_y(i);
            break;

       case AXIS_Z:
            clrplane_z(i);
            break;
    }
}


// 9-feb-2014 Ready HKO
void tmpfill (unsigned char pattern)
{
	int z;
	int y;
	for (z=0;z<CUBE_SIZE;z++)
	{
		for (y=0;y<CUBE_SIZE;y++)
		{
			fb[z][y] = pattern;
		}
	}
}

// Draw a box with all walls drawn and all voxels inside set
void box_filled(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int iy;
	int iz;

	argorder(x1, x2, &x1, &x2);
	argorder(y1, y2, &y1, &y2);
	argorder(z1, z2, &z1, &z2);

	for (iz=z1;iz<=z2;iz++)
	{
		for (iy=y1;iy<=y2;iy++)
		{
			cube[iz][iy] |= byteline(x1,x2);
		}
	}

}

// Draw a hollow box with side walls.
void box_walls(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int iy;
	int iz;

	argorder(x1, x2, &x1, &x2);
	argorder(y1, y2, &y1, &y2);
	argorder(z1, z2, &z1, &z2);

	for (iz=z1;iz<=z2;iz++)
	{
		for (iy=y1;iy<=y2;iy++)
		{
			if (iy == y1 || iy == y2 || iz == z1 || iz == z2)
			{
				cube[iz][iy] = byteline(x1,x2);
			} else
			{
				cube[iz][iy] |= ((0x01 << x1) | (0x01 << x2));
			}
		}
	}

}

// 9-feb-2014 Ready HKO
// Draw a wireframe box. This only draws the corners and edges,
// no walls.
void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int ix;
        int iy;
	int iz;

	argorder(x1, x2, &x1, &x2);
	argorder(y1, y2, &y1, &y2);
	argorder(z1, z2, &z1, &z2);

	// Lines along X axis
        for (ix=x1;ix<=x2;ix++)
        {
		setvoxel(ix,y1,z1);
		setvoxel(ix,y1,z2);
		setvoxel(ix,y2,z1);
		setvoxel(ix,y2,z2);
        }



	// Lines along Y axis
	for (iy=y1;iy<=y2;iy++)
	{
		setvoxel(x1,iy,z1);
		setvoxel(x1,iy,z2);
		setvoxel(x2,iy,z1);
		setvoxel(x2,iy,z2);
	}

	// Lines along Z axis
	for (iz=z1;iz<=z2;iz++)
	{
		setvoxel(x1,y1,iz);
		setvoxel(x1,y2,iz);
		setvoxel(x2,y1,iz);
		setvoxel(x2,y2,iz);
	}

}

// Returns a byte with a row of 1's drawn in it.
// byteline(2,5) gives 0b00111100
char byteline (int start, int end)
{
	return ((0xff<<start) & ~(0xff<<(end+1)));
}


// Draw a line between any coordinates in 3d space.
// Uses integer values for input, so dont expect smooth animations.
void line(int x1, int y1, int z1, int x2, int y2, int z2)
{
	float xy;	// how many voxels do we move on the y axis for each step on the x axis
	float xz;	// how many voxels do we move on the y axis for each step on the x axis
	unsigned char x,y,z;
	unsigned char lasty, lastz;

	// We always want to draw the line from x=0 to x=7.
	// If x1 is bigget than x2, we need to flip all the values.
	if (x1>x2)
	{
		int tmp;
		tmp = x2; x2 = x1; x1 = tmp;
		tmp = y2; y2 = y1; y1 = tmp;
		tmp = z2; z2 = z1; z1 = tmp;
	}


	if (y1>y2)
	{
		xy = (float)(y1-y2)/(float)(x2-x1);
		lasty = y2;
	} else
	{
		xy = (float)(y2-y1)/(float)(x2-x1);
		lasty = y1;
	}

	if (z1>z2)
	{
		xz = (float)(z1-z2)/(float)(x2-x1);
		lastz = z2;
	} else
	{
		xz = (float)(z2-z1)/(float)(x2-x1);
		lastz = z1;
	}



	// For each step of x, y increments by:
	for (x = x1; x<=x2;x++)
	{
		y = (xy*(x-x1))+y1;
		z = (xz*(x-x1))+z1;
		setvoxel(x,y,z);
	}

}

// Delay loop. Since _delay_ms() only accepts constants, I needed a workaround
// http://www.avrfreaks.net/forum/delayms-arggument-solved
// Found this approach there, accepting int parameter (delay in ms)
// then looping x times and delay by 1ms each iteration.
void delay_ms(int x)
{
	while (x > 0){
		_delay_ms(1);
		x--;
	}
}

// Shift the entire contents of the cube along an axis
// This is great for effects where you want to draw something
// on one side of the cube and have it flow towards the other
// side. Like rain flowing down the Z axiz.
void shift (char axis, int direction)
{
	int i, x ,y;
	int ii, iii;
	int state;

	for (i = 0; i < CUBE_SIZE; i++)
	{
		if (direction == -1)
		{
			ii = i;
		} else
		{
			ii = (3-i);
		}


		for (x = 0; x < CUBE_SIZE; x++)
		{
			for (y = 0; y < CUBE_SIZE; y++)
			{
				if (direction == -1)
				{
					iii = ii+1;
				} else
				{
					iii = ii-1;
				}

				if (axis == AXIS_Z)
				{
					state = getvoxel(x,y,iii);
					altervoxel(x,y,ii,state);
				}

				if (axis == AXIS_Y)
				{
					state = getvoxel(x,iii,y);
					altervoxel(x,ii,y,state);
				}

				if (axis == AXIS_X)
				{
					state = getvoxel(iii,y,x);
					altervoxel(ii,y,x,state);
				}
			}
		}
	}

	if (direction == -1)
	{
		i = 3;
	} else
	{
		i = 0;
	}

	for (x = 0; x < CUBE_SIZE; x++)
	{
		for (y = 0; y < CUBE_SIZE; y++)
		{
			if (axis == AXIS_Z)
				clrvoxel(x,y,i);

			if (axis == AXIS_Y)
				clrvoxel(x,i,y);

			if (axis == AXIS_X)
				clrvoxel(i,y,x);
		}
	}
}

void sinewave(){

  int i, x, y, z;
  double distance;
  double cx = 1.5;
  double cy = 1.5;
  double a; // distance between x and cx
  double b; // distance between y and cy

  for (i=0; i<4; i++)
    {
      for (x=0; x<CUBE_SIZE; x++)
      {
        a = cx - x;

        for (y=0; y<CUBE_SIZE; y++)
        {
          b = cy - y;
          distance = sqrt((a * a) + (b * b));

          z = sin(distance) + i;
          setvoxel(x,y,z);
          delay_ms(20);
        }
      }
    }
}

// Based on http://www.hownottoengineer.com/projects/lc.html
// Display a sine wave running out from the center of the cube.
void sine(int iterations, int delay) {

	float z;
	int x,y,phase;

	fill(0x00);  // Clear cube

	for (phase = 0; phase < iterations; phase++)
	{
		for (x = 0; x < 4; x++)
		{
		  for (y = 0; y < 4; y++)
		  {
			  z = sin(phase+ sqrt(pow(map(x,0,CUBE_SIZE-1,-PI,PI),2) + pow(map(y,0,CUBE_SIZE-1,-PI,PI),2)));
			  z = round(map(z,-1,1,0,CUBE_SIZE-1));
			  setvoxel(x,y,(int) z);
		  }
		}
		delay_ms(delay);
		fill(0x00);  // Clear cube
	}
}


// Display a sine wave running out from the center of the cube.
void ripples (int iterations, int delay) {
	fill(0x00);  // Clear cube

	float distance, height, ripple_interval;
	int x,y,i;

	for (i = 0; i < iterations; i++) {
	for (x = 0; x < 4; x++) {
	  for (y = 0; y < 4; y++) {
		//distance = distance2d(3.5,3.5,x,y)/4.9*4;
		distance = distance2d(1.5,1.5,x,y)/4.9*4;
		ripple_interval = 2;//=1.2;
		//height = sin(distance/ripple_interval+(float) i/200)*4;
	        height = sin(distance/ripple_interval)+(float) i/500;

		setvoxel(x,y,(int) height);
	  }
	}
	//delay_ms(delay);
	fill(0x00);  // Clear cube
	}
}

void sidewaves (int iterations, int delay) {
	float origin_x, origin_y, distance, height, ripple_interval;
	  int x,y,i;

	  for (i = 0; i < iterations; i++) {
	    origin_x = 3.5+sin((float)i/500)*4;
	    origin_y = 3.5+cos((float)i/500)*4;

	    for (x = 0; x < 4; x++) {
	      for (y = 0; y < 4; y++) {
	        distance = distance2d(origin_x,origin_y,x,y)/9.899495*8;
	        ripple_interval =2;
	        height = 4+sin(distance/ripple_interval+(float) i/50)*3.6;

	        setvoxel(x,y,(int) height);
	        setvoxel(x,y,(int) height);
	      }
	    }

	    delay_ms(delay);
	    fill(0x00);
	  }
}

void spheremove (int iterations, int delay) {
  fill(0x00);  // Clear cube

  float origin_x, origin_y, origin_z, distance, diameter;

  origin_x = 0;
  origin_y = 1.5;
  origin_z = 1.5;

  diameter = 3;

  int x, y, z, i;

  for (i=0; i<iterations; i++) {
    origin_x = 1.75+sin((float)i/50)*2.5;
    origin_y = 1.75+cos((float)i/50)*2.5;
    origin_z = 1.75+cos((float)i/30)*2;

    diameter = 2+sin((float)i/150);

    for (x = 0; x < 4; x++) {
      for (y = 0; y < 4; y++) {
        for (z = 0; z < 4; z++) {
          distance = distance3d(x,y,z, origin_x, origin_y, origin_z);

          if (distance > diameter && distance < diameter+1)
            setvoxel(x,y,z);
        }
      }
    }

    delay_ms(delay);
    fill(0x00);
  }
}

float distance2d (float x1, float y1, float x2, float y2) {
  float dist;
  dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

  return dist;
}

float distance3d (float x1, float y1, float z1, float x2, float y2, float z2) {
  float dist;
  dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

  return dist;
}


double map(double in, double inMin, double inMax, double outMin, double outMax)
{
	double out;
	out = (in-inMin)/(inMax-inMin)*(outMax-outMin) + outMin;
	return out;
}

void setColumn(int x, int y)
{
	for (int z=0; z <= 3; z++)
	{
		setvoxel(x,y,z);
	}

}

void clrColumn(int x, int y)
{
	for (int z=0; z <= 3; z++)
	{
		clrvoxel(x,y,z);
	}

}

void setDiagonal (int stepcount)
{
	for (int z=0;z<CUBE_SIZE;z++)
	{
		cube[z][0] = spinArray[stepcount][0];
		cube[z][1] = spinArray[stepcount][1];
	}
}

