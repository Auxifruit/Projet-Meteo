#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Humidité max par station"
    set xlabel "Longitude"
    set ylabel "Latitude"
    unset key
    stats 'humidite_trie.txt' using 1 name 'x' nooutput
    set cbrange [x_min:x_max]
    set pm3d map
    set dgrid3d 1000,1000
    set pm3d interpolate 0,0
    splot 'humidite_trie.txt' using 2:3:1
EOFMarker