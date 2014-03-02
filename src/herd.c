#include "herd.h"



Herd*
build_herd ( unsigned int const herd_size , unsigned const int pop_size )
{
  Herd* herd = malloc ( sizeof ( Herd ) );

  herd->herd_size = herd_size;
  herd->herd_list = calloc ( herd_size , sizeof ( char ) );

  herd->pop_size = pop_size;
  herd->pop_list = calloc ( pop_size , sizeof ( char ) );

  return herd;
};



void
free_herd ( Herd* herd )
{
  free ( herd->herd_list );
  free ( herd->pop_list );

  free ( herd );
}



Herd*
herd_randomize_herd ( Herd * const herd )
{
  return herd;
}
