#!/bin/bash

gnuplot -persist <<-EOFMarker
    set title "Températures selon la date/heure"
    set xlabel "Jour"
    set ylabel "Température"
    set xdata time
    set timefmt "%Y-%m-%dT%H%M%S"
    set xtic rotate
    set datafile separator " T:"
    set palette model RGB defined (1 "#440154", 4 "#472c7a", 7 "#3b518b" , 10 "#2c718e", 13 "#21908d", 16 "#27ad81", 19 "#5cc863", 22 "#aadc32")
    set cbrange [1:22]
    set cbtics format ""
    set cbtics ("1H" 1, "4H" 4, "7H" 7, "10H" 10, "13H" 13, "16H" 16, "19H" 19, "22H" 22)
    plot 'temperature3_trie.txt' using 2:7:3 with l title "Température" palette
EOFMarker