#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Température des stations"
    set xlabel "ID de station"
    set ylabel "Température"
    set xtics rotate 
    plot 'temperature1_trie.txt' using log(1):3:2:xtic(1) with filledcurve title "Ecart avec min et max" lc rgb '#fde725', '' using log(1):4 smooth mcspline lw 2 title "Température moyenne"
EOFMarker
