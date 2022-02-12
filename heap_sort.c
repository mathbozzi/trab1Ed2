#include <stdlib.h>

#include "item.h"
float *pq;
int N;
// A fila de prioridades residirá em pq[0..N-1].
// Portanto, a fila estará vazia se e só se N == 0.

// Cria uma fila de prioridades vazia
// em um vetor pq[0..maxN-1].
//
void PQ_init(int maxN) {
    pq = malloc(maxN * sizeof(float));
    N = 0;
}

// // Insere um novo item v na fila de prioridades
// // que reside em pq[0..N-1].
// // (Supõe que há espaço suficiente para um novo item.)
// //
void PQ_insert(float v) {
    pq[N++] = v;
}

void heapSort(Item *a, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int N = hi - lo + 1;

    PQ_init(N);
    for (int i = 0; i < N; i++) {
        PQ_insert(a[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        int j, max = 0;
        for (j = 1; j < N; j++) {
            comparision++;
            if (less(pq[max], pq[j])) {
                max = j;
            }
        }
        changes++;
        exch(pq[max], pq[N - 1]);
        a[i] = pq[--N];
    }
    statistics[0] += comparision;
    statistics[1] += changes;
}