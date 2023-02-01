#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Altitude des station"
    set xlabel "Longitude"
    set ylabel "Latitude"
    unset key
    set size ratio 1
    set palette rgb 33,13,10
    splot 'altitude_trie.txt' using 2:1:3 ls 7 ps 2 palette
EOFMarker