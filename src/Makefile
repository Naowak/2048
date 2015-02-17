CC= gcc
CFLAGS= -std=c99 -Wall -Werror -g
OUTFILE= grid_test
OBJS= grid_test.o
LDLIB= -lgrid -lm
LDFLAGS= -L ../build/src

$(OUTFILE): $(OBJS)
		$(CC) $^ -o $@ $(LDFLAGS) $(LDLIB)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS) $(OUTFILE)
