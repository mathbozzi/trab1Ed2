#include <stdio.h>

#include "item.h"

void selectSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
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

void shellSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int h = 1;
    while (h < (hi - lo) / 9) {  // 3x+1 increment sequence
        h = 3 * h + 1;           // 1, 4, 13, 40, 121, 364, ...
    }
    while (h > 0) {  // h-sort the array.
        for (int i = lo + h; i <= hi; i++) {
            int j = i;  // Insertion sort
            Item v = a[i];
            comparision++;
            while (j >= lo + h && less(v, a[j - h])) {
                comparision++;
                changes++;
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
        h /= 3;  // Move to next increment
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}
