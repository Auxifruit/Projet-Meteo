#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Moyenne des températures selon la date"
    set xlabel "Date"
    set ylabel "Moyenne température"
    set xdata time
    set timefmt "%Y-%m-%dT%H%M%S"
    set xtic rotate
    plot 'temperature2_trie.txt' using 1:2 with l title "Température"
EOFMarker