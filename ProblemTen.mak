#makefile
CC = gcc
WARNINGS = -Wall

all: ProblemTen

ProblemTen: ProblemTen.o linkedlist_ull.o Primes.o inputs.o
	$(CC) $(WARNINGS) linkedlist_ull.o Primes.o inputs.o ProblemTen.o -o ProblemTen
	
linkedlist_ull.o: linkedlist_ull.c linkedlist_ull.h
	$(CC) -c linkedlist_ull.c

Primes.o: Primes.c ProblemTen.h
	$(CC) -c Primes.c
	
inputs.o: inputs.c inputs.h
	$(CC) -c inputs.c
	
ProblemTen.o: ProblemTen.c ProblemTen.h
	$(CC) -c ProblemTen.c

clean:
	rm -rf *o ProblemTen
