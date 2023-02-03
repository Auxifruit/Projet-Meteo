# Projet-Meteo


## Table des matières
1. [INFORMATIONS GÉNÉRALES](#informations-générales)
2. [UTILISATION](#utilisation)
3. [OPTIONS OBLIGATOIRES](#options-obligatoires)
4. [OPTIONS FACULTATIVES](#options-facultatives)
5. [TYPE DE DONÉES](#type-de-données)
6. [LIEUX](#lieux)
7. [DATE](#date)
8. [TRI](#tri)
9. [FICHIER](#fichier)
10. [EXEMPLE DE LANCEMENT](#exemple-de-lancement)
11. [ERREURS POSSIBLES EN SHELL](#erreurs-possibles-en-shell)
12. [CRÉATEURS](#créateurs)

## INFORMATIONS GÉNÉRALES

Le projet "nom du projet" permet depuis un fichier de données météo de les trier selon certaines conditions et de dessiner des graphiques. Le projet utilise un script en shell et un programme en c.

## UTILISATION

Pour lancer le programme:
```bash
  $ bash projet.sh <options>
```
Le script a besoin de plusieures options pour fonctionner. Vous pouvez les saisir dans l'odre que vous voulez.
Les options possibles pour le script sont de deux types: les données obligatoires et les données facultatives.

## OPTIONS OBLIGATOIRES

### TYPE DE DONNÉES

Les options de type de données sont:

	-t pour la température
	-p pour la pression atmosphérique
	-w pour le vent
	-h pour l'altitude
	-m pour l'humidité

Ces options servent à savoir quel type de données vous voulez traiter. <br />
Les options -t et -p doivent être accomapgné du mode 1, 2, 3. <br />
Un seul mode pour la température peut être exécuté. On peut pas faire -t1 et -t2 dans la même exécution. <br />
Le dernier mode sera pris en compte. <br />
Au moins l'une de ces options doivent être présentes pour que le script fonctionne. <br />
Il n'y a pas de limite quant à l'utilisation de ces options. <br />
Vous pouvez demandez de traiter la température, le vent et l'altitude en une seule fois. <br />

### FICHIER

L'option de fichier est:

	-f<nom_fichier>
	
Cette option sert à connaître le nom du fichier d'entré pour que le script puisse acquérir toutes les données. <br />
Cette option est obligatoire pour que le script fonctionne. <br />

## OPTIONS FACULTATIVES

### LIEUX

Les options de lieux sont:

	-F pour la France
	-G pour la Guyane
	-S pour Saint-Pierre et Miquelon
	-A pour les Antilles
	-O pour l'océan Indien
	-Q pour l'Antarctique

Ces options servent à savoir si vous voulez filtrer selon un lieux en particulier. <br />
Ces options ne sont pas obligatoires, si aucune n'est renseignée il n'y aura pas de filtre selon le lieux. <br />
Seule une option de lieux est possible à la fois. <br />
Si plusieurs options sont renseignées, la première selon l'ordre ci-dessus est prise en compte. <br />

### DATE

L'options de date:

	-d<min><max>

Cette option sert à savoir si vous voulez filtrer selon une date en particulier. <br />
Cette option n'est pas obligatoire, si elle n'est pas renseignée il n'y aura pas de filtre selon la date. <br />
Le format des dates est une chaine de caractère de la forme : AAAA-MM-JJ (année-mois-jour). <br />
Les données vont de 2010 à 2022. <br />
Pour séparer les deux dates, veuillez utiliser le caractère "/", sinon la date ne sera pas prise en compte. <br />

### TRI

Les options de tri sont:

	-T ou --tab
	-R ou --abr
	-L ou --avl

Ces options servent à savoir si vous voulez trier d'une certaine manière. <br />
Ces options ne sont pas obligatoires, si aucune n'est renseignée le tri sera fait à l'aide d'un AVL. <br />
Seule une option de tri est possible à la fois. <br />
Si plusieurs options sont renseignées, la première selon l'ordre ci-dessus est prise en compte. <br />

### HELP

L'option d'aide est:

	--help

Cette option permet d'avoir des informations sur le script et comment l'utiliser. <br />
Cette option doit être renseignée seule pour fonctionner. <br />

### EXEMPLE DE LANCEMENT

Exemple d'utilisation:

```bash
$ bash projet.sh -fdata.csv -d2015-12-8/2016-5-25 -h -p1 -S --abr
```

	-fdata.csv : le script utilise les données provenant du fichier data.csv.
	
	-d2015-12-8/2016-5-25 : le script ne prend en compte que les données entre le 8-12-2015 et le 25-5-2016.
	
	-h : le script traite les donneés de l'altitude.
	
	-p1 : le script traite les donneés de la pression en mode 1.
	
	-S : le script ne prend en compte que les données provenant de Saint-Pierre et Miquelon.
	
	--abr : le script fait le tri avec un ABR.

### ERREURS POSSIBLES EN SHELL

Le script retourne des valeurs différentes si l'exécution s'est bien déroulée:

	- 0: tout c'est bien passé
	- 1: erreur argument
	- 2: erreur sur le fichier d'entré
	- 3: erreur sur la date

## CRÉATEURS

Binôme composé de Guillaume BARRÉ(aka Auxifruit) et Lucas BEZAMAT(aka Luczerty) en PRÉING 2 MI GROUPE 4
