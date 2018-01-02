/*
 * launch_effect.cpp
 *
 *  Created on: 14 mrt. 2014
 *      Author: harm
 */

#include "defines.h"
#include "launch_effect.h"

void launch_effect (int effect)
{
  int i;

  fill(LOW);

  switch (effect)
  {
    // plane boing effect
    case 0:
      effect_sine(75,125);
      fill(LOW);
      delay_ms(250);
      break;

    case 1:
      for (i=0; i<6; i++)
      {
        effect_planboing (AXIS_Z, 100);
        transposePlane(TRANSPOSE_Z0X0, 100);
        effect_planboing (AXIS_X, 100);
        transposePlane(TRANSPOSE_X0Y0, 100);
        effect_planboing (AXIS_Y, 100);
        transposePlane(TRANSPOSE_Y0Z0, 100);
      }
      fill(LOW);
      delay_ms(250);
      break;

    // light all leds one by one
    case 2:
      effect_test_all_voxels(20,2000);
      delay_ms(250);
      fill(LOW);
      break;

    case 3:
      effect_all_leds_on(3000);
      fill(LOW);
      delay_ms(250);
      break;

    case 4:
      effect_wireframe_box(100,100);
      delay_ms(500);
      for (int i=0; i<3; i++)
      {
		  effect_box_woopwoop(175,0);
		  effect_box_woopwoop(175,1);
		  effect_box_woopwoop(175,0);
		  effect_box_woopwoop(175,1);
      }
      delay_ms(250);
      fill(LOW);
      break;

    case 5:
      effect_sendvoxels_rand_z(100,25,150); // parameters: (int iterations, int delay, int wait)
      fill(LOW);
      delay_ms(250);
      break;

    case 6:
      effect_rain(200);
      fill(LOW);
      delay_ms(250);
      break;

    case 7:
  	  effect_sendplane_rand_z(3,35,50); // parameters:  (unsigned char z, int delay, int wait)
      fill(LOW);
      delay_ms(250);
      break;

   case 8:
	  for (int i=0;i<10;i++){
		  effect_rotating_column(1,60,COUNTERCLOCKWISE);
		  effect_rotating_column(1,60,CLOCKWISE);
	  }
      fill(LOW);
      delay_ms(250);
      break;

   case 9:
	  effect_spinning(20,80,CLOCKWISE);
      fill(LOW);
      delay_ms(250);
      effect_spinning(20,80,COUNTERCLOCKWISE);
      fill(LOW);
      delay_ms(250);
      break;

   case 10:
	  effect_runningPlanes(10,140,rand()%2);
      fill(LOW);
      delay_ms(250);
      break;

   case 11:
	  effect_sidewaves(2500,10);
      fill(LOW);
      delay_ms(250);
      break;

   case 12:
	  effect_sinewave(100,120);
      fill(LOW);
      delay_ms(250);
      break;

    // In case the effect number is out of range do nothing
    default:
  	  effect_planboing(AXIS_X,100);
      fill(LOW);
      delay_ms(100);
      transposePlane(TRANSPOSE_X0Y0,500);
      break;
  }
}


