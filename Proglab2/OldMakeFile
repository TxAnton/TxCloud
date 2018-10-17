all: menu

clean:
	rm menu *.o

menu.o: menu.c
	gcc -c -o menu.o menu.c

index_first_even.o: index_first_even.c fe_lo.o
	gcc -c -o index_first_even.o index_first_even.c

index_last_odd.o: index_last_odd.c fe_lo.o
	gcc -c -o index_last_odd.o index_last_odd.c

sum_between_even_odd.o: sum_between_even_odd.c fe_lo.o
	gcc -c -o sum_between_even_odd.o sum_between_even_odd.c

sum_before_even_and_after_odd.o: sum_before_even_and_after_odd.c fe_lo.o
	gcc -c -o sum_before_even_and_after_odd.o sum_before_even_and_after_odd.c

fe_lo.o: fe_lo.c
	gcc -c -o fe_lo.o fe_lo.c

menu: menu.o fe_lo.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after_odd.o
	gcc -o menu menu.o fe_lo.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after_odd.o
