#include <stdio.h>

#include "element.h"

int partition(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int i = lo, j = hi + 1;
    Element v = elements[lo];
    while (1) {
        comparision++;
        int comp2 = 0;
        while (more(elements[++i], v)) {  // encontra o element a esquerda para trocar
            comp2++;
            if (i == hi) break;
        }
        comparision += comp2;
        comp2 = 0;
        while (more(v, elements[--j])) {  // encontra o element a direita para trocar
            comp2++;
            if (j == lo) break;
        }
        comparision += comp2;
        if (i >= j) break;  // verifica se os indices se cruzam
        changes++;
        swap(elements[i], elements[j]);
    }
    changes++;
    swap(elements[lo], elements[j]);  // troca
    statistics[0] += comparision;
    statistics[1] += changes;
    return j;  // Return o indice que ja esta no seu lugar
}

void quickSort(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    if (hi <= lo) {
        return;
    }
    int j = partition(elements, lo, hi, statistics);
    //recursao
    quickSort(elements, lo, j - 1, statistics);
    quickSort(elements, j + 1, hi, statistics);
}