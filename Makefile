CC=gcc
CFLAGS=-c -Wall -O0

all: stest

stest: sixel_test.o sixel.o
	$(CC) sixel_test.o sixel.o -o stest

sixel_test.o: sixel_test.c
	$(CC) $(CFLAGS) sixel_test.c

sixel.o: sixel.c
	$(CC) $(CFLAGS) sixel.c

clean:
	rm -rf *.o