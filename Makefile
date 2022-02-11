all:
	gcc -Wall quick_sort.c shell_sort.c selection_sort.c insertion_sort.c main.c

clean:
	rm -f *.o a.out
