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
   * with mod 128.
   */
  for ( unsigned int i = gene_size / 2  ; i < gene_size ; ++i )
    gene[i] = ( rand () % 46 ) + 48;

  return gene;
};



unsigned char*
gene_mate ( unsigned char const * const gene_1 , unsigned char const * const gene_2 , unsigned int const gene_size )
{
  unsigned char* child = malloc ( sizeof ( unsigned char ) * gene_size );

  for ( unsigned int i = 0 ; i < gene_size ; ++i)
    if ( i % 2 )
      child[i] = gene_1[i];
    else
      child[i] = gene_2[i];

  return child;
};



unsigned char*
gene_mutate ( unsigned char * const gene , unsigned int const gene_size , unsigned int min_mutations , unsigned int max_mutations )
{
  unsigned char ops [4] = OPS;
  int mutation_count = ( rand () % (max_mutations - min_mutations) ) + min_mutations;

  for ( int i = 0 ; i < mutation_count ; ++i )
    {
      unsigned int j = rand () % gene_size;
      
      if ( j >= gene_size / 2 )
        gene[j] = ( rand () % 46 ) + 48;
      else
        gene[j] = ops[ rand () % 4 ];
    }
  return gene;
};



long 
gene_eval_r ( unsigned char const * const gene , unsigned int const gene_size , unsigned int x , unsigned int y , unsigned int index , unsigned int depth , unsigned int max_depth )
{
  if ( depth < max_depth )
    {
      long a = gene_eval_r ( gene , gene_size , x , y , ( 2 * index + 1 ) , depth + 1 , max_depth );
      long b = gene_eval_r ( gene , gene_size , x , y , ( 2 * index + 2 ) , depth + 1 , max_depth );

      switch ( gene[index] )
        {
        case ADD_OP:
          return a + b;
        case SUB_OP:
          return a - b;
        case MUL_OP:
          return a * b;
        case DIV_OP:
          if ( b )
            return a / b ;
          else
            return a ;
        case 'x':
        case 'X':
          return x;
        case 'y':
        case 'Y':
          return y;
        default:
          return gene[index];
        }
    }
  else
    return gene[index];
};



long
gene_eval ( unsigned char const * const gene , unsigned int const gene_size , unsigned int x , unsigned int y )
{
  return gene_eval_r ( gene , gene_size , x , y , 0 , 1 , ceil ( log ( gene_size ) / log ( 2 ) ) );
  //return rand () % 256;
};
