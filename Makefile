all:
	gcc -Wall main.c algorithms.c

quick:
	gcc -Wall main.c quick_sort.c

clean:
	rm -f *.o a.out
