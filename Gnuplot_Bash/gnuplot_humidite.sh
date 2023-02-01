#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Humidité max par station"
    set xlabel "Longitude"
    set ylabel "Latitude"
    unset key
    set size ratio 1
    splot 'humidite_trie.txt' using 2:3:1 ls 7 ps 2 palette
EOFMarker

: <<'END'
    set pm3d map
    set dgrid3d
    set pm3d interpolate 0,0
END