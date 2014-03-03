#!/bin/bash

THREADS=7

mpirun -np $THREADS bin/collateral-bishop
#if [ $? -eq 0 ]
#then
#        cp tmp/img_0.ppm tmp/feh_tmp.ppm
#        feh -. --force-aliasing tmp/feh_tmp.ppm &
#        ppmtojpeg tmp/feh_tmp.ppm > tmp/feh_tmp.jpeg
#        textme

#        echo "Success."
#else
#        echo "Image generation failed." | mutt -s "Buddhabrot Notice" -- 4357573639@mms.att.net

#        echo "Failure."
#fi
