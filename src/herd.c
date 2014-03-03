#include "herd.h"



Herd*
build_herd ( unsigned int const gene_size , unsigned int const herd_size , unsigned const int pop_size )
{
  Herd* herd = malloc ( sizeof ( Herd ) );

  herd->gene_size = gene_size;

  herd->herd_size = herd_size;
  herd->herd_list = calloc ( herd_size + pop_size , sizeof ( char* ) );

  for ( unsigned int i = 0 ; i < herd_size ; ++i )
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
};



Herd*
herd_randomize_herd ( Herd * const herd )
{
  for ( unsigned int i = 0 ; i < herd->herd_size ; ++i )
    {
      herd->herd_list[i] = gene_randomize ( herd->herd_list[i] , herd->gene_size );
    }

  return herd;
};



Herd*
herd_mate ( Herd * const herd )
{
  /*
   * Look for free spots in the pop_list.
   */
  for ( unsigned int i = 0 ; i < herd->pop_size ; ++i )
    {
      if ( herd->pop_list[i] == NULL );
        /*
         * If a free spot is found, pick two members of the herd at
         * random, mate them, and assign the offspring to the spot.
         * Note that the membership of any herd is diverse and may
         * include narcissists. As such, self-love is allowed.
         */
        herd->pop_list[i] = gene_mate ( herd->herd_list[rand () % herd->herd_size] , herd->herd_list[rand () % herd->herd_size] , herd->gene_size );
    }

  return herd;
};



Herd*
herd_mutate_offspring ( Herd * const herd , unsigned int const min_mutations , unsigned int const max_mutations )
{
  /*
   * Apply random mutations to the offspring in pop_list.
   */
  for ( unsigned int i = 0 ; i < herd->pop_size ; ++i )
    if ( herd->pop_list[i] )
      gene_mutate ( herd->pop_list[i] , herd->gene_size , min_mutations , max_mutations );

  return herd;
};



Herd*
herd_emmigrate ( Herd * const herd , Herd * const out_herd )
{
  unsigned int size = out_herd->gene_size;
  size++;
  return herd;
};



Herd*
herd_immigrate ( Herd * const herd , Herd const * const in_herd )
{
  unsigned int size = in_herd->gene_size;
  size++;
  return herd;
};



Herd*
herd_cull ( Herd * const herd )
{
  /*
   * EX-TERMINATE the offspring in pop_list.
   */
  for ( unsigned int i = 0 ; i < herd->pop_size ; ++i )
    {
      if ( herd->pop_list[i] )
        free_gene ( herd->pop_list[i] );
      herd->pop_list[i] = NULL;
    }

  return herd;
};



Herd*
herd_sort_fitness ( Herd * const herd , Histogram const * const master )
{
  /*
   * Allocate an array to hold the fitness of each gene.
   */
  float* fitness = calloc ( herd->herd_size + herd->pop_size , sizeof ( float ) );

  /*
   * Compute the fitness of each gene and store it in the array.
   */
  for ( unsigned int k = 0 ; k < herd->herd_size + herd->pop_size ; ++k )
    for ( unsigned int j = 0 ; j < master->y_span ; ++j )
      for ( unsigned int i = 0 ; i < master->x_span ; ++i )
        fitness[k] += powf ( gene_eval ( herd->herd_list[k] , i , j ) - master->data[i + j*master->x_span] , 2 );

  /*
   * Sort both arrays in parallel, insertion sort.
   *
   * Apply optimization later.
   */
  for ( unsigned int i = 1 ; i < herd->herd_size + herd->pop_size ; ++i )
    {
      unsigned int j = i;

      while ( j > 0 && fitness[j-1] > fitness[j] )
        {
          unsigned short tmp = fitness[j-1];
          fitness[j-1] = fitness[j];
          fitness[j] = tmp;

          unsigned char* pmt = herd->herd_list[j-1];
          herd->herd_list[j-1] = herd->herd_list[j];
          herd->herd_list[j] = pmt;

          --j;
        }
    }

  /*
   * Free the fitness array.
   */
  free ( fitness );

  return herd;
};
