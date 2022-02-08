all:
	gcc -Wall main.c algorithms.c shell_sort.c quick_sort.c

shell:
	gcc -Wall main.c shell_sort.c

quick:
	gcc -Wall main.c quick_sort.c

clean:
	rm -f *.o a.out
