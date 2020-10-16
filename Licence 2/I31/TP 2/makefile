bib: ex_11.o bib.o
	gcc -o bib ex_11.o bib.o
bib.o:bib_premier.c
	gcc -c bib_premier.c -o bib.o
ex_11.o:ex_11.c bib_premier.h
	gcc -c ex_11.c -o ex_11.o