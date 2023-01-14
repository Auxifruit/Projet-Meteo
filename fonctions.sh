#!bin/bash

Help () {
    cat Help.txt
}

Tri_en_C () {
    echo "On traite le fichier "$1"."
    sleep 1
    if [ "$3" -eq 1 ] ; then
        echo "abr"
    elif [ $4 -eq 1 ] ; then
        echo "tab"
    else
        echo "avl"
    fi
}