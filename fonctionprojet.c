#include <stdio.h>
#include <stdlib.h>

/*
// fonction pour la pression option 2


void p2()
{
FILE *p2 = fopen ("p2" , "w" );


if (p2 != NULL )
{
fprintf(p2, "set title 'Pression Moyenne par jour et heure' \n ");
fprintf(p2, "set grid \n");
fprintf(p2, "set palette rgb 33,13,10 \n");
fprintf(p2, "plot 'p2.dat' u 1:3:3:xtic(2) with lines tit 'Pression moyenne en (P) ' palette \n");
}
fclose (p2);
}

// fonction pour la temeperature option 2


void t2()
{
FILE *t2 = fopen ("t2" , "w" );


if (t2 != NULL )
{
fprintf(t2, "set title 'Temperature Moyenne par jour et heure' \n");
fprintf(t2, "set grid \n");
fprintf(t2, "set palette rgb 33,13,10 \n");
fprintf(t2, "plot 't2.dat' u 1:3:3:xtic(2) with lines tit 'temperature moyenne en (°C) ' palette \n");
}
fclose (t2);
}

*/
// fonction pour l'altitude


void altitude()
{
FILE *alt = fopen("altitude" , "w" ) ;

if ( alt !=NULL)
{
fprintf (alt , "set title 'altitude' \n");
fprintf (alt , "set size ratio 1 \n ");

 fprintf (alt , "set palette rgb 33,13,10 \n");
fprintf (alt , "plot 'h.txt' u 1:2:3  ls 7 ps 2 palette \n");
}
fclose (alt);

}


// fonction pour l'humidité 


void humidité()
{
FILE *humid = fopen("humidité" , "w" ) ;

if ( humid !=NULL)
{
fprintf (humid , "set title Humidité \n");
fprintf (humid , "set size ratio 1 \n ");
fprintf (humid , "set palette rgb 33,13,10 \n" );
fprintf (humid , "plot 'h.txt' u 1:2:3 with image \n ");
}
fclose (humid);

}


// fonction pour les champs de vecteurs wind w 
 
 
void vect()
{ 

 FILE *v = fopen("vecteur" , "w" ) ;
 
 if ( v != NULL)
 {

fprintf (v, "set title vent \n");
fprintf (v,"set key box \n");
fprintf (v,"plot 'vect.dat' u 1:2:($3/8):($4/8) with vectors lc -1 filled \n"); 
}
fclose(v);
}



int main()
{  
altitude();    

}
