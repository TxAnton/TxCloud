menu: menu.o index_first_zero.o index_last_zero.o summa_between.o summa_before_and_after.o 
	gcc -o menu  menu.o index_first_zero.o index_last_zero.o  summa_between.o summa_before_and_after.o

menu.o: menu.c index_first_zero.h index_last_zero.h summa_between.h summa_before_and_after.h
	gcc -c menu.c

index_first_zero.o: index_first_zero.h index_first_zero.c
	gcc -c index_first_zero.c

index_last_zero.o: index_last_zero.h index_last_zero.c
	gcc -c index_last_zero.c

summa_between.o: summa_between.h summa_between.c
	gcc -c summa_between.c

summa_before_and_after.o: summa_before_and_after.c summa_before_and_after.h
	gcc -c summa_before_and_after.c 

clean:
	rm -rf *.o menu  

