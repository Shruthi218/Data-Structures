CC=gcc
CFLAGS=-c -Wall


all: interval lcs
interval: interval.c
	$(CC) -o $@ $^

lcs: lcs.c
	$(CC) -o $@ $^

clean: 
	rm -rf *o interval lcs 

