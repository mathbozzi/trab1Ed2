#include "item.h"

void insertionSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = hi; i > lo; i--) {
        // compexch(a[i - 1], a[i]);
        comparision++;
        // printf("a[%d] %d ", i, a[i]);
        // printf("> ");
        // printf("a[%d] %d\n", i - 1, a[i - 1]);
        if (less(a[i], a[i - 1])) {
            // printf("troco %d por %d \n", a[i - 1], a[i]);
            changes++;
            exch(a[i - 1], a[i]);
        }
    }
    // for (int i = 0; i < hi; i++) {
    //     printf("%d ,", a[i]);
    // }
    // printf("\n");
    for (int i = lo + 2; i <= hi; i++) {
        int j = i;
        Item v = a[i];
        while (less(v, a[j - 1])) {
            comparision++;
            a[j] = a[j - 1];
            j--;
        }
        changes++;
        a[j] = v;
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}

void insertionSort2(Item *a, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = lo + 1; i <= hi; i++) {
        for (int j = i; j > lo; j--) {
            comparision++;
            if (less(a[j], a[j - 1])) {
                exch(a[j - 1], a[j]);
                changes++;
            }
        }
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}
