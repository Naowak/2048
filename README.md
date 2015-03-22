# 2048
Projet de EDD
-------------

- Avant de chercher à compiler quoi que ce soit, veillez a ce que les bibliothèques SDL-1.2 et SDL_Image soit installé sur votre machine.
- Sinon, sur linux, vous pouvez les installés avec les commandes suivantes :
	- sudo apt-get install libsdl1.2-dev   //Pour SDL-1.2
	- sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev  //Pour SDL_Image

- Dans le dossier principal (2048), creez un dossier build.
- Dans ce dossier, executez ensuite les commandes suivantes :
	- cmake ..
	- make
- Vous trouverez les bibiliothèques libgrid.a et libgraphics.a dans 2048/build/src

- Allez dans 2048/src
- Ici sont situés les trois executables :
	- grid_test permet de jouer dans la console
	- 2048_graphic permet de jouer dans un interface graphique (encore en création)
	- testRandom lance un algorithme qui va jouer de manière aléatoire

-------------

Erreurs connues et modifications a effectuées :

- Lorsque l'on test valgrind sur le 2048_graphics, on a pas mal de perte de mémoire. Il faut regarder où...



