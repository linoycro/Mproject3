CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o StrList.o
	$(CC) $(CFLAGS) -o main main.o StrList.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

.PHONY: clean all

clean:
	rm -f *.o main