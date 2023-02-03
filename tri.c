#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct arbre {
    int data;           // element du noeud
    float lat; 
    float longitude ; 
    int numstation;
    struct arbre* fg;   // pointeur sur fils gauche
    struct arbre* fd;   // pointeur sur fils droit
} Arbre;

typedef Arbre* pArbre;

typedef struct vect {
    float data;
    float x;
    float y;           // element du noeud
    float lat; 
    float longitude ; 
    int numstation;	 
    struct vect* fg;   // pointeur sur fils gauche
    struct vect* fd;   // pointeur sur fils droit
}Vect;

typedef Vect* pVect;

typedef struct temp{
    float data;
    int jour; 
    int heure;
    int mois ; 
    int annee ;
    int numstation ;
    struct temp* fg;   // pointeur sur fils gauche
    struct temp* fd;   // pointeur sur fils droit
}Temp;

typedef Temp* pTemp;

typedef struct temp1{
    float moy ; 
    float min ;
    float max ; 
    int  numstation ;
    struct temp1* fg;   // pointeur sur fils gauche
    struct temp1* fd;   // pointeur sur fils droit
}Temp1;

typedef Temp1* pTemp1;

pArbre creerArbre(int n, int numstation , float lat,float longitude) { // a pointeur sur l'arbre à créer et n l'élément à insérer; créer un arbre en initialisant ses fils et insere la valeur dans le noeud
    pArbre noeud = malloc(sizeof(Arbre)); // creation d'un nouveau noeud
    if(noeud == NULL) { // verification allocation
        exit(1); // si problème
    }
    noeud->longitude=longitude;
    noeud->lat=lat;
    noeud->numstation= numstation;
    
    noeud->data = n; // insere la valeur dans le noeud
    noeud->fg = NULL; // initialise le fils gauche à NULL
    noeud->fd = NULL; // initialise le fils droit à NULL
    return noeud;
}


pVect creerVect(float n, int numstation , float lat,float longitude , float x , float y  ) { // a pointeur sur l'arbre à créer et n l'élément à insérer; créer un arbre en initialisant ses fils et insere la valeur dans le noeud
    pVect noeud = malloc(sizeof(Vect)); // creation d'un nouveau noeud
    if(noeud == NULL) { // verification allocation
        exit(1); // si problème
    }
    noeud->x=x;
    noeud->y=y;
    noeud->longitude=longitude;
    noeud->lat=lat;
    noeud->numstation= numstation;
    
    noeud->data = n; // insere la valeur dans le noeud
    noeud->fg = NULL; // initialise le fils gauche à NULL
    noeud->fd = NULL; // initialise le fils droit à NULL
    return noeud;
}

pTemp creerTemp(float temp , int heure,int jour  ,int mois, int annee  , int numstation ) { // a pointeur sur l'arbre à créer et n l'élément à insérer; créer un arbre en initialisant ses fils et insere la valeur dans le noeud
    pTemp noeud = malloc(sizeof(Temp)); // creation d'un nouveau noeud
    if(noeud == NULL) { // verification allocation
        exit(1); // si problème
    }
   
 
    noeud->jour=jour;
    noeud->heure=heure;  
    noeud->annee=annee;
    noeud->mois = mois ;
    noeud->numstation=numstation  ; 
    noeud->data = temp; // insere la valeur dans le noeud
    noeud->fg = NULL; // initialise le fils gauche à NULL
    noeud->fd = NULL; // initialise le fils droit à NULL
    return noeud;
}

pTemp1 creerTemp1(int numstation , float max , float moy , float min)
{
    
	pTemp1 noeud = malloc(sizeof(Temp1)); // creation d'un nouveau noeud
	noeud->max=max ; 
	noeud->min =min ; 
	noeud->moy = moy;
    noeud->numstation = numstation ; 
    
	noeud->fg = NULL; // initialise le fils gauche à NULL
	noeud->fd = NULL; // initialise le fils droit à NULL
}

