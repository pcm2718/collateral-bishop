#include "gene.h"



unsigned char*
build_gene ( unsigned int const gene_size )
{
  return calloc ( gene_size , sizeof ( unsigned char ) );
};



void
free_gene ( unsigned char* gene )
{
  free ( gene );
};



unsigned char*
gene_randomize ( unsigned char * const gene, unsigned int const gene_size )
{
  //for ( int i = 0 ; j < floor ( log ( gene_size ) / log ( 2 ) ) ; ++j )

  /*
   * Create an array filled with operators.
   */
  unsigned char ops [4] = OPS;

  /*
   * Fill the upper layers with operators. The funny bit with logs in
   * the test computes a log base 2 of gene_size.
   */
  for ( unsigned int i = 0 ; i < gene_size / 2 ; ++i )
    gene[i] = ops[ rand () % 4 ];

  /*
   * Fill the bottom layer of the tree with constants. Bit of a hack
   * with mod 256.
   */
  for ( unsigned int i = ( gene_size / 2 ) + 1 ; i < gene_size ; ++i )
    gene[i] = rand () % 256;

  return gene;
};



unsigned char*
gene_mate ( unsigned char const * const gene_1 , unsigned char const * const gene_2 , unsigned int const gene_size )
{
  unsigned char* child = malloc ( sizeof ( unsigned char ) * gene_size );
  memcpy ( child , gene_1 , gene_size );
  return child;
};



unsigned char*
gene_mutate ( unsigned char * const gene , unsigned int const gene_size , unsigned int min_mutations , unsigned int max_mutations )
{
  return gene;
};



unsigned short
gene_eval ( unsigned char const * const gene , unsigned int x , unsigned int y )
{
  return 255;
};
