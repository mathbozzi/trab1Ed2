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

void imprimeTMaioresElementos(int T, Element *e) {
    for (int i = 0; i < T; i++) {
        printf("%d\n", e[i]);
    }
    printf("\n");
}

void imprimeEstatisticas(double time, unsigned long *statistics) {
    printf("\nTempo de CPU :%.4f\n", time);
    printf("Comparações: %lu\n", statistics[0]);
    printf("Trocas: %lu\n", statistics[1]);
}

void imprimeTable(char *archive, int N, int T, unsigned long *statistics, double time, char *algorithm) {
    // char *algorithm = "seleção";
    printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    printf("%s\t\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, archive, N, T, statistics[0], statistics[1], time);
}

void imprime(char modoImpressao, int T, Element *e, double time, unsigned long *statistics, char *archive, int N, char *algorithm) {
    if (modoImpressao == 49) {
        imprimeTMaioresElementos(T, e);
    }

    else if (modoImpressao == 50) {
        imprimeEstatisticas(time, statistics);
    }

    else if (modoImpressao == 51) {
        imprimeTable(archive, N, T, statistics, time, algorithm);
    }
}

int selecionaMetodoDeOrdenacao(char selectedSortMethod) {
    switch (selectedSortMethod) {
        case 'a':
            return 1;
        case 's':
            return 2;
        case 'i':
            return 3;
        case 'e':
            return 4;
        case 'q':
            return 5;
        case 'h':
            return 6;

        default:
            return 0;
    }
}

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

    char selectedSortMethod = argv[1][2];
    char selectedPrintMode = argv[1][1];
    printf("\n%c\n", selectedSortMethod);
    printf("\n%c\n", selectedPrintMode);

    int selected = selecionaMetodoDeOrdenacao(selectedSortMethod);

    if (selected == 1 || selected == 2) {
        // printf("Ordenação por seleção\n");
        // ############ Selection Sort ####################
        unsigned long statistics[2] = {0, 0};
        clock_t start, stop;
        start = clock();
        selectionSort(e, 0, N - 1, statistics);
        stop = clock();

        double time = ((double)stop - start) / CLOCKS_PER_SEC;
        char *algorithm = "Selection Sort";
        // Output
        imprime(selectedPrintMode, T, e, time, statistics, argv[3], N, algorithm);

        // Output
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
    }

    if (selected == 1 || selected == 3) {
        // ############ Insert Sort ####################
        unsigned long statistics[2] = {0, 0};
        clock_t start, stop;
        start = clock();
        insertionSort(e, 0, N - 1, statistics);  //melhor
        //insertionSort2(e, 0, N - 1, statistics);
        stop = clock();
        char *algorithm = "Insertion Sort";
        // Output
        double time = ((double)stop - start) / CLOCKS_PER_SEC;
        imprime(selectedPrintMode, T, e, time, statistics, argv[3], N, algorithm);

        // for (int i = 0; i < T; i++) {
        //     printf("%d\n", a[i]);
        // }
        // double time = ((double)stop - start) / CLOCKS_PER_SEC;
        // printf("\nTempo de CPU: %.4f\n", time);
        // printf("Comparações: %lu\n", statistics[0]);
        // printf("Trocas: %lu\n", statistics[1]);
        // char *algorithm = "insertion";
        // printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
        // printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, argv[3], N, T, statistics[0], statistics[1], time);
    }

    if (selected == 1 || selected == 4) {
        // ############ Shell Sort ####################
        unsigned long statistics[2] = {0, 0};
        clock_t start, stop;
        start = clock();
        shellSort(e, 0, N - 1, statistics);
        stop = clock();
        char *algorithm = "Shell Sort";
        // Output
        double time = ((double)stop - start) / CLOCKS_PER_SEC;
        imprime(selectedPrintMode, T, e, time, statistics, argv[3], N, algorithm);
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
    }

    if (selected == 1 || selected == 5) {
        // ############ Quick Sort ####################
        unsigned long statistics[2] = {0, 0};
        clock_t start, stop;
        start = clock();
        quickSort(e, 0, N - 1, statistics);
        stop = clock();

        char *algorithm = "Quick Sort";
        // Output
        double time = ((double)stop - start) / CLOCKS_PER_SEC;
        imprime(selectedPrintMode, T, e, time, statistics, argv[3], N, algorithm);

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
    }

    if (selected == 1 || selected == 6) {
        // ############ Heap Sort ####################
        unsigned long statistics[2] = {0, 0};
        clock_t start, stop;
        start = clock();
        heapSort(e, 0, N - 1, statistics);
        stop = clock();
        char *algorithm = "Heap Sort";
        // Output
        double time = ((double)stop - start) / CLOCKS_PER_SEC;
        imprime(selectedPrintMode, T, e, time, statistics, argv[3], N, algorithm);

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
    }

    if (selected == 0) {
        printf("Método de ordenção não encontrado\n");
    }

    free(e);
}