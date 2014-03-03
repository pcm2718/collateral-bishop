#include<stdlib.h>
#include<stdio.h>
#include <mpi.h>

#include <string.h>
#include "herd.h"
#include "histogram.h"



/*
 * This is the name of the file used to generate the master histogram
 * used for training in the genetic algorithm.
 */
#define MASTER_FILENAME "home/test.ppm"



/*
 * The parameters for the genetic algorithm go here as constants
 * until I figure out how command line arguments work.
 */
#define ITTR_COUNT 10
#define GENE_SIZE 16
#define HERD_SIZE 4
#define POP_SIZE 16



int
main ( int argc , char** argv )
{
  /*
   * Declare and initalize the process count and pid.
   */
  int ps_count = 0;
  int pid = 0;

  /*
   * Start MPI.
   */
  MPI_Init ( &argc , &argv );

  /*
   * Get the process count.
   */
  MPI_Comm_size ( MPI_COMM_WORLD , &ps_count );

  /*
   * Get the pid.
   */
  MPI_Comm_rank ( MPI_COMM_WORLD , &pid );


  /*
   * Build an instance of Histogram to contain the master histogram.
   */
  Histogram* master_histogram = NULL;

  /*
   * Check the pid. It may be possible merge the ends of this
   * conditional.
   */
  if ( pid == 0 )
    {
      /*
       * If the pid is 0, then the process is responsible for
       * loading the master histogram and sending copies to
       * all other processes.
       */


      /*
       * Read the contents of MASTER_FILENAME into master_str.
       *
       * Verify this area.
       */
      size_t transmit_size = 0;
      char* master_str = NULL;
      FILE* master_file = fopen ( MASTER_FILENAME , "r" );
      if ( master_file != NULL )
        {
          if ( fseek ( master_file , 0L , SEEK_END ) == 0 )
            {
              long buffer_size = ftell ( master_file );

              if ( buffer_size == -1 )
                return EXIT_FAILURE;

              master_str = malloc ( sizeof ( char ) * ( buffer_size + 1 ) );
              
              if ( fseek ( master_file , 0L , SEEK_SET ) != 0 )
                return EXIT_FAILURE;

              transmit_size = fread ( master_str , sizeof ( char ) , buffer_size , master_file );
              if ( transmit_size == 0 )
                return EXIT_FAILURE;
              else
                master_str[transmit_size] = '\0';
            }

          fclose ( master_file );
        }

      /*
       * Send the size of master_str and then master_str itself to
       * all other processes.
       */
      for ( int i = 1 ; i < ps_count ; ++i )
        {
          MPI_Send ( &transmit_size , 1 , MPI_UNSIGNED , i , 0 , MPI_COMM_WORLD );
          MPI_Send ( master_str , transmit_size , MPI_CHAR , i , 0 , MPI_COMM_WORLD );
        }

      /*
       * Construct a histogram from master_str.
       */
      master_histogram = convert_ppm_to_histogram ( master_str );

      /*
       * Deallocate of master_str.
       */
      free ( master_str );
    }
  else
    {
      /*
       * If the pid is not 0, then the process is expecting the
       * receipt of the data comprising master histogram.
       * After receiving the histogram data, the process
       * reconstitutes it into a Histogram structure.
       */


      /*
       * Receive the size of master_str from process 0.
       */
      size_t receive_size = 0;
      MPI_Recv ( &receive_size , 1 , MPI_UNSIGNED , 0 , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE );

      /*
       * Create a buffer of size receive_size to hold master_str.
       */
      char* master_str = malloc ( sizeof ( char ) * receive_size );

      /*
       * Receive the master histogram data and place it into master_str.
       */
      MPI_Recv ( master_str , receive_size , MPI_CHAR , 0 , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE );

      /*
       * Construct a histogram from master_str.
       */
      master_histogram = convert_ppm_to_histogram ( master_str );

      /*
       * Free the buffer holding master_str.
       */
      free ( master_str );
    }

  /*
   * By this point in the program, the local node has a copy of the
   * master histogram.
   */


  /*
   * Create a new local herd with:
   *    genes of size GENE_SIZE,
   *    a core herd of size HERD_SIZE,
   *    a maximum population os size POP_Size.
   */
  Herd* local_herd = build_herd ( GENE_SIZE , HERD_SIZE , POP_SIZE );

  /*
   * Fill the core herd with random genes.
   */
  //local_herd = herd_randomize_herd ( local_herd );


  /*
   * Start the genetic algorithm.
   *
   * I need a good way of stoping the algorithm synchronously and
   * criteria for doing so. Right now its just an itteration count.
   *
   * Figure out command line arguments while I'm at it.
   */
  for ( int i = 0 ; i < ITTR_COUNT ; ++i )
    {
      /*
       * Mate.
       */
      //herd_mate_random ( local_herd );


      /*
       * Mutate.
       */
      //herd_mutate_offspring ( local_herd );


      /*
       * Migrate.
       */
      //Herd* out_herd = build_herd ( HERD_SIZE , HERD_SIZE );
      //out_herd = herd_emmigrate ( local_herd , out_herd );
      //Herd* in_herd = out_herd;
      //herd_immigrate ( local_herd , in_herd );
      //free_herd ( in_herd );

      /*
       * Evaluate.
       */
      //herd_sort_fitness ( local_herd );


      /*
       * Cull. EX-TERMINATE! EX-TERMINATE!
       */
      //herd_cull_fitness ( local_herd );
    }

  /*
   * By this point in the program, each node has executed its own
   * genetic algorithm and has developed its own best solution.
   */


  /*
   * Check the pid. It may be possible merge the ends of this
   * conditional.
   */
  if ( pid == 0 )
    {
      /*
       * If the pid is 0, then the process needs to collect the best
       * solutions from the other nodes and pick the best one of
       * these solutions as the result of the genetic algorithm.
       */


      /*
       * Build a herd to contain the best solutions.
       */
      //Herd* best_herd = build_herd ( GENE_SIZE , ps_count , ps_count );

      /*
       * Get the best solution from the local herd and place it in
       * best_genes.
       */
      //memcpy ( best_herd->herd_list[0] , local_herd->herd_list[0] , local_herd->gene_size );

      /*
       * Receive the best solution from every other node.
       */
      for ( int i = 1 ; i < ps_count ; ++i )
        {
          //MPI_Recv ( best_herd->herd_list[i] , best_herd->gene_size , MPI_CHAR , i , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE );
        }

      /*
       * Sort the best solutions to find *the* best solution.
       */
      //herd_sort_fitness ( best_herd );

      /*
       * The best solution has been sorted to best_herd->herd_list[0]
       * as a result of the call to herd_sort_fitness. Copy it out
       * to best_gene.
       */
      //unsigned char* best_gene = malloc ( sizeof ( unsigned char ) * local_herd->gene_size );
      //memcpy ( best_gene , best_herd->herd_list[0] , local_herd->gene_size );

      /*
       * Free best_herd.
       */
      //free_herd ( best_herd );

      /*
       * Print the best gene to stdout.
       */
      for ( int i = 0 ; i < GENE_SIZE ; ++i );
        //putchar ( best_gene[i] );
    }
  else
    {
      /*
       * If the pid is not 0, the the process needs to send its best
       * solution to process 0 for processing.
       */
      //MPI_Send ( local_herd->herd_list[0] , local_herd->gene_size , MPI_CHAR , 0 , 0 , MPI_COMM_WORLD );
    }


  /*
   * Free the local herd.
   */
  free_herd ( local_herd );

  /*
   * Free the master histogram.
   */
  free_histogram ( master_histogram );


  /*
   * Stop MPI.
   */
  MPI_Finalize ();

  /*
   * We got this far, return success.
   */
  return EXIT_SUCCESS;
};
