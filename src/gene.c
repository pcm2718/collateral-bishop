#include "gene.h"



unsigned char*
build_gene ( unsigned int const gene_size )
{
  return malloc ( sizeof ( unsigned char ) * gene_size );
};



void
free_gene ( unsigned char* gene )
{
  free ( gene );
};



unsigned char*
gene_randomize ( unsigned char* const gene, unsigned int const gene_size )
{
  /*
   * Declare array of gene bases.
   */
  unsigned char bases [5] = BASES;

  /*
   * Assign a random base to each spot in the gene.
   * There might be a fast way to do this using SIMD.
   */
  for ( unsigned int i = 0 ; i < gene_size ; ++i )
    gene[i] = bases[ rand () % 5 ];

  /*
   * Return the gene pointer, now with random bases.
   */
  return gene;
};
