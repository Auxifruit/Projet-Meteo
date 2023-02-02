#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Pression des stations"
    set xlabel "ID de station"
    set ylabel "Pression"
    plot 'pression1_trie.txt' using log(1):3:2 with filledcurve title "Marge d'erreur" lc rgb '#fde725', '' using log(1):4 smooth mcspline lw 2 title "Pression moyenne"
EOFMarker