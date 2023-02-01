#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct avl {
    float x;
    float y; 
    float data ;  
    float max  ;
    float moy ; 
    float min ; 
    float longitude ; 
    float latitude ; 
    int jour; 
    int heure;
    int mois ; 
    int annee ;
    int numstation;
    struct avl* fg ;
    struct avl* fd ;
    int equilibre ; 
} Avl;


typedef Avl* pAvl ; 




/////////////////////////////////////////////////////////////fonction diverses ///////////////////////////////////////////////////////////////////////////////////////////////////////////

pAvl filsGauche(pAvl a) {
	return a->fg;
}

pAvl filsDroit(pAvl a) {
	return a->fd;
}

int existeFilsGauche(pAvl a) { // a pointeur sur l'arbre; vérifie si l'arbre a un fils gauche
    if(a==NULL) { // verification arbre vide ou pas
        exit(1); // l'arbre est vide
    }
    return a->fg != NULL;
}

int existeFilsDroit(pAvl a) { // a pointeur sur l'arbre; vérifie si l'arbre a un fils droit
    if(a==NULL) { // verification arbre vide ou pas
        exit(1); // l'arbre est vide
    }
    return a->fd != NULL;
}

///////////////////////////////////////////////////////////// fonction de rotation ///////////////////////////////////////////////////////////////////////////////////////////////////////


int max2(int a, int b) {
    return (a > b ? a : b);
}

