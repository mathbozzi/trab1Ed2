#include <stdio.h>

#include "item.h"

int partition(Item *a, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1) {
        comparision++;
        int comp2 = 0;
        while (less(a[++i], v)) {  // encontra o item a esquerda para trocar
            comp2++;
            if (i == hi) break;
        }
        comparision += comp2;
        comp2 = 0;
        while (less(v, a[--j])) {  // encontra o item a direita para trocar
            comp2++;
            if (j == lo) break;
        }
        comparision += comp2;
        if (i >= j) break;  // verifica se os indices se cruzam
        changes++;
        exch(a[i], a[j]);
    }
    changes++;
    exch(a[lo], a[j]);  // troca
    statistics[0] += comparision;
    statistics[1] += changes;
    return j;  // Return o indice que ja esta no seu lugar
}

void quickSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi, statistics);
    //recursao
    quickSort(a, lo, j - 1, statistics);
    quickSort(a, j + 1, hi, statistics);
}