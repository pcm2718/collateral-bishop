#ifndef BISHOP_HISTOGRAM_H
#define BISHOP_HISTOGRAM_H



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <complex.h>



struct histogram
{
  unsigned int x_span;
  unsigned int y_span;

  unsigned short scale;
  unsigned short* data;
};
typedef struct histogram Histogram;



Histogram*
build_histogram ( unsigned int const x_span , unsigned int const y_span , unsigned short const scale );



void
free_histogram ( Histogram * histogram );



Histogram*
convert_ppm_to_histogram ( char * const ppm );



#endif
