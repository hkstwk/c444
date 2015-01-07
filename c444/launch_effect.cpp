/*
 * launch_effect.cpp
 *
 *  Created on: 14 mrt. 2014
 *      Author: harm
 */


#include "launch_effect.h"

void launch_effect (int effect)
{
  int i;

  fill(0x00);

  switch (effect)
  {
    // plane boing effect
    case 0:
      effect_sine(75,150);
      fill(0x00);
      break;

    case 1:
      for (i=0; i<2; i++)
      {
        effect_planboing (AXIS_Z, 100);
        effect_planboing (AXIS_Z, 100);
        effect_planboing (AXIS_Z, 100);
        effect_planboing (AXIS_X, 100);
        effect_planboing (AXIS_X, 100);
        effect_planboing (AXIS_X, 100);
        effect_planboing (AXIS_Y, 100);
        effect_planboing (AXIS_Y, 100);
        effect_planboing (AXIS_Y, 100);
      }
      fill(0x00);
      break;

    // light all leds one by one
    case 2:
      effect_test_all_voxels(20,2000);
      fill(0x00);
      break;

    case 3:
      effect_all_leds_on(3000);
      fill(0x00);
      break;

    case 4:
      effect_wireframe_box(100,150);
      delay_ms(500);
      for (int i=0; i<3; i++)
      {
		  effect_box_woopwoop(200,0);
		  effect_box_woopwoop(200,1);
		  effect_box_woopwoop(200,0);
		  effect_box_woopwoop(200,1);
      }
      fill(0x00);
      break;

    case 5:
      effect_sendvoxels_rand_z(100,50,200); // parameters: (int iterations, int delay, int wait)
      fill(0x00);
      break;

    case 6:
      effect_rain(200);
      fill(0x00);
      break;

    case 7:
  	  effect_sendplane_rand_z(3,100,200); // parameters:  (unsigned char z, int delay, int wait)
      fill(0x00);
      break;

   case 8:
	  effect_light_column(200,50);
      fill(0x00);
      break;

    // In case the effect number is out of range do nothing
    default:
      break;
  }
}


