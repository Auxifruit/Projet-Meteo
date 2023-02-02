#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Température des stations"
    set xlabel "ID de station"
    set ylabel "Température"
    plot 'temperature1_trie.txt' using log(1):3:2 with filledcurve title "Marge d'erreur" lc rgb '#fde725', '' using log(1):4 smooth mcspline lw 2 title "Température moyenne"
EOFMarker