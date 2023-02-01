#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct liste {
    float x;
    float y; 
    int altitude ;
    float humidité ; 
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

pListe creationChainon( float x ,float y, float data  ,float max  ,float moy  , float min  , float longitude ,float latitude , int jour ,int heure ,int mois  , int annee , int numstation )
{
 pListe noeud = malloc(sizeof(Pliste)); // creation d'un nouveau noeud
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

return noeud ; 
}

pListe insertdebut( pListe N , float x ,float y  ,float data,float max  ,float moy  , float min  , float longitude ,float latitude , int jour ,int heure ,int mois  , int annee , int numstation )
{
pListe k =  creationChainon (x , y , altitude ,humidité , max  , moy  ,  min  ,  longitude , latitude ,  jour , heure , mois  ,  annee ,  numstation )
k ->suivant =N ; 

return k;
}


insertionliste ( pListe N , float x ,float y  ,float data,float max  ,float moy  , float min  , float longitude ,float latitude , int jour ,int heure ,int mois  , int annee , int numstation )
{
     if (N==NULL )
{
     return creationChainon (x , y , altitude ,humidité , max  , moy  ,  min  ,  longitude , latitude ,  jour , heure , mois  ,  annee ,  numstation );
// on retourne le chainon car la liste est vide
}
else 
{
    pListe z = N ; 
    pListe k = creationChainon (x , y , altitude ,humidité , max  , moy  ,  min  ,  longitude , latitude ,  jour , heure , mois  ,  annee ,  numstation );
  while (z->suivant != NULL)
   {
    if ( k == z)
   {
    return  N ; // si le chainon existe deja on ne le rentre pas 
   }
    z=z->suivant ; 
   }
   z->suivant = k ; // o n rentre le nouveaux chainons dans la liste 
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
	if(z->suivant!= NULL) 
	{ 
	
	    fprintf (f, "%d %d %d %d\n", z->numstation , z->max ,  z->moy ,  z->min);  
	
	}	 
} 

void parcourstemp2(pListe z , FILE* f)
{
	if(z->suivant!= NULL) 
	{ 

	    fprintf (f, "%d %d %d %d %f \n",  z->heure , z->jour , z->mois , z->annee, z->data );  

	}	 
}

void parcoursT3 (  pListe  a , FILE* f  , int *heure , int* jour , int* mois , int *annee  )
{
if (a->suivant !=NULL) 
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
 }
 } 
 

void parcours (pListe  z , FILE* f)
{
	if(z->suivant!=NULL) 
	{ 
	
	 fprintf (f, "%f %f %d\n", z->longitude , z->latitude , z->data );  
	
	}	 
}

void parcoursvect (pListe z , FILE* f)
{
	if(z->suivant!= NULL) 
	{ 

	fprintf (f, "%f %f %f %f %d\n", z->longitude , z->latitude , z->x , z->y , z->data );  
	
	}	 
}

void parcoursinverse (pListe data, File* F )
{
    while (data->suivant!= NULL  )
    {   fseek(f, 0 ,  SEEK_SET); 
         fprintf (f, "%f %f %d\n", z->longitude , z->latitude , z->data );  
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
    if (a->data <= b->data)
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
 
int main(void)
{
   
 
    // trie la liste
    mergesort(&head);
 
   
 
    return 0;
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
    if (a->numstation <= b->numstation)
    {
        result = a;
        result->suivant = sortedMerge(a->suivant, b);
    }
    else {
        result = b;
        result->suivant= sortedMerge(a, b->suivant );
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
    if (datemin (a->heure  , a->jour , a->mois, a->annee ,b->heure  ,b->jour , b->mois ,b->annee ,) == 0 || (datemin (a->heure  , a->jour , a->mois, a->annee ,b->heure  ,b->jour , b->mois ,b->annee ,) == 22  )
    // si la date de a est plus  petite ou egale alors 
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
 
/////////////////////////////////////////// Fonctions par option ///////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
   
 
    // trie la liste
    mergesort(&head);
 
   
 
    return 0;
}