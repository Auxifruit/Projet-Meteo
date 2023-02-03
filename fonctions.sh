#!bin/bash

Help () {
    cat Help.txt
}

Tri_en_C () {
    echo "On traite le fichier "$1"."
    if [ "$2" -eq 1 ] ; then
        if [ -n "$4" ] ; then
            ./triABR r f "$1" o fichier.txt
        fi
        echo "Fonction tri ABR."
        ./triABR f "$1" o fichier.txt
    elif [ $3 -eq 1 ] ; then
        if [ -n "$4" ] ; then
            ./triLC r f "$1" o fichier.txt
        fi
        echo "Fonction tri liste chainée."
        ./triLC f "$1" o fichier.txt
    else
        if [ -n "$4" ] ; then
            ./triAVL r f "$1" o fichier.txt
        fi
        echo "Fonction tri AVL."
        ./triAVL f "$1" o fichier.txt
    fi
}
