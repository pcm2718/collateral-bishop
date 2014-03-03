#include "herd.h"



Herd*
build_herd ( unsigned int const gene_size , unsigned int const herd_size , unsigned const int pop_size )
{
  Herd* herd = malloc ( sizeof ( Herd ) );

  herd->gene_size = gene_size;

  herd->herd_size = herd_size;
  herd->herd_list = calloc ( herd_size + pop_size , sizeof ( char* ) );

  for ( unsigned int i = 0 ; i < herd_size + pop_size ; ++i )
    herd->herd_list[i] = build_gene ( gene_size );

  herd->pop_size = pop_size;
  herd->pop_list = herd->herd_list + herd_size;

  return herd;
};



void
free_herd ( Herd* herd )
{
  for ( unsigned int i = 0 ; i < herd->herd_size + herd->pop_size ; ++i )
    free_gene ( herd->herd_list[i] );

  free ( herd->herd_list );

  free ( herd );
}



Herd*
herd_randomize_herd ( Herd * const herd )
{
  for ( unsigned int i = 0 ; i < herd->herd_size ; ++i )
    {
      herd->herd_list[i] = gene_randomize ( herd->herd_list[i] , herd->gene_size );
    }

  return herd;
}
