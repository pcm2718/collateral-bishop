#include<stdlib.h>
#include<stdio.h>
#include <mpi.h>

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
#define POP_SIZE 4



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
  //Histogram* master_histogram = NULL;

  /*
   * Check the pid.
   */
  if ( pid == 0 )
    {
      /*
       * If the pid is 0, then the process is responsible for
       * loading the master histogram and sending copies to
       * all other processes.
       *
       * I may replace some code here with special MPI stuff for
       * sending structures.
       */


      /*
       * Read the contents of MASTER_FILENAME into master_str.
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
                master_str[++transmit_size] = '\0';
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
       * Construct the master histogram from the string containing
       * it.
       */
      //master_histogram = convert_ppm_to_histogram ( master_str );

      /*
       * Deallocate the buffer containing the contents of
       * MASTER_FILENAME.
       */
      //printf ( "Process %i:\n" , pid );
      //printf ( "Size %zu:\n" , transmit_size );
      //puts ( master_str );
      //free ( master_str );
    }
  else
    {
      /*
       * If the pid is not 0, then the process is expecting the
       * receipt of the data comprising master histogram.
       * After receiving the histogram data, the process
       * reconstitutes it into a Histogram structure.
       *
       * I may replace some code here with special MPI stuff for
       * sending structures.
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
       * Construct a Histogram structure containing the master
       * histogram data.
       */

      /*
       * Free the buffer holding master_str.
       */
      //printf ( "Process %i:\n" , pid );
      //printf ( "Size %zu:\n" , receive_size );
      //puts ( master_str );
      //free ( master_str );
    }

  /*
   * Print the histogram for testing purposes.
   */
  /*
  printf ( "Node %i, master histogram:\n", pid );
  for ( unsigned long j = 0 ; j < master_histogram->y_span ; ++j )
    {
      for ( unsigned long i = 0 ; i < master_histogram->x_span ; ++i )
        printf ( "%i " , master_histogram->data[i + j * master_histogram->y_span] );
      printf ( "\n" );
    }
  printf ( "\n\n" );
  */


  /*
   * Generate an initial population of random genes of size POP_SIZE.
   */


  /*
   * Start the genetic algorithm.
   *
   * I need a good way of stoping the algorithm synchronously and
   * criteria for doing so.
   *
   * Figure out command line arguments while I'm at it.
   */
  for ( int i = 0 ; i < ITTR_COUNT ; ++i )
    {
      /*
       * Mate.
       */


      /*
       * Mutate.
       */


      /*
       * Migrate.
       */


      /*
       * Cull. EX-TERMINATE! EX-TERMINATE!
       */
    }


  /*
   * Stop MPI.
   */
  MPI_Finalize ();

  /*
   * We got this far, return success.
   */
  return EXIT_SUCCESS;
};
