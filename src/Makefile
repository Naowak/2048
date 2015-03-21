CC= gcc
CFLAGS= -std=c99 -Wall -Werror -g
OUTFILE1= grid_test
OUTFILE2= testRandom
OUTFILE3= 2048_graphics
OBJS1= grid_test.o
OBJS2= testRandom.o
OBJS3= 2048_graphics.o
LDLIB= -lgrid -lgraphics -lm -lSDL -lSDL_image              #-lSDL_ttf pour charger la bibliotheque pour ecrire
LDFLAGS= -L ../build/src

all : test1 test2 jeu_graphique

test1 : $(OUTFILE1)
test2 : $(OUTFILE2)
jeu_graphique : $(OUTFILE3)

$(OUTFILE1): $(OBJS1)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

$(OUTFILE2): $(OBJS2)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

$(OUTFILE3): $(OBJS3)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OUTFILE1) $(OUTFILE2) $(OUTFILE3)
