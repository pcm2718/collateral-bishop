#include "histogram.h"



Histogram*
build_histogram ( float complex const min_point , float complex const max_point , unsigned int const x_span , unsigned int const y_span , unsigned short const scale )
{
  Histogram* histogram = malloc ( sizeof ( histogram ) );

  histogram->min_point = min_point;
  histogram->max_point = max_point;
  histogram->x_span = x_span;
  histogram->y_span = y_span;

  histogram->scale = scale;
  histogram->data = calloc ( x_span * y_span , sizeof ( unsigned short ) );

  printf ( "\n\nHistogram Created:\n" );
  printf ( "\tx_span: %u\n" , x_span );
  printf ( "\ty_span: %u\n" , y_span );
  printf ( "\n" );

  return histogram;
};



void
free_histogram ( Histogram* histogram )
{
  free ( histogram->data );

  free ( histogram );
};



Histogram*
convert_ppm_to_histogram ( char const * const ppm )
{
  /*
   * The pointer to our current position in the string.
   */
  char const * str = ppm;

  /*
   * Ignore first line. HACK!
   */
  str += 3;

  /*
   * Parse x_span and y_span. HACK!
   */
  unsigned int x_span = 0;
  unsigned int y_span = 0;

  sscanf ( str , "%u %u" , &x_span , &y_span);

  str += 6;

  /*
   * Parse scale.
   */
  unsigned short scale = 0;

  sscanf ( str , "%hu" , &scale);

  /*
   * Create histogram.
   */
  Histogram* histogram = build_histogram ( DEFAULT_MIN_POINT , DEFAULT_MAX_POINT , x_span , y_span , scale );

  /*
   * Parse the actual histogram data.
   */

  /*
   * Return histogram.
   */
  return histogram;
};
