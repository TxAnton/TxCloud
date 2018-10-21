all: menu

menu: diff.o sum.o max.o min.o menu.o
	gcc -o menu ./*.o

menu.o: menu.c
	gcc -c -o menu.o menu.c 

min.o: min.c
	gcc -c -o min.o min.c

max.o: max.c
	gcc -c -o max.o max.c

sum.o: sum.c min.o
	gcc -c -o sum.o sum.c

diff.o: diff.c max.o min.o
	gcc -c -o diff.o diff.c

clear:	
	rm -rf *.o menu
