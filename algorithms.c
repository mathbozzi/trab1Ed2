#include <stdio.h>

#include "item.h"

void selectSort(Item *a, int lo, int hi, int statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = lo; i < hi; i++) {
        // printf("i %d\n", i);
        int min = i;
        for (int j = i + 1; j <= hi; j++) {
            // printf("j %d\n", j);
            // printf("a[min] %d\n", a[min]);
            // printf("< \n");
            // printf("a[j] %d\n", a[j]);
            comparision++;
            if (less(a[j], a[min])) {
                min = j;
                // printf("Sou maior\n");
                // printf("min %d\n", min);
            }
        }
        // printf("troca %d <-> %d\n", a[i], a[min]);
        changes++;
        exch(a[i], a[min]);
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}

void insertionSort(Item *a, int lo, int hi, int statistics[2]) {
    for (int i = hi; i > lo; i--) {
        // compexch(a[i - 1], a[i]);
        if (less(a[i], a[i - 1])) {
            exch(a[i - 1], a[i]);
        }
    }
    for (int i = lo + 2; i <= hi; i++) {
        int j = i;
        Item v = a[i];
        while (less(v, a[j - 1])) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}
