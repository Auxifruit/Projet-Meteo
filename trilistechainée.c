#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
typedef struct liste {
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
    struct liste* suivant ;
} Liste;


typedef Liste* pListe ; 

pListe creationChainon( float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation )
{
 pListe noeud = malloc(sizeof(Liste)); // creation d'un nouveau noeud
    if(noeud == NULL) { // verification allocation
        exit(1); // si problème
    }
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

    noeud->suivant=NULL;
return noeud ; 
}



pListe insertionliste ( pListe N , float x ,float y  ,float data,float max  ,float moy  , float min  , float longitude ,float latitude  ,int heure , int jour,int mois  , int annee , int numstation )
{

 
     if (N==NULL )
{
     return creationChainon (x , y , data, max  , moy  ,  min  ,  longitude , latitude  , heure,  jour , mois  ,  annee ,  numstation );
// on retourne le chainon car la liste est vide
}
else 
{
    pListe z = N ; 
    pListe k = creationChainon (x , y , data , max  , moy  ,  min  ,  longitude , latitude , heure,  jour  , mois  ,  annee ,  numstation );
  while (z->suivant != NULL)
   {
    if ( k == z)
   {
    return  N ; // si le chainon existe deja on ne le rentre pas 
   }
    z=z->suivant ; 
   }
   z->suivant = k ; // o n rentre le nouveaux chainons dans la liste 
   return N;
}
}
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
    return 1;// retourne 1 si annee 2 plus vieille 
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
///////////////////////////////// parocurs liste //////////////////////////////////////////

void parcourstemp1(pListe z , FILE* f)
{
	if(z!= NULL) 
	{ 
	    fprintf (f, "%d %f %f %f\n", z->numstation , z->max ,  z->moy ,  z->min);  
        parcourstemp1(z->suivant, f);
	
	}	 
} 




void parcourstemp2(pListe z , FILE* f)
{
	if(z!= NULL) 
	{ 

	fprintf (f, "%d-%d-%dT%d %f \n",z->annee ,  z->mois , z->jour  ,  z->heure , z->data );  
parcourstemp2(z->suivant, f ); 
	}	 
}




void parcourstemp3 (  pListe  a , FILE* f  , int *heure , int* jour , int* mois , int *annee  )
{
if (a!=NULL) 
{
 
 
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
parcourstemp3 (a->suivant , f , heure , jour , mois , annee);
 }
 } 
 

 
void parcours (pListe  z , FILE* f)
{
	if(z!=NULL) 
	{ 
	
	  fprintf (f, "%f %f %f\n", z->longitude , z->latitude , z->data ); 
	parcours (z->suivant , f);
	}	 
}



void parcoursvect (pListe z , FILE* f)
{
	if(z!= NULL) 
	{ 
    
	fprintf (f, "%f %f %f %f %f\n",  z->x , z->y , z->data ,z->longitude , z->latitude);  
	parcoursvect(z->suivant , f);
	}	 
}



////////////////////////////////////////////  tri rapide  s/o tech de light ///////////////////////////////////


pListe  sortedMerge(pListe a, pListe  b)
{
    // cas de base
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    pListe result = NULL;
 
    // sélectionne `a` ou `b`, et se reproduit
    if (a->data < b->data)
    {
        result = a;
        result->suivant = sortedMerge(a->suivant, b);
    }
    else {
        result = b;
        result->suivant = sortedMerge(a, b->suivant );
    }
 
    return result;
}
 
