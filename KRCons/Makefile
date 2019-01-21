all: menu

clean:
	rm menu *.o

menu.o: menu.c
	gcc -c -o menu.o menu.c	

ctext.o: ctext.c:
	gcc -c -o ctext.o ctext.c
	
ctextio.o: ctextio.c:
	gcc -c -o ctextio.o ctextio.c
	
ctextp.o: ctextp.c:
	gcc -c -o ctextp.o ctextp.c
	
menu: menu.o ctext.o ctextio.o ctextp.o
	gcc -o menu.exe menu.o ctext.o ctextio.o ctextp.o