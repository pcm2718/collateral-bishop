#ifndef BISHOP_GENE_H
#define BISHOP_GENE_H



#include <stdlib.h>
#include <string.h>



unsigned char*
build_gene ( unsigned int const gene_size );



void
free_gene ( unsigned char* gene );



/*
 * Note that this function could be implemented in terms of gene_mutate.
 */
unsigned char*
gene_randomize ( unsigned char * const gene, unsigned int const gene_size );



unsigned char*
gene_mate ( unsigned char const * const gene_1 , unsigned char const * const gene_2 , unsigned int const gene_size );



unsigned char*
gene_mutate ( unsigned char * const gene , unsigned int const gene_size , unsigned int min_mutations , unsigned int max_mutations );



unsigned short
gene_eval ( unsigned char const * const gene , unsigned int x , unsigned int y );



#endif
