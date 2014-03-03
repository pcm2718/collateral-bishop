#include "histogram.h"



Histogram*
build_histogram ( unsigned int const x_span , unsigned int const y_span , unsigned short const scale )
{
  Histogram* histogram = malloc ( sizeof ( Histogram ) );

  histogram->x_span = x_span;
  histogram->y_span = y_span;

  histogram->scale = scale;
  histogram->data = calloc ( x_span * y_span , sizeof ( unsigned short ) );

  return histogram;
};



void
free_histogram ( Histogram* histogram )
{
  free ( histogram->data );

  free ( histogram );
};



Histogram*
convert_ppm_to_histogram ( char * const ppm )
{
  /*
   * Check for P2 tag at top of file. If the P2 tag is not present,
   * return NULL.
   */
  if ( strncmp ( "P2" , strtok ( ppm , "\n" ) , 2 ) )
    return NULL;

  /*
   * Parse x_span and y_span.
   */
  unsigned int x_span = 0;
  unsigned int y_span = 0;

  sscanf ( strtok ( NULL , "\n" ) , "%u %u" , &x_span , &y_span);

  /*
   * Parse scale.
   */
  unsigned short scale = 0;

  sscanf ( strtok ( NULL , "\n" ) , "%hu" , &scale );

  /*
   * Create histogram.
   */
  Histogram* histogram = build_histogram ( x_span , y_span , scale );

  /*
   * Parse the actual histogram data.
   */

  for ( unsigned int j = 0 ; j < histogram->y_span ; ++j )
    {
      for ( unsigned int i = 0 ; i < histogram->x_span ; ++i )
        {
          unsigned short tmp = 0;
          /*
           * sscanf may be inefficeint, look into strtol
           */
          sscanf ( strtok ( NULL , " \n" ) , "%hu" , &tmp );
          histogram->data[i + j * histogram->x_span] = tmp;
        }
    }

  /*
   * Return histogram.
   */
  return histogram;
};



/*
void
convert_histogram_to_ppm ( Histogram const * const histogram , FILE* outfile)
{
  return;
};
*/