pArbre insertionABR(pArbre a, int alt, int  numstation ,  float lat, float longitude) 
{
  
  if(a==NULL) 
     {
  
    a=creerArbre(alt, numstation , lat,longitude);

        return a;
    } 
   
    else if(alt <= a->data ) 
    {
     
     a->fg = insertionABR(a->fg,alt, numstation , lat,longitude);
    } 
    
    else if(alt > a->data ) 
    {
  
        a->fd = insertionABR(a->fd, alt , numstation , lat, longitude );
    }  
    return a;
}


pVect insertionABRvect(pVect a, float data, int  numstation ,  float lat, float longitude , float x , float y ) 
{
  
  if(a==NULL) 
     {
  
    a=creerVect(data, numstation , lat,longitude, x , y );

        return a;
    } 
   
    else if(numstation<= a->numstation) 
    {
     
     a->fg = insertionABRvect(a->fg,data, numstation , lat,longitude , x , y);
    } 
    
    else if(numstation > a->numstation ) 
    {
  
        a->fd = insertionABRvect(a->fd, data , numstation , lat, longitude, x , y  );
    }  
    return a;
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

pTemp1 insertionTemp1(pTemp1 a, int numstation , float max , float moy , float min ) 
{
  
 
  if(a==NULL) 
     {
  
    a=creerTemp1(numstation , max , moy , min );

        return a;
    } 
   
    else if (a->numstation > numstation ) 
    {

      
     a->fg = insertionTemp1(a->fg,numstation , max , moy , min );
    } 
    
    else if(numstation > a->numstation) 
    {  
  
        a->fd = insertionTemp1(a->fd, numstation , max , moy , min  );
    }  
    return a;
}

   
    pTemp insertiontemp2(pTemp a, float temp , int heure  , int jour, int mois , int annee  , int numstation ) 
{
  
  if(a==NULL) 
     {
  
    a=creerTemp(temp, heure , jour , mois , annee , numstation  );

        return a;
    } 
   
    else if(datemin ( heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee )== 0) // on met le 1 car si il y a egalité ça ne fait rien 
    {
     
     a->fg = insertiontemp2(a->fg,temp, heure , jour , mois , annee ,numstation );
    } 
    
    else if(datemin(heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee ) == 1)
   {
        a->fd = insertiontemp2(a->fd,temp,  heure , jour , mois , annee  ,numstation  );
    }  
    return a;
} 
///::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://    
  

   pTemp insertiontemp3(pTemp a, float temp, int heure , int jour  , int mois, int annee  , int numstation) 
{
  
  if(a==NULL) 
     {

    a=creerTemp(temp,  heure , jour , mois , annee , numstation  );

        return a;
    } 
   
    else if(datemin ( heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee )== 0) // on met le 1 car si il y a egalité ça ne fait rien 
    {
     
     a->fg = insertiontemp3(a->fg,temp,   heure , jour , mois , annee , numstation );
    } 
    
    else if(datemin(heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee ) == 1)
   {
        a->fd = insertiontemp3(a->fd,temp,heure , jour  , mois , annee , numstation  );
    }  
    
   if (datemin(heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee ) == 22 &&  a->numstation >numstation )
	{
   	a->fg= insertiontemp3(a->fg,temp,   heure , jour , mois , annee , numstation  );
	} 
    else if(datemin(heure , jour , mois , annee, a->heure , a->jour , a->mois , a->annee ) == 22 && numstation > a->numstation )
    {
    a->fd = insertiontemp3(a->fd,temp,   heure , jour , mois , annee , numstation  );
    }	 
return a;
} 
    
 

void parcours (pArbre z , FILE* f)
{
	if(z!=NULL) 
	{ 
	
	parcours(z->fg, f); // on regarde dans le fils gauche 
	 fprintf (f, "%f %f %d\n", z->longitude , z->lat , z->data );  
	parcours(z->fd,f); // on regarde dans le fils droit
	}	 
}


void parcoursr (pArbre z , FILE* f)
{
	if(z!=NULL) 
	{ 
	
	parcoursr(z->fd,f); // on regarde dans le fils droit
	 fprintf (f, "%f %f %d \n", z->longitude , z->lat , z->data  );  
	parcoursr(z->fg, f); // on regarde dans le fils gauche 
	}	 
}

void parcoursvect (pVect z , FILE* f)
{
	if(z!= NULL) 
	{ 
    parcoursvect(z->fg, f); // on regarde dans le fils gauche  
	fprintf (f, "%f %f %f %f %f\n", z->x , z->y , z->data, z->lat,  z->longitude  ); 
	parcoursvect(z->fd,f); // on regarde dans le fils droit
	}	 
}

void parcoursvectr (pVect z , FILE* f)
{
	if(z!= NULL) 
	{
    parcoursvectr(z->fd,f); // on regarde dans le fils droit
    fprintf (f, "%f %f %f %f %f\n", z->x , z->y , z->data ,z->lat , z->longitude  );  
	parcoursvectr(z->fg, f); // on regarde dans le fils gauche  
	}	 
}





 


void parcourstemp1(pTemp1 z , FILE* f)
{
	if(z!= NULL) 
	{ 
	
    
	parcourstemp1(z->fg, f); // on regarde dans le fils gauche 
	fprintf (f, "%d %f %f %f\n", z->numstation , z->max ,  z->moy ,  z->min);  
	parcourstemp1(z->fd,f); // on regarde dans le fils droit
	}	 
} 

void parcourstemp1r(pTemp1 z , FILE* f)
{
	if(z!= NULL) 
	{ 
	parcourstemp1r(z->fd,f); // on regarde dans le fils droit
	
	fprintf (f, "%d %f %f %f\n", z->numstation , z->max ,  z->moy ,  z->min);  
	parcourstemp1r(z->fg, f); // on regarde dans le fils gauche 
	}	 
} 

void parcourstemp2(pTemp z , FILE* f)
{
	if(z!= NULL) 
	{ 
	
	parcourstemp2(z->fg, f); // on regarde dans le fils gauche 
    
	fprintf (f, "%d-%d-%dT%d %f \n",z->annee ,  z->mois , z->jour  ,  z->heure , z->data );  
	parcourstemp2(z->fd,f); // on regarde dans le fils droit
	}	 
}


void parcourstemp2r(pTemp z , FILE* f)
{
	if(z!= NULL) 
	{ 
	
	parcourstemp2r(z->fd,f); // on regarde dans le fils droit
	fprintf (f, "%d-%d-%dT%d %f \n",z->annee ,  z->mois , z->jour  ,  z->heure , z->data );  
	parcourstemp2r(z->fg, f); // on regarde dans le fils gauche 
	}	 
}

///////////////////////////////////////////////////////////////////////////////supression ///////////////////////////////////////////////////////////////////////////////

void suppresionabr( pArbre z )
{
  
   
    if (z!= NULL)
    {
        suppresionabr(z->fg) ; 
      suppresionabr(z->fd) ; 
      free (z);
    }
}


void suppresionvect( pVect z )
{
    
    if (z!= NULL)
    {
        suppresionvect(z->fg) ; 
   
        suppresionvect(z->fd) ;
         free (z)  ; 
    }
}

void suppresiontemp1( pTemp1 z )
{
   
    if (z!= NULL)
    {
        suppresiontemp1(z->fg) ; 
   
        suppresiontemp1(z->fd) ;
         free (z)  ; 
    }
}

void suppresiontemp( pTemp z )
{

    
    if (z!= NULL)
    {
        suppresiontemp(z->fg) ; 
        suppresiontemp(z->fd) ; 
        free (z) ;
    }
    
    
}      


//////////////////////////////////////////////////////////////////////////////// fonction par option ///////////////////////////////////////////////////////////////////
void humiditédata (int r , char entreefichier [20] , char sortiefichier[20])
{
pArbre z= NULL;
int x;
int numstation=0;
float longi;
float lat ;
int nouvelleval;

FILE *m= fopen(entreefichier,"r");
FILE *m2= fopen(sortiefichier,"w"); 

while (fscanf(m ,"%d %f %f\n", &nouvelleval , &lat , &longi )!=EOF)
{


z=insertionABR(z ,nouvelleval, numstation , longi  ,lat);
}


if (r== 1)
parcours(z , m2);
else 
{
parcoursr(z , m2);
}

suppresionabr( z );
fclose(m2);

fclose(m);
}


void  vent(int r , char entreefichier [20] , char sortiefichier[20])
{
pVect z= NULL;

int numstation;
float longi;
float lat;
float nouvelleval;

float x , y ;

FILE *w= fopen(entreefichier,"r");
FILE *w2= fopen(sortiefichier,"w"); 
 if (w==NULL)
 {
    printf(" erreur ouverture fichier d'entrée "); 
    exit (2);

 }

  if (w2==NULL)
 {
    printf(" erreur ouverture fichier de sortie"); 
    exit (3);
    
 }

while (fscanf(w ,"%d %f %f %f %f %f\n" , &numstation ,  &x , &y, &nouvelleval ,&longi , &lat  )!=EOF)
{

z=insertionABRvect(z ,nouvelleval, numstation , longi  ,lat, x , y);
}

if (r== 1)
parcoursvect(z , w2);
else 
{
parcoursvectr(z , w2);
}
suppresionvect(z);
fclose(w2);
fclose(w);
}

void altitudedata(int r , char entreefichier [20] , char sortiefichier[20] ) 
{


pArbre z= NULL;
int numstation=1;
float alt;
float longi;
float lat ;
FILE *ALT= fopen(entreefichier,"r");
FILE *h= fopen(sortiefichier,"w");
while (fscanf(ALT ,"%f %f %f\n " , &alt , &longi , &lat  )!=EOF)
{


z=insertionABR(z , alt, numstation , longi  ,lat);

}

 if (r==1) 
{
parcours(z , h);
 }
 else 
 {
parcoursr(z , h ) ;
 }

suppresionabr(z);
fclose(ALT);
fclose(h);
}

void  t1(int r , char entreefichier [20] , char sortiefichier[20])
{
pTemp1 z= NULL;

float min ; 
float max ; 
float moy  ;
int numstation; 

FILE *t= fopen(entreefichier,"r");
FILE *t2= fopen(sortiefichier,"w"); 


while (fscanf(t ,"%d %f %f %f\n" , &numstation, &min  , &max ,&moy  )!=EOF)
{

z=insertionTemp1(z , numstation , max , moy , min  );
}
 
 if (r==1) 
 {
parcourstemp1(z , t2 );
 }
 else 
 {
parcourstemp1r(z , t2 );
 }
 suppresiontemp1 (z);


 
 fclose(t) ; 
fclose(t2) ; 

}

void  t2(int r , char entreefichier [20] , char sortiefichier[20])
{
pTemp z= NULL;
int numstation = 0; 
float nouvelleval;
int jour ; 
int heure; 
int annee ; 
int mois;
int   poubelle;
FILE *t= fopen(entreefichier,"r");
FILE *t2= fopen(sortiefichier,"w"); 
int  w;
float k ;
int e;
float data ; 
 if (t==NULL)
 {
    printf(" erreur ouverture fichier d'entrée "); 
    exit (2);

 }

  if (t2==NULL)
 {
    printf(" erreur ouverture fichier de sortie"); 
    exit (3);
    
 }

while (fscanf(t ,"%d-%d-%dT%d:%d:%d+%d:%d %f\n" , &annee ,&mois , &jour ,&heure ,&poubelle , &poubelle , &poubelle , &poubelle, &nouvelleval) !=EOF){

z=insertiontemp2(z, nouvelleval , heure ,  jour , mois ,annee , 0); 
}

if (r==1) 
 {
parcourstemp2 ( z, t2 );

 }
 else 
 {
parcourstemp2r( z, t2 );
 }

suppresiontemp(z);
fclose(t) ; 
fclose(t2) ; 

}

void  t3(int r , char entreefichier [20] , char sortiefichier[20])
{
pTemp z= NULL;
   
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

if (t==NULL)
{

exit (2);

}
int i =0;

while (fscanf(t ,"%d %d-%d-%dT%d:%d:%d+%d:%d %f\n" ,&numstation ,  &annee ,&mois , &jour ,&heure ,&poubelle , &poubelle , &poubelle , &poubelle, &data ) !=EOF)
{
    i++;
   
z=insertiontemp3(z ,data ,  heure, jour , mois , annee , numstation  );

}  

if (r==1) 
 {


 }
 else 
 {

 }

suppresiontemp(z);
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