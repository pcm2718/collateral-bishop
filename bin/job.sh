#!/bin/bash
# The #PBS directives are the equivalent of passing the same argument on
# the qsub command line.

#PBS -N collateral-bishop
#PBS -l nodes=4:ppn=4
#PBS -l walltime=00:15:00
#PBS -M parker.michaelson@gmail.com

#PBS -j oe
#PBS -m abe

. /rc/tools/utils/dkinit

collateral-bishop
