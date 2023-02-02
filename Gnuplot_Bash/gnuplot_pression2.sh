#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Moyenne des pression selon la date"
    set xlabel "Date"
    set ylabel "Moyenne pression"
    set xdata time
    set timefmt "%Y-%m-%dT%H%M%S"
    set xtic rotate
    plot 'pression2_trie.txt' using 1:2 with l title "Pression"
EOFMarker