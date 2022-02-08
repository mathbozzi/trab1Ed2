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