int max3(int a, int b, int c) {
    if(a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}

int min2(int a, int b) {
    return (a < b ? a : b);
}

int min3(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    }
    else if (b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}


pAvl rotationGauche(pAvl a) {
    pAvl pivot;
    int eq_a;
    int eq_p;
    pivot = a->fd;
    a->fd = pivot->fg;
    pivot->fg = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - max2(eq_p, 0) - 1;
    pivot->equilibre = min3(eq_a-2, eq_a+eq_p-2, eq_p-1);
    a = pivot;
    return a;
}

pAvl rotationDroite(pAvl a) {
    pAvl pivot;
    int eq_a;
    int eq_p;
    pivot = a->fg;
    a->fg = pivot->fd;
    pivot->fd = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min2(eq_p, 0) + 1;
    pivot->equilibre = max3(eq_a+2, eq_a+eq_p+2, eq_p+1);
    a = pivot;
    return a;
}

pAvl doubleRotationGauche(pAvl a) {
    a->fd = rotationDroite(a->fd);
    return rotationGauche(a);
}

pAvl doubleRotationDroite(pAvl a) {
    a->fg = rotationGauche(a->fg);
    return rotationDroite(a);
}




//////////////////////////////////////////////////////// fonction date /////////////////////////////////////////////////////////////////////////////////////////////////////////

int datedifferente ( int  heure , int jour ,int mois  ,int annee, int heure2 ,int jour2  ,int mois2 , int annee2)
{
if (jour ==jour2 && heure == heure2 && annee == annee2 && mois== mois2 )
{
	return 1;
}
return 0; 

}


int datemin(  int  heure ,int jours ,int mois , int annee , int  heure2 , int jours2 ,int mois2 , int annee2)
{
if (annee<annee2)
{
return 0; // retourne 0 si annee 2 plus vieille 
}
else if (annee>annee2)
{
    return 1;// retourne 0 si annee 2 plus vieille 
}
if (mois<mois2)
{
return 0; // retourne 0 si annee 2 plus vieille 
}
else if (mois>mois2)
{
    return 1; 
}
if (jours<jours2)
{
return 0; // retourne 0 si annee 2 plus vieille 
}
else if (jours>jours2)
{
    return 1;
}
if (heure<heure2)
{
return 0; // retourne 0 si annee 1 plus jeune 
}
else if (heure>heure2)
{
    return 1;
}
return 22 ;//pour les egalités
}




////////////////////////////////////////////////////////////// insertion / creation chaine //////////////////////////////////////////////////////////////////////////////////////////////////////////////
pAvl creerAvl (float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation )
{
     pAvl noeud = malloc(sizeof(Avl));
     if (noeud==NULL )
     {
        printf(" problème d'allocation de la mémoire ");
        exit (5); 

     }
    noeud->fg = NULL;
    noeud->fd = NULL;
    noeud->x = x ; 
    noeud->y =y; 
    noeud->data = data ;
    noeud->max = max  ;
    noeud->moy = moy; 
    noeud->min  = min; 
    noeud->longitude  = longitude; 
    noeud->latitude = latitude; 
    noeud->jour = jour; 
    noeud->heure = heure ;
    noeud->mois = mois ; 
    noeud->annee  = annee;
    noeud->numstation = numstation;
    noeud->equilibre = 0 ;
    return noeud ; 
}


pAvl equilibreAVL(pAvl a) 
{
    if(a->equilibre >= 2) {
        if(a->fd->equilibre >=0) {
            return rotationGauche(a);
        }
        else {
            return doubleRotationGauche(a);
        }
    }
    else if (a->equilibre <= -2) {
        if(a->fg->equilibre <= 0) {
            return rotationDroite(a);
        }
        else {
            return doubleRotationDroite(a);
        }
    }
    return a;
}

pAvl insertionAVL(pAvl a, float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation , int* h) 
{
    if(a==NULL) {
        *h = 1;
        return creerAvl( x , y,  data  ,max  , moy  ,  min  ,  longitude , latitude  , heure ,  jour, mois  , annee ,  numstation );
    }
    else if(data < a->data) {
        a->fg = insertionAVL(a->fg,  x , y,  data  ,max  , moy  ,  min  , longitude , latitude  , heure , jour , mois  , annee ,  numstation , h);
        *h = -*h;
    }
    else if(data > a->data) {
        a->fd = insertionAVL(a->fd, x , y,  data  , max  , moy  , min  , longitude , latitude  , heure ,  jour, mois  ,  annee , numstation , h);
    }
    else {
        *h = 0;
        return a;
    }
    if(*h != 0) {
        a->equilibre = a->equilibre + *h;
        a = equilibreAVL(a);
        if(a->equilibre == 0) {
            *h = 0;
        }
        else {
            *h = 1;
        }
    }
    return a;
}


pAvl insertionAVLNumstat(pAvl a, float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation , int* h) 
{
    if(a==NULL) {
        *h = 1;
        return creerAvl( x , y,  data  ,max  , moy  ,  min  ,  longitude , latitude  , heure ,  jour, mois  , annee ,  numstation );
    }
    else if(numstation< a->numstation) {
        a->fg = insertionAVLNumstat(a->fg,  x , y,  data  ,max  , moy  ,  min  , longitude , latitude  , heure , jour , mois  , annee ,  numstation , h);
        *h = -*h;
    }
    else if(numstation > a->numstation) {
        a->fd = insertionAVLNumstat(a->fd, x , y,  data  , max  , moy  , min  , longitude , latitude  , heure ,  jour, mois  ,  annee , numstation , h);
    }
    else {
        *h = 0;
        return a;
    }
    if(*h != 0) {
        a->equilibre = a->equilibre + *h;
        a = equilibreAVL(a);
        if(a->equilibre == 0) {
            *h = 0;
        }
        else {
            *h = 1;
        }
    }
    return a;
}




pAvl insertionAVLdate(pAvl a, float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation , int* h) 
{
    if(a==NULL) {
        *h = 1;
        return creerAvl( x , y,  data  ,max  , moy  ,  min  ,  longitude , latitude  , heure ,  jour, mois  , annee ,  numstation );
    }
    else if(datemin(a->heure , a->jour , a->mois , a->annee , heure , jour , mois, annee) == 0) 
    {
        a->fg = insertionAVLNumstat(a->fg,  x , y,  data  ,max  , moy  ,  min  , longitude , latitude  , heure , jour , mois  , annee ,  numstation , h);
        *h = -*h;
    }
    else if(datemin(a->heure , a->jour , a->mois , a->annee , heure , jour , mois, annee) == 1)  
    {
        a->fd = insertionAVLNumstat(a->fd, x , y,  data  , max  , moy  , min  , longitude , latitude  , heure ,  jour, mois  ,  annee , numstation , h);
    }
    else {
        *h = 0;
        return a;
    }
    if(*h != 0) {
        a->equilibre = a->equilibre + *h;
        a = equilibreAVL(a);
        if(a->equilibre == 0) {
            *h = 0;
        }
        else {
            *h = 1;
        }
    }
    return a;
}





////////////////////////////////////////////////////// parcours /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







void parcourstemp1(pAvl z , FILE* f)
{
	if(z!= NULL) 
	{ 
	
	parcourstemp1(z->fg, f); // on regarde dans le fils gauche 
	fprintf (f, "%d %f %f %f\n", z->numstation , z->max ,  z->moy ,  z->min);  
	parcourstemp1(z->fd,f); // on regarde dans le fils droit
	}	 
} 

void parcourstemp2(pAvl z , FILE* f)
{
	if(z!= NULL) 
	{ 
	
	parcourstemp2(z->fg, f); // on regarde dans le fils gauche 
	fprintf (f, "%d %d %d %d %f \n",  z->heure , z->jour , z->mois , z->annee, z->data );  
	parcourstemp2(z->fd,f); // on regarde dans le fils droit
	}	 
}



void parcourstemp3 (  pAvl a , FILE* f  , int *heure , int* jour , int* mois , int *annee  )
{
if (a!=NULL) 
{
 parcourstemp3 ( a->fg , f  , heure , jour , mois , annee);
 
 
 if (datedifferente(  *heure , *jour , *mois , *annee,  a->heure, a->jour ,a->mois , a->annee ) ==0 ) 
{

    fprintf (f, "\n%d/%d/%d/%d ", a->heure , a->jour ,a->mois , a->annee );
    *jour = a->jour;
    *heure = a->heure ; 
    *mois  = a->mois ; 
    *annee = a->annee;
}
 if (datedifferente(  *heure , *jour , *mois , *annee,  a->heure, a->jour ,a->mois , a->annee ) ==1);
{

    fprintf (f , "%f ", a->data );

}
 
    parcourstemp3 ( a->fd , f  , heure , jour , mois ,annee); 
 
 } 
}

void parcoursvect (pAvl z , FILE* f)
{
	if(z!= NULL) 
	{ 
    parcoursvect(z->fg, f); // on regarde dans le fils gauche  
	fprintf (f, "%f %f %f %f %f\n", z->longitude , z->latitude , z->x , z->y , z->data );  
	parcoursvect(z->fd,f); // on regarde dans le fils droit
	}	 
}
 
void parcours (pAvl z , FILE* f)
{
	if(z!=NULL) 
	{ 
	
	parcours(z->fg, f); // on regarde dans le fils gauche 
	 fprintf (f, "%f %f %f\n", z->longitude , z->latitude , z->data );  
	parcours(z->fd,f); // on regarde dans le fils droit

	}	 
}



void parcoursinvers (pAvl z , FILE* f)
{
	if(z!=NULL) 
	{ 
	
	parcoursinvers(z->fd,f); // on regarde dans le fils droit
	 fprintf (f, "%f %f %f\n", z->longitude , z->latitude , z->data );  
	parcoursinvers(z->fg, f); // on regarde dans le fils gauche 

	}	 
}

///////////////////////////////////////////////////////////////// fonctions par option ////////////////////////////////////////////////////////////////////////////



void humiditédata (int r)
{
pAvl z = NULL;
int x= 0;
int numstation=6;
float longi=6;
float lat =6;
float data;

FILE *m= fopen("humid.csv","r");
FILE *m2= fopen("m.txt","w"); 
int *h ;
while (fscanf(m ,"%d;%f;%f,%f\n " , &numstation , &data , &lat , &longi )!=EOF)
{


z=insertionAVL( z, 0 , 0 ,  data  , 0  ,0 , 0 , longi ,lat , 0  , 0  ,0 , 0, numstation , h);
}
if (r== 1)
parcours(z , m2);
else 
{
parcoursinvers(z , m2);
}
fclose(m2);

fclose(m);
}


void  vent()
{
pAvl z= NULL;

int numstation;
float longi;
float lat;
float data;
float angle;
float x , y ;

FILE *w= fopen("w.csv","r");
FILE *w2= fopen("w.txt","w"); 

int *h ;
while (fscanf(w ,"%d;%f;%f;%f,%f\n" , &numstation , &data ,  &angle , &lat , &longi )!=EOF)
{
x=cosf (angle) ;
y=sinf (angle);
z=insertionAVL( z, x, y,  data  , 0  ,0 , 0 , longi ,lat, 0 , 0 ,0 , 0, numstation , h);
}

parcoursvect(z , w2);
fclose(w2);
fclose(w);
}

void altitudedata(int r ) 
{


pAvl z= NULL;
int numstation;
float data ; 
float longi;
float lat ;
FILE *ALT= fopen("altitude.csv","r");
FILE *h= fopen("h.txt","w");

int *k;
while (fscanf(ALT ,"%d;%f,%f;%f\n" , &numstation , &longi , &lat , &data)!=EOF)
{


z=insertionAVL( z, 0 , 0 ,  data  , 0  ,0 , 0 , longi , lat, 0 , 0  ,0 , 0  , numstation , k );

}
 if (r==1) 
 {
parcours(z , h);
 }
 else 
 {
    parcoursinvers(z , h ) ;
 }
fclose(ALT);
fclose(h);
}

void  t1()
{
pAvl z= NULL;

float min ; 
float max ; 
float moy  ;
int numstation; 

FILE *t= fopen("t2.csv","r");
FILE *t2= fopen("t2.txt","w"); 
int *k ;

while (fscanf(t ,"%d;%f;%f;%f" , &numstation , &max ,&moy , &min  )!=EOF)
{

z=insertionAVLNumstat( z, 0 , 0 ,  0  , max  , moy, min , 0 ,0 , 0 , 0  ,0 , 0 , numstation , k);
}
parcourstemp1 (z ,t2  );
fclose(t) ; 
fclose(t2) ; 

}

void  t2()
{
pAvl z= NULL;
int numstation ; 
float data;
int jour ; 
int heure; 
int annee ; 
int mois;
int  poubelle ;
FILE *t= fopen("t2.csv","r");
FILE *t2= fopen("t2.txt","w"); 
int* k;

while (fscanf(t ,"%d-%d-%dT%d:%d:%d+%d:%d;%f\n" , &annee , &jour , &mois , &heure ,&poubelle , &poubelle ,&poubelle , &poubelle ,&data )!=EOF)
{

z= insertionAVLdate (z, 0 , 0 ,  data  , 0  ,0 , 0 , 0 ,0 , heure  , jour  ,mois  , annee , 0 , k);
}
parcourstemp2 ( z, t2 );
fclose(t) ; 
fclose(t2) ; 

}

void  t3()
{
pAvl z= NULL;
    float data;
    int jour; 
    int heure;
    int mois ; 
    int annee ;
    int numstation ;
   int a ;
     int b; 
    int c ;
    int d  ;
    a=1;
    b=-2;
   c=-3;
    d=-4;
int poubelle;
FILE *t= fopen("t3.csv","r");
FILE *t2= fopen("t3.txt","w"); 
int* k ;

while (fscanf(t ,"%d,%d-%d-%dT%d:%d:%d+%d:%d,%f\n", &numstation , &annee ,&mois , &jour ,&heure ,&poubelle , &poubelle , &poubelle , &poubelle ,&data ) !=EOF)
{
z=insertionAVLdate( z, 0 , 0 ,  data  , 0  ,0 , 0 , 0 ,0 , heure  , jour  ,mois  , annee , numstation , k );

}  

 parcourstemp3(z ,t2  ,&a  , &b  ,&c ,&d);

fclose(t) ; 
fclose(t2) ; 

}