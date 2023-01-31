#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "test gnuplot"
    set xlabel "longitude"
    set ylabel "latitude"
    set pm3d map
    set dgrid3d
    set pm3d interpolate 0,0
    splot 'plot5.dat'
EOFMarker