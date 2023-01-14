#!bin/bash

Help () {
    cat Help.txt
}

Tri_en_C () {
    echo "On traite le fichier "$1"."
    sleep 1
    if [ "$2" -eq 1 ] ; then
        if [ -n "$4" ] ; then
            echo "$4"
        fi
        echo "Fonction tri ABR."
    elif [ $3 -eq 1 ] ; then
        if [ -n "$4" ] ; then
            echo "$4"
        fi
        echo "Fonction tri liste chainée."
    else
        if [ -n "$4" ] ; then
            echo "$4"
        fi
        echo "Fonction tri AVL."
    fi
}
