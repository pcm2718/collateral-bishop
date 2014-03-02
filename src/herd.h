#ifndef BISHOP_HERD_H
#define BISHOP_HERD_H



#include <stdlib.h>



struct herd
{
  unsigned int gene_size;

  unsigned int herd_size;
  unsigned char** herd_list;

  unsigned int pop_size;
  unsigned char** pop_list;
};
typedef struct herd Herd;



Herd*
build_herd ( unsigned int const gene_size, unsigned int const herd_size , unsigned int const pop_size );



void
free_herd ( Herd* herd );



Herd*
herd_randomize_herd ( Herd * const herd );



Herd*
herd_randomize_pop ( Herd * const herd );



void
herd_mate_random ( Herd * const herd );



void
herd_mutate_offspring ( Herd * const herd );



Herd*
herd_emmigrate ( Herd * const herd , Herd * const out_herd );



void
herd_immigrate ( Herd * const herd , Herd const * const in_herd );



void
herd_sort_fitness ( Herd * const herd );



void
herd_cull_fitness ( Herd * const herd );



#endif