/*
    Diviser les nœuds de la liste donnée en moitiés avant et arrière
    et retourner les deux listes en utilisant les paramètres de référence.
    Si la longueur est impaire, le nœud supplémentaire doit aller dans la première liste.
    Il utilise la stratégie de pointeur rapide/lent
*/
void frontBackSplit(pListe source, pListe* frontRef,
                    pListe* backRef)
{
    // si la longueur est inférieure à 2, traitez-la séparément
    if (source == NULL || source->suivant == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    pListe slow = source;
    pListe fast = source->suivant;
 
    // avance `fast` de deux nœuds et avance `slow` d'un nœud
    while (fast != NULL)
    {
        fast = fast->suivant;
        if (fast != NULL)
        {
            slow = slow->suivant;
            fast = fast->suivant;
        }
    }
 
    // `slow` est avant le milieu de la liste, donc divisez-le en deux
    // à ce moment.
    *frontRef = source;
    *backRef = slow->suivant;
    slow->suivant = NULL;
}
 
// Trier une liste chaînée donnée à l'aide de l'algorithme de tri par fusion
void mergesort(pListe* head)
{
    // cas de base — longueur 0 ou 1
    if (*head == NULL || (*head)->suivant == NULL) {
        return;
    }
 
    pListe a;
    pListe b;
 
    // divise `head` en sous-listes `a` et `b`
    frontBackSplit(*head, &a, &b);
 
    // trie récursivementment les sous-listes
    mergesort(&a);
    mergesort(&b);
 
    // réponse = fusionner les deux listes triées
    *head = sortedMerge(a, b);
}
 


/////////////////////// tri pour le numstation ///////////////////////////////////////////////////////////////////////////


pListe  sortedMergenumst(pListe a, pListe  b)
{
    // cas de base
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    pListe result = NULL;
 
    // sélectionne `a` ou `b`, et se reproduit
    if (a->numstation < b->numstation)
    {
        result = a;
        result->suivant = sortedMergenumst (a->suivant, b);
    }
    else {
        result = b;
        result->suivant= sortedMergenumst(a, b->suivant );
    }
 
    return result;
}
 
/*
    Diviser les nœuds de la liste donnée en moitiés avant et arrière
    et retourner les deux listes en utilisant les paramètres de référence.
    Si la longueur est impaire, le nœud supplémentaire doit aller dans la première liste.
    Il utilise la stratégie de pointeur rapide/lent
*/
void frontBackSplitnumst(pListe source, pListe* frontRef,
                    pListe* backRef)
{
    // si la longueur est inférieure à 2, traitez-la séparément
    if (source == NULL || source->suivant == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    pListe slow = source;
    pListe fast = source->suivant;
 
    // avance `fast` de deux nœuds et avance `slow` d'un nœud
    while (fast != NULL)
    {
        fast = fast->suivant;
        if (fast != NULL)
        {
            slow = slow->suivant ;
            fast = fast->suivant ;
        }
    }
 
    // `slow` est avant le milieu de la liste, donc divisez-le en deux
    // à ce moment.
    *frontRef = source;
    *backRef = slow->suivant ;
    slow->suivant  = NULL;
}
 
// Trier une liste chaînée donnée à l'aide de l'algorithme de tri par fusion
void mergesortnumst(pListe* head)
{
    // cas de base — longueur 0 ou 1
    if (*head == NULL || (*head)->suivant  == NULL) {
        return;
    }
 
    pListe a;
    pListe b;
 
    // divise `head` en sous-listes `a` et `b`
    frontBackSplitnumst(*head, &a, &b);
 
    // trie récursivementment les sous-listes
    mergesortnumst(&a);
    mergesortnumst(&b);
 
    // réponse = fusionner les deux listes triées
    *head = sortedMergenumst(a, b);
}
 

/////////////////////////////////////////////////////////////////// tri  date ///////////////////////////////////////////

pListe  sortedMergedate(pListe a, pListe  b)
{
    // cas de base
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    pListe result = NULL;
 
    // sélectionne `a` ou `b`, et se reproduit
    if (datemin (a->heure  , a->jour , a->mois, a->annee ,b->heure  ,b->jour , b->mois ,b->annee ) == 0 || datemin (a->heure  , a->jour , a->mois, a->annee ,b->heure  ,b->jour , b->mois ,b->annee ) == 22  )
    // si la date de a est plus  petite ou egale alors 
    {
        result = a;
        result->suivant = sortedMergedate(a->suivant, b);
    }
    else {
        result = b;
        result->suivant = sortedMergedate(a, b->suivant );
    }
 
    return result;
}
 
/*
    Diviser les nœuds de la liste donnée en moitiés avant et arrière
    et retourner les deux listes en utilisant les paramètres de référence.
    Si la longueur est impaire, le nœud supplémentaire doit aller dans la première liste.
    Il utilise la stratégie de pointeur rapide/lent
*/
void frontBackSplitdate(pListe source, pListe* frontRef,
                    pListe* backRef)
{
    // si la longueur est inférieure à 2, traitez-la séparément
    if (source == NULL || source->suivant == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    pListe slow = source;
    pListe fast = source->suivant;
 
    // avance `fast` de deux nœuds et avance `slow` d'un nœud
    while (fast != NULL)
    {
        fast = fast->suivant;
        if (fast != NULL)
        {
            slow = slow->suivant;
            fast = fast->suivant;
        }
    }
 
    // `slow` est avant le milieu de la liste, donc divisez-le en deux
    // à ce moment.
    *frontRef = source;
    *backRef = slow->suivant;
    slow->suivant = NULL;
}
 
// Trier une liste chaînée donnée à l'aide de l'algorithme de tri par fusion
void mergesortdate (pListe* head)
{
    // cas de base — longueur 0 ou 1
    if (*head == NULL || (*head)->suivant == NULL) {
        return;
    }
 
    pListe a;
    pListe b;
 
    // divise `head` en sous-listes `a` et `b`
    frontBackSplitdate(*head, &a, &b);
 
    // trie récursivementment les sous-listes
    mergesortdate(&a);
    mergesortdate(&b);
 
    // réponse = fusionner les deux listes triées
    *head = sortedMergedate(a, b);
}

/////////////////////////////////////////// Supp liste /////////////////////////////////////////////////////////////////////////////////////////////////////

void suppliste(pListe z  )
{
   pListe k = z ; 
    if (z!= NULL)
    {
        z=z->suivant;
    
      free (k);
      suppliste (z);
    }
}



//////////////////////////// inverse liste ///////////////////////////////////////////////////

void reverse2 (pListe* tete)
 {
    pListe nouveau = NULL ; 
    pListe actue = *tete ; 
    pListe suivants ;
    while (actue !=NULL)
    {
        suivants = actue->suivant ; 

        actue->suivant = nouveau ;

        nouveau=actue ;
        actue = suivants ;
    }
    *tete = nouveau;
 }
/////////////////////////////////////////// Fonctions par option ///////////////////////////////////////////////////////////////////////////////////////////


void humiditédata (int r , char entreefichier [20] , char sortiefichier[20])
{
pListe z= NULL;
int x= 0;
int numstation=6;
float longi=6;
float lat =6;
float data;

FILE *m= fopen(entreefichier,"r");
FILE *m2= fopen(sortiefichier,"w"); 

while (fscanf(m ,"%f %f %f\n " , &data , &lat , &longi )!=EOF)
{


z=insertionliste( z, 0 , 0 ,  data  , 0  ,0 , 0 , longi ,lat , 0  , 0  ,0 , 0, numstation);
}
mergesort(&z) ; 
if (r== 1)
parcours(z , m2);
else 
{
    reverse2(&z);
parcours(z , m2);
}
suppliste( z) ;
fclose(m2);

fclose(m);
}


void  vent(int r , char entreefichier [20] , char sortiefichier[20])
{
pListe z= NULL;

int numstation;
float longi;
float lat;
float data;
float angle;
float x , y ;

FILE *w= fopen(entreefichier,"r");
FILE *w2= fopen(sortiefichier,"w"); 


while (fscanf(w ,"%d %f %f %f %f %f\n" , &numstation ,  &x , &y, &data , &longi, &lat  )!=EOF)
{

z=insertionliste( z, x, y,  data  , 0  ,0 , 0 , longi ,lat, 0 , 0 ,0 , 0, numstation);
}

mergesortnumst(&z) ; 

if (r== 1)
{
parcoursvect (z , w2);
}
else 
{
    reverse2(&z);
    parcoursvect(z, w2);

}


suppliste( z) ;
fclose(w2);
fclose(w);
}

void altitudedata(int r , char entreefichier [20] , char sortiefichier[20]) 
{

pListe z= NULL;
int numstation=0;
float data;
float longi;
float lat ;

FILE *ALT= fopen(entreefichier,"r");
FILE *h= fopen(sortiefichier,"w");  
while (fscanf(ALT ,"%f %f %f \n " ,&data ,  &longi , &lat )!=EOF)
{

z=insertionliste( z, 0 , 0 ,  data  , 0  ,0 , 0 , longi , lat, 0 , 0  ,0 , 0  , numstation);

}

mergesort(&z);

 if (r==1) 
 {
 
    parcours(z , h);
 }
 else 
 { 
reverse2(&z); 
parcours(z, h ) ;

 } 
 suppliste( z);

fclose(ALT);
fclose(h);
}


void  t1(int r , char entreefichier [20] , char sortiefichier[20])
{
pListe z= NULL;

float min ; 
float max ; 
float moy  ;
int numstation; 

FILE *t= fopen(entreefichier,"r");
FILE *t2= fopen(sortiefichier,"w"); 


while (fscanf(t ,"%d %f %f %f" , &numstation , &min , &max ,&moy  )!=EOF)
{
 

z=insertionliste( z, 0 , 0 ,  0  , max  , moy, min , 0 ,0 , 0 , 0  ,0 , 0 , numstation);
}

mergesortnumst(&z);
if (r== 1)
{
parcourstemp1 (z ,t2  );

}
else 
{
    reverse2 (&z);
parcourstemp1( z , t2);
}
suppliste( z) ;

fclose(t) ; 
fclose(t2) ; 

}

void  t2(int r , char entreefichier [20] , char sortiefichier[20])
{
pListe z= NULL;
int numstation = 0; 
float data;
int jour ; 
int heure; 
int annee ; 
int mois ;
int  poubelle;
FILE *t= fopen(entreefichier,"r");
FILE *t2= fopen(sortiefichier,"w"); 


while (fscanf(t ,"%d-%d-%dT%d:%d:%d+%d:%d %f\n"  , &annee , &mois , &jour , &heure ,&poubelle ,&poubelle ,&poubelle , &poubelle,&data )!=EOF)
{
     
z=insertionliste(z, 0 , 0 ,  data  , 0  ,0 , 0 , 0 ,0 , heure  , jour  ,mois  , annee , 0);
}
mergesortdate(&z); 
if (r== 1)
{

parcourstemp2 (z ,t2 );
}
else 
{
    reverse2 (&z);
parcourstemp2 (z ,t2);
}
suppliste( z) ;
fclose(t) ; 
fclose(t2) ; 

}

void  t3(int r , char entreefichier [20] , char sortiefichier[20])
{
pListe z= NULL;
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
FILE *t= fopen(entreefichier,"r");
FILE *t2= fopen(sortiefichier,"w"); 


while (fscanf(t ,"%d %d-%d-%dT%d:%d:%d+%d:%d %f", &numstation , &annee ,&mois , &jour ,&heure ,&poubelle , &poubelle , &poubelle , &poubelle ,&data ) !=EOF)
{
z=insertionliste( z, 0 , 0 ,  data  , 0  ,0 , 0 , 0 ,0 , heure  , jour  ,mois  , annee , numstation);

}  
mergesortdate(&z);
if (r== 1)
{

parcourstemp3 (z ,t2  ,&a  , &b  ,&c ,&d);
}
else 
{
    reverse2 (&z);
parcourstemp3 (z ,t2  ,&a  , &b  ,&c ,&d);
}

suppliste( z) ;
fclose(t) ; 
fclose(t2) ; 

}

int main (int argc , char * argv[] )
{ 

    
char* entreefichier ;
char* sortiefichier ;
int r =1 ; 
for (int i ; i<argc ;i++)
{
if ( strcmp ("r" , argv[i]) == 0)
{
    r=100 ; 
}

if ( strcmp ("f" , argv[i])== 0)
{
 entreefichier = argv[i+1]; 
}

if ( strcmp ("o" , argv[i])== 0)
{
 sortiefichier = argv[i+1]; 
}

// choix du tri 
if ( strcmp ("w" , argv[i])== 0)
{
    vent( r , entreefichier , sortiefichier);
}
else if (  strcmp ("t1" , argv[i])== 0)
{
    t1(r , entreefichier ,  sortiefichier);
}
else if (  strcmp ("t2" , argv[i])== 0)
{
    t2(r , entreefichier ,  sortiefichier );
}
else if (  strcmp ("t3" , argv[i])== 0)
{
    t3(r , entreefichier, sortiefichier );
}
else if (strcmp("h" , argv[i]) == 0)
{
    altitudedata(r , entreefichier ,sortiefichier);
}
else if (strcmp("m" , argv[i]) == 0)
{
    humiditédata (r , entreefichier ,sortiefichier );
}
else if (  strcmp ("p1" , argv[i])== 0)
{
    t1(r , entreefichier, sortiefichier);
}
else if (  strcmp ("p2" , argv[i])== 0)
{
    t2(r ,entreefichier ,  sortiefichier );
}
else if (  strcmp ("p3" , argv[i])== 0)
{
    t3(r , entreefichier, sortiefichier );
}
else
{

}


}
 return 0;
}