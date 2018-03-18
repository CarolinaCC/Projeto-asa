# Makefile, versao 1

CC       = gcc
CFLAGS   = -g -std=gnu99 -Wall -pedantic -pthread

.PHONY: all clean zip run

all: asa

asa: graph.o list.o node.o stack.o
	$(CC) $(CFLAGS) -o $@ $+

graph.o: graph.c list.h node.h
	$(CC) $(CFLAGS) -o $@ -c $<

list.o: list.c 
	$(CC) $(CFLAGS) -o $@ -c $<

node.o: node.c list.h
	$(CC) $(CFLAGS) -o $@ -c $<

stack.o: stack.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o asa

zip: asa.zip

run:
	./asa


