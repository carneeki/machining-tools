#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*
 * Adam Carmichael <carneeki@carneeki.net>
 *
 * Calculate a gauge block stack to use with a sine bar for setting an angle.
 * It assumes the same unit for the length between centres on the sine bar and
 * for the gauge blocks (that is mm with mm or inches with inches). No units are
 * needed to be specified. All angles are in decimal degrees.
 */

float hypotenuse;
float angle;
float opp;

#define PI 3.14159265

void help(char**);

int main(int argc, char *argv[])
{
  // ensure argc is sane, expect to see something like:
  // ./sine <angle> <distance>
  if(argc != 3)
  {
    help(argv);
    exit(-1);
  }

  angle = atof(argv[1]);
  hypotenuse = atof(argv[2]);

  // remember SOH CAH TOA!
  opp = hypotenuse * sin(angle * PI/180);

  printf("Angle: %.4f, Sinebar length: %.4f | Stack up: %.4f\n", angle, hypotenuse, opp);

  return 0;
}

void help(char *argv[])
{
  printf("Usage:\n");
  printf("%s <angle> <sinebar length>\n\n", argv[0]);
  printf("<angle> is the number of degrees you wish to set\n\n");
  printf("<sinebar length> is the distance between centres of the sinebar\n\n");
}
