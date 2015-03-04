CC= gcc
CFLAGS= -std=c99 -Wall -Werror -g
OUTFILE1= grid_test
OUTFILE2= testRandom
OBJS1= grid_test.o
OBJS2= testRandom.o
LDLIB= -lgrid -lm
LDFLAGS= -L ../build/src

all : test1 test2

test1 : $(OUTFILE1)
test2 : $(OUTFILE2)

$(OUTFILE1): $(OBJS1)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

$(OUTFILE2): $(OBJS2)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS) $(OUTFILE1) $(OUTFILE2)
