### Projet-Meteo

## INFORMATIONS GÉNÉRALES

Le projet "nom du projet" permet depuis un fichier de données météo de les trier selon certaines conditions et de dessiner des graphiques. Le projet utilise un script en shell et un programme en c.

## UTILISATION

Pour lancer le programme:

  $ bash projet.sh <options>

Le script a besoin de plusieures options pour fonctionner. Vous pouvez les saisir dans l'odre que vous voulez.
Les options possibles pour le script sont de deux types: les données obligatoires et les données facultatives.

## OPTIONS OBLIGATOIRES

# TYPE DE DONNÉES

Les options de type de données sont:

	-t pour la température
	-p pour la pression atmosphérique
	-w pour le vent
	-h pour l'altitude
	-m pour l'humidité

Ces options servent à savoir quel type de données vous voulez traiter. 
Les options -t et -p doivent être accomapgné du mode 1, 2, 3.
Un seul mode pour la température peut être exécuté. On peut pas faire -t1 et -t2 dans la même exécution.
Le dernier mode sera pris en compte.
Au moins l'une de ces options doivent être présentes pour que le script fonctionne.
Il n'y a pas de limite quant à l'utilisation de ces options.
Vous pouvez demandez de traiter la température, le vent et l'altitude en une seule fois.

# FICHIER

L'option de fichier est:

	-f<nom_fichier>
	
Cette option sert à connaître le nom du fichier d'entré pour que le script puisse acquérir toutes les données.
Cette option est obligatoire pour que le script fonctionne.

## OPTIONS FACULTATIVES

# LIEUX

Les options de lieux sont:

	-F pour la France
	-G pour la Guyane
	-S pour Saint-Pierre et Miquelon
	-A pour les Antilles
	-O pour l'océan Indien
	-Q pour l'Antarctique

Ces options servent à savoir si vous voulez filtrer selon un lieux en particulier.
Ces options ne sont pas obligatoires, si aucune n'est renseignée il n'y aura pas de filtre selon le lieux.
Seule une option de lieux est possible à la fois.
Si plusieurs options sont renseignées, la première selon l'ordre ci-dessus est prise en compte.

# DATE

L'options de date:

	-d<min><max>

Cette option sert à savoir si vous voulez filtrer selon une date en particulier.
Cette option n'est pas obligatoire, si elle n'est pas renseignée il n'y aura pas de filtre selon la date.
Le format des dates est une chaine de caractère de la forme : AAAA-MM-JJ (année-mois-jour).
Pour séparer les deux dates, veuillez utiliser le caractère "/", sinon la date ne sera pas prise en compte.
Veuillez faire attention car certaine station n'ont pas de données pendant une période donnée.

# TRI

Les options de tri sont:

	-T ou --tab
	-R ou --abr
	-L ou --avl

Ces options servent à savoir si vous voulez trier d'une certaine manière.
Ces options ne sont pas obligatoires, si aucune n'est renseignée le tri sera fait à l'aide d'un AVL.
Seule une option de tri est possible à la fois.
Si plusieurs options sont renseignées, la première selon l'ordre ci-dessus est prise en compte.

# HELP

L'option d'aide est:

	--help

Cette option permet d'avoir des informations sur le script et comment l'utiliser.
Cette option doit être renseignée seule pour fonctionner.

## EXEMPLE DE LANCEMENT

Exemple d'utilisation:


$ bash projet.sh -fdata.csv -d2015-8-25/2018-6-28 -h -p1 -G --abr


	-fdata.csv : le script utilise les données provenant du fichier data.csv.
	
	-d2015-8-25/2018-6-28 : le script ne prend en compte que les données entre le 25-8-2015 et le 28-6-2018.
	
	-h : le script traite les donneés de l'altitude.
	
	-p1 : le script traite les donneés de la pression en mode 1.
	
	-G : le script ne prend en compte que les données provenant de Guyane.
	
	--abr : le script fait le tri avec un ABR.

## ERREURS POSSIBLES EN SHELL

Le script retourne des valeurs différentes si l'exécution s'est bien déroulée:

	- 0: tout c'est bien passé
	- 1: erreur argument
	- 2: erreur sur le fichier d'entré
	- 3: erreur sur la date

## COMMUNICATION AVEC LE C

Après avoir crée les fichiers nécessaires. Le script shell les envoie au programme c avec les options suivantes:

	-f<nom du fichier d'entré>
	-o<nom du fichier de sortie>

L'option -f permet au programme de savoir depuis quel fichier récupérer les données.
Le programme tri les données selon le mode de tri choisi.
Puis les envoie dans un fichier de sorti connu grâce à l'option -o.

Une autre option est possible:

	-r

L'option -r permet de faire un tri inverse.

## PRODUCTION DES DIAGRAMMES

Le script shell récupère les fichiers sortis pour en faire des diagrammes grâce à Gnuplot.
Le type de diagramme dépend des types de données:

	-t1 et p1: diagramme de type barre d'erreur
	-t2 et p2: diagramme de type ligne simple
	-t3 et p3: diagramme de type multi-lignes
	-w: diagramme de type vecteurs
	-h: diagramme de type carte interpolée et colorée
	-m: diagramme de type carte interpolée et colorée

## CRÉATEURS

Binôme composé de Guillaume BARRÉ(aka Auxifruit) et Lucas BEZAMAT(aka Luczerty) en PRÉING 2 MI GROUPE 4
