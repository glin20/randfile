all: randfile.o
	gcc -o randfile randfile.o

randfile.o: randfile.c
	gcc -c randfile.c

run:
	./randfile

clear:
	rm randfile.o
	rm randfile
	rm file.txt
