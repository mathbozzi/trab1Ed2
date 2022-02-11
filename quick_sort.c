#include <stdio.h>

#include "item.h"

// #define MAX_SZ 50
// static int v[MAX_SZ];
// static int size;
// #define stack_init() size = 0
// #define stack_empty() (size == 0)

// void push(int e) {
//     v[size++] = e;
// }
// int pop() {
//     return v[--size];
// }

// #define push2(A, B)
//     push(B);
//     push(A)

// int partition(Item *a, int lo, int hi, unsigned long statistics[2]) {
//     int i = lo, j = hi + 1;
//     Item v = a[lo];
//     while (1) {
//         while (less(a[++i], v))  // Encontra o item à esquerda para trocar
//             if (i == hi) break;
//         while (less(v, a[--j]))  // Encontra o item à direita para trocar.
//             if (j == lo) break;
//         if (i >= j) break;  // Verifique se os indices se cruzam
//         exch(a[i], a[j]);
//     }
//     exch(a[lo], a[j]);  // Troca
//     return j;           // Return o indice que ja esta em seu lugar
// }

// void quickSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
//     stack_init();
//     push2(lo, hi);
//     while (!stack_empty()) {
//         lo = pop();
//         hi = pop();
//         if (hi <= lo) {
//             continue;
//         }
//         int i = partition(a, lo, hi, statistics);
//         if (i - lo > hi - i) {  // testa o tamanho do sub-vetor
//             push2(lo, i - 1);   // push no maior
//             push2(i + 1, hi);   // classifica o menor antes
//         } else {
//             push2(i + 1, hi);
//             push2(lo, i - 1);
//         }
//     }
// }

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1) {
        while (less(a[++i], v))  // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j]))  // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break;  // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]);  // Swap with partitioning item.
    return j;           // Return index of item known to be in place.
}

void quickSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi);
    quickSort(a, lo, j - 1, statistics);
    quickSort(a, j + 1, hi, statistics);
}