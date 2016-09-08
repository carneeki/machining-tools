#include <stdio.h>
/*
 * Adam Carmichael <carneeki@carneeki.net>
 *
 * Modern port of Marv Klotz' mandrel calculation program 'MANDREL'.
 * This in turn was based on Kozo Hiraoka's article in Home Shop Machinist,
 * July/August 1987, pg 30.
 */

int main(int argc, char *argv[])
{
  // magic constants
  double c0[] = {0.980364,0.012436};  // constant coefficient
  double c1[] = {-0.012436,-0.11018}; // first order coefficient

  int    wt = 0;   // wire type
  double id = 0;   // inner dia of spring
  double ds = 0;   // average dia of spring
  double dw = 0;   // wire dia
  double fact = 0; // empirical factor
  double dm = 0;   // mandrel dia

  printf("Enter wire type. Music wire [0], phosphor bronze [1]: ");
  scanf("%d", &wt);

  printf("Wire diameter: ");
  scanf("%lf", &dw);

  printf("Enter spring id: ");
  scanf("%lf", &id);

  ds = id + dw;
  fact = c0[wt] + c1[wt] * (ds/dw);
  dm = (fact * ds) - dw;

  printf("Mandrel diameter = %.3lf\n", dm);
  return 0;
}
