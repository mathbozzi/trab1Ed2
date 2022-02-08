#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item.h"

extern void sort(Item *, int, int);

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
    Item *a = malloc(N * sizeof(Item));

    int i = 0;
    while ((fgets(inputFile, sizeof(inputFile), arqv_de_entrada)) != NULL) {
        a[i] = atoi(inputFile);
        i++;
    }
    fclose(arqv_de_entrada);

    // ############ selectionSort ####################
    int statistics[2];
    clock_t start, stop;
    start = clock();
    selectSort(a, 0, N - 1, statistics);
    stop = clock();

    // Output
    for (int i = 0; i < T; i++) {
        printf("%d\n", a[i]);
    }
    double time = ((double)stop - start) / CLOCKS_PER_SEC;
    printf("\nTempo de CPU: %.4f\n", time);
    printf("Comparações: %d\n", statistics[0]);
    printf("Trocas: %d\n", statistics[1]);
    char *algorithm = "seleção";
    printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    printf("%s\t\t%s\t%d\t%d\t%d\t%d\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);

    // ############ InsertSort ####################

    free(a);
}
