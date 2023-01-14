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
            # r = 1
        fi
        echo "Fonction tri ABR."
        # fonction_abr($1,r)
    elif [ $3 -eq 1 ] ; then
        if [ -n "$4" ] ; then
            echo "$4"
        fi
        echo "Fonction tri liste chainée."
        # fonction_tab($1,r)
    else
        if [ -n "$4" ] ; then
            echo "$4"
        fi
        echo "Fonction tri AVL."
        # fonction_avl($1,r)
    fi
}
