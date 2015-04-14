# 2048
Projet de EDD
-------------
- Dans le dossier principal (2048), creez un dossier build.
- Dans ce dossier, executez ensuite les commandes suivantes :
	- cmake ..
	- make
- Vous trouverez les bibiliothèques libgrid.a et libgraphics.a dans 2048/build/src

- Allez dans 2048/src
- Vous pouvez utilisez la commande make pour compiler grid_test qui est permet de jouer sur la console, et testRandom qui joue seul de manière aléatoire.

- Pour l'interface graphique : veillez a ce que les bibliothèques SDL-1.2, SDL_Image et SDL_ttf soit installés sur votre machine.
- Sinon, sur linux, vous pouvez les installés avec les commandes suivantes :
	- sudo apt-get install libsdl1.2-dev   //Pour SDL-1.2
	- sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev  //Pour SDL_Image
	- sudo apt-get install libsdl-ttf2.0-dev //Pour SDL_ttf
- Utilisez ensuite " make graphic " pour compiler l'interface graphique.

------------

Les stratégies :

Pour créer le .so
	- gcc -c -Wall -Werror -fpic nomlib.c
	- gcc -shared -o nomlib.so nomlib.o

-------------

Ce qu'il reste à faire :
- Dans l'interface graphique :
	- Afficher quand l'utilisateur à gagner (a fait 2048). (Facile)
- Ajouter des stratégies, de manière propre ! 



