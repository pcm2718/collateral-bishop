#include<stdlib.h>
#include <mpi.h>

#include "histogram.h"



/*
 * This is the name of the file used to generate the master histogram
 * used for training in the genetic algorithm.
 */
#define MASTER_FILENAME "home/master.ppm"



/*
 * The parameters for the genetic algorithm go here as constants
 * until I figure out how command line arguments work.
 */
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
       * Read the string containing the master histogram from
       * MASTER_FILENAME.
       */
      
      /*
       * Construct the master histogram from the string containing
       * it.
       */

      /*
       * Send the master histogram data to all other processes.
       */
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
       * Read the master histogram data.
       */

      /*
       * Construct a Histogram structure containing the master
       * histogram data.
       */
    }

  /*
   * Print the histogram for testing purposes.
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


  /*
   * Stop MPI.
   */
  MPI_Finalize ();

  /*
   * We got this far, return success.
   */
  return EXIT_SUCCESS;
};
