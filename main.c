#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "element.h"

extern void selectionSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void insertionSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void insertionSort2(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void shellSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void quickSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void heapSort(Element *elements, int lo, int hi, unsigned long statistics[2]);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Número de parâmetros incorreto. Por favor, insira no seguinte modelo:\n");
        printf("./a.out <[-123iseqha]> <top_T> <caminho_arquivo>\n");
        return 0;
    }

    FILE *arqv_de_entrada = fopen(argv[3], "r");
    int T = atoi(argv[2]);
    // printf("top -> %d\n", T);

    if (arqv_de_entrada == NULL) {
        printf("Erro na leitura dos dados!");
        return 0;
    }

    char inputFile[50];
    fgets(inputFile, sizeof(inputFile), arqv_de_entrada);
    // printf("numero de dados: %d\n", atoi(inputFile));

    int N = atoi(inputFile);
    if (T > N) {
        printf("Erro! O Número de T(top) deve ser menor ou igual a %d\n", N);
        return 0;
    }
    Element *e = malloc(N * sizeof(Element));

    int i = 0;
    while ((fgets(inputFile, sizeof(inputFile), arqv_de_entrada)) != NULL) {
        e[i] = atoi(inputFile);
        i++;
    }
    fclose(arqv_de_entrada);

    // // ############ Selection Sort ####################
    // unsigned long statistics[2] = {0, 0};
    // clock_t start, stop;
    // start = clock();
    // selectionSort(e, 0, N - 1, statistics);
    // stop = clock();
    //
    // // Output
    // for (int i = 0; i < T; i++) {
    //     printf("%d\n", e[i]);
    // }
    // double time = ((double)stop - start) / CLOCKS_PER_SEC;
    // printf("\nTempo de CPU :%.4f\n", time);
    // printf("Comparações: %lu\n", statistics[0]);
    // printf("Trocas: %lu\n", statistics[1]);
    // char *algorithm = "seleção";
    // printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    // printf("%s\t\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    // ############ Insert Sort ####################
    unsigned long statistics[2] = {0, 0};
    clock_t start, stop;
    start = clock();
    insertionSort(e, 0, N - 1, statistics);  //melhor
    //insertionSort2(e, 0, N - 1, statistics);
    stop = clock();

    // Output
    for (int i = 0; i < T; i++) {
        printf("%d\n", e[i]);
    }
    double time = ((double)stop - start) / CLOCKS_PER_SEC;
    printf("\nTempo de CPU: %.4f\n", time);
    printf("Comparações: %lu\n", statistics[0]);
    printf("Trocas: %lu\n", statistics[1]);
    char *algorithm = "insertion";
    printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    // ############ Shell Sort ####################
    // unsigned long statistics[2] = {0, 0};
    // clock_t start, stop;
    // start = clock();
    // shellSort(e, 0, N - 1, statistics);
    // stop = clock();
    //
    // // Output
    // for (int i = 0; i < T; i++) {
    //     printf("%d\n", a[i]);
    // }
    // double time = ((double)stop - start) / CLOCKS_PER_SEC;
    // printf("\nTempo de CPU: %.4f\n", time);
    // printf("Comparações: %lu\n", statistics[0]);
    // printf("Trocas: %lu\n", statistics[1]);
    // char *algorithm = "shell Sort";
    // printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    // printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    // ############ Quick Sort ####################
    // unsigned long statistics[2] = {0, 0};
    // clock_t start, stop;
    // start = clock();
    // quickSort(e, 0, N - 1, statistics);
    // stop = clock();
    //
    // // Output
    // for (int i = 0; i < T; i++) {
    //     printf("%d\n", a[i]);
    // }
    // double time = ((double)stop - start) / CLOCKS_PER_SEC;
    // printf("\nTempo de CPU: %.4f\n", time);
    // printf("Comparações: %lu\n", statistics[0]);
    // printf("Trocas: %lu\n", statistics[1]);
    // char *algorithm = "quick Sort";
    // printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    // printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    // ############ Heap Sort ####################
    // unsigned long statistics[2] = {0, 0};
    // clock_t start, stop;
    // start = clock();
    // heapSort(e, 0, N - 1, statistics);
    // stop = clock();
    //
    // // Output
    // for (int i = 0; i < T; i++) {
    //     printf("%d\n", a[i]);
    // }
    // double time = ((double)stop - start) / CLOCKS_PER_SEC;
    // printf("\nTempo de CPU: %.4f\n", time);
    // printf("Comparações: %lu\n", statistics[0]);
    // printf("Trocas: %lu\n", statistics[1]);
    // char *algorithm = "heap Sort";
    // printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    // printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    free(e);
}
