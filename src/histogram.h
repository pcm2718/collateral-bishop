#ifndef BISHOP_HISTOGRAM_H
#define BISHOP_HISTOGRAM_H



struct point
{
  float real;
  float imag;
};
typedef struct point Point;



struct histogram
{
  Point min_point;
  Point max_point;

  unsigned int x_span;
  unsigned int y_span;

  unsigned short scale;
  unsigned short * data;
};
typedef struct histogram Histogram;



Histogram*
build_histogram ( Point const min_point , Point const max_point , unsigned int const x_span , unsigned int const y_span );



void
free_histogram ( Histogram * histogram );



Histogram*
convert_ppm_to_histogram ( char const * const ppm );



#endif
