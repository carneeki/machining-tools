#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Adam Carmichael <carneeki@carneeki.net>
 *
 * Divide a circle into d divisions using r ratio with a list of holes in plates
 * specified in file.
 */

#define F_HOLES "divide-holes.txt"

FILE *fpHoles;
char *fHoles;
char *line = NULL; // line number
size_t len = 0;    // length of line ??? TODO confirm me
ssize_t read;      // length of line
int divisions = 0; // number of divisions to make
int ratio = 0;     // ratio of worm gear
int hole = 0;      // number of holes in current plate


void help(char**);

int main(int argc, char *argv[])
{
  // ensure argc is sane, expect to see something like:
  // ./divide <divisions> <ratio> [filename]
  if(!( (argc == 3) || (argc == 4)) )
  {
    help(argv);
    exit(-1);
  }

  if(argc == 4)
  {
    fHoles = (char *) malloc(strlen(argv[3]));
    strcpy(fHoles, argv[3]);
  }
  else
  {
    fHoles = (char *) malloc(strlen(F_HOLES));
    strcpy(fHoles, F_HOLES);
  }

  divisions = atoi(argv[1]);
  ratio = atoi(argv[2]);

  printf("divisions: (%d), ratio: (%d), input-file: (%s)\n", divisions, ratio, fHoles);

  fpHoles = fopen(fHoles,"r");
  if(fpHoles == NULL)
  {
    printf("Could not open file: %s\n", fHoles);
    exit(EXIT_FAILURE);
  }

  while((read = getline(&line, &len, fpHoles)) != -1)
  {
    int h = atoi(line);
    //printf("%d\n",h);

    // w = (r*h)/d where w is a whole number
    if( ( (ratio * h) % divisions) == 0 )
      printf("(%d * %d) / %d = %d | Use %d plate and index %d holes at a time\n", ratio, h, divisions, ((ratio * h) / divisions), h, ((ratio * h) / divisions));
  }

  return 0;
}

void help(char *argv[])
{
  printf("Usage:\n");
  printf("%s <divisions> <ratio> [filename]\n\n", argv[0]);
  printf("<divisions> is the number of divisions you wish to divide the circle by\n\n");
  printf("<raito> is the ratio of the worm / pinion gear\n\n");
  printf("[filename] is an optional file containing a list of numbers (one per line) of how many holes are in each plate. If omitted, %s is used.\n", F_HOLES );
}
