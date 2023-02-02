#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Pression des stations"
    set xlabel "ID de station"
    set ylabel "Pression"
    set xtics rotate
    plot 'pression1_trie.txt' using log(1):3:2:xtic(1) with filledcurve title "Ecart avec min et max" lc rgb '#fde725', '' using log(1):4 smooth mcspline lw 2 title "Pression moyenne"
EOFMarker
