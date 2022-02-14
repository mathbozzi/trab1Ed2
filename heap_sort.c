#include <stdlib.h>

#include "element.h"
float *priorityQueue;  // fila de prioridades
int N;

// Cria uma fila de prioridades vazia
void PQ_init(int maxN) {
    priorityQueue = malloc(maxN * sizeof(float));
    N = 0;
}

// // Insere um novo element v na fila de prioridades
void PQ_insert(float v) {
    priorityQueue[N++] = v;
}

void heapSort(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int N = hi - lo + 1;

    PQ_init(N);
    for (int i = 0; i < N; i++) {
        PQ_insert(elements[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        int j, max = 0;
        for (j = 1; j < N; j++) {
            comparision++;
            if (more(priorityQueue[max], priorityQueue[j])) {
                max = j;
            }
        }
        changes++;
        swap(priorityQueue[max], priorityQueue[N - 1]);
        elements[i] = priorityQueue[--N];
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}