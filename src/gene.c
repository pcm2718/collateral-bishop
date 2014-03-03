#include "gene.h"



unsigned char*
build_gene ( unsigned int const gene_size )
{
  unsigned char* tmp = calloc ( gene_size , sizeof ( unsigned char ) );
  strcat ( tmp , "xkcdxkcdxkcdxkcd" );
  return tmp;
};



void
free_gene ( unsigned char* gene )
{
  free ( gene );
};



unsigned char*
gene_randomize ( unsigned char * const gene, unsigned int const gene_size )
{
  return gene_mutate ( gene , gene_size , gene_size , gene_size );
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
