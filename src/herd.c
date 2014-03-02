#include "herd.h"



Herd*
build_herd ( unsigned int const gene_size , unsigned int const herd_size , unsigned const int pop_size )
{
  Herd* herd = malloc ( sizeof ( Herd ) );

  herd->gene_size = gene_size;

  herd->herd_size = herd_size;
  herd->herd_list = calloc ( herd_size + pop_size , sizeof ( char* ) );

  herd->pop_size = pop_size;
  herd->pop_list = herd->herd_list + herd_size;

  return herd;
};



void
free_herd ( Herd* herd )
{
  free ( herd->herd_list );

  free ( herd );
}



Herd*
herd_randomize_herd ( Herd * const herd )
{
  return herd;
}
