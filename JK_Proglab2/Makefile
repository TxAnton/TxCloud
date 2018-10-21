all: menu

menu: differenceBetweenMaxAndMin.o sumElementsBeforeFirstMin.o maxElement.o minElement.o menu.o
	gcc -o menu ./*.o

menu.o: menu.c
	gcc -c -o menu.o menu.c 

minElement.o: minElement.c
	gcc -c -o minElement.o minElement.c

maxElement.o: maxElement.c
	gcc -c -o maxElement.o maxElement.c

sumElementsBeforeFirstMin.o: sumElementsBeforeFirstMin.c minElement.o
	gcc -c -o sumElementsBeforeFirstMin.o sumElementsBeforeFirstMin.c

differenceBetweenMaxAndMin.o: differenceBetweenMaxAndMin.c maxElement.o minElement.o
	gcc -c -o differenceBetweenMaxAndMin.o differenceBetweenMaxAndMin.c

clear:	
	rm -rf *.o menu
