CC=gcc
CFLAGS=-I.
DEPS = book.h member.h
OBJ = main.o book.o member.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

library: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o library