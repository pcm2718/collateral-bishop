#ifndef BISHOP_GENE_H
#define BISHOP_GENE_H



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



#define ADD_OP '+'
#define SUB_OP '-'
#define MUL_OP '*'
#define DIV_OP '/'

#define OPS { ADD_OP , SUB_OP , MUL_OP , DIV_OP };



unsigned char*
build_gene ( unsigned int const gene_size );



void
free_gene ( unsigned char* gene );



unsigned char*
gene_randomize ( unsigned char * const gene, unsigned int const gene_size );



unsigned char*
gene_mate ( unsigned char const * const gene_1 , unsigned char const * const gene_2 , unsigned int const gene_size );



unsigned char*
gene_mutate ( unsigned char * const gene , unsigned int const gene_size , unsigned int min_mutations , unsigned int max_mutations );



long
gene_eval ( unsigned char const * const gene , unsigned int gene_size , unsigned int x , unsigned int y );



#endif
