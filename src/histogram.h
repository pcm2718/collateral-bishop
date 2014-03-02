#ifndef BISHOP_HISTOGRAM_H
#define BISHOP_HISTOGRAM_H



#include <stdlib.h>
#include <stdio.h>
#include <complex.h>



#define DEFAULT_MIN_POINT -2.25 + -1.5 * I
#define DEFAULT_MAX_POINT 0.75 + 1.5 * I



/*
 * Not currently used.
 */
/*
struct point
{
  float real;
  float imag;
};
typedef struct point Point;
*/



struct histogram
{
  float complex min_point;
  float complex max_point;

  unsigned int x_span;
  unsigned int y_span;

  unsigned short scale;
  unsigned short* data;
};
typedef struct histogram Histogram;



Histogram*
build_histogram ( float complex const min_point , float complex const max_point , unsigned int const x_span , unsigned int const y_span , unsigned short const scale );



void
free_histogram ( Histogram * histogram );



Histogram*
convert_ppm_to_histogram ( char const * const ppm );



#endif
