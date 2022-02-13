#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "element.h"

extern void selectionSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void selectionSortAsc(Element *elements, int lo, int hi);
extern void insertionSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void insertionSort2(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void shellSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void quickSort(Element *elements, int lo, int hi, unsigned long statistics[2]);
extern void heapSort(Element *elements, int lo, int hi, unsigned long statistics[2]);

void imprimeTMaioresElementos(int T, Element *e) {
    printf("\n");
    for (int i = 0; i < T; i++) {
        printf("%d\n", e[i]);
    }
}

void imprimeEstatisticas(double time, unsigned long *statistics) {
    printf("\nTempo de CPU :%.4f\n", time);
    printf("Comparações: %lu\n", statistics[0]);
    printf("Trocas: %lu\n", statistics[1]);
}

void imprimeTable(char *archive, int N, int T, unsigned long *statistics, double time, char *algorithm) {
    // char *algorithm = "seleção";
    printf("\n[algoritmo\tarquivo\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    printf("%s\t%s\t%d\t%d\t%lu\t%lu\t%.4f\n", algorithm, archive, N, T, statistics[0], statistics[1], time);
}

void imprime(int modoImpressao, int T, Element *e, double time, unsigned long *statistics, char *archive, int N, char *algorithm) {
    if (modoImpressao == 1) {
        imprimeTMaioresElementos(T, e);
    }

    else if (modoImpressao == 2) {
        imprimeEstatisticas(time, statistics);
    }

    else if (modoImpressao == 3) {
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

    /* ************** */
    int arrPrint[3] = {-1, -1, -1};
    int posArrPrint = 0;

    char arrSortMethod[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
    int posArrSortMethod = 0;

    for (int cont = 1; argv[1][cont] != '\0'; cont++) {
        // check for alphabets
        if (isalpha(argv[1][cont]) != 0) {
            arrSortMethod[posArrSortMethod] = argv[1][cont];
            posArrSortMethod++;
        }

        // check for decimal digits
        else if (isdigit(argv[1][cont]) != 0) {
            arrPrint[posArrPrint] = argv[1][cont] - '0';
            posArrPrint++;
        }
    }

    for (i = 0; i < 6; i++) {
        char selectedSortMethod = arrSortMethod[i];
        // char selectedPrintMode = argv[1][1];
        // printf("\n%c\n", selectedSortMethod);
        // printf("\n%c\n", selectedPrintMode);

        int selected = selecionaMetodoDeOrdenacao(selectedSortMethod);
        // printf("\n%d\n", selected);

        if (selected == 1 || selected == 2) {
            // printf("Ordenação por seleção\n");
            // ############ Selection Sort ####################
            unsigned long *statistics = malloc(2 * sizeof(unsigned long));
            statistics[0] = 0;
            statistics[1] = 0;
            clock_t start, stop;
            start = clock();
            selectionSort(e, 0, N - 1, statistics);
            stop = clock();

            double time = ((double)stop - start) / CLOCKS_PER_SEC;
            char *algorithm = "Selection Sort";
            // Output
            for (int j = 0; j < 3; j++) {
                // printf("arr %d\n", arrPrint[j]);
                if (arrPrint[j] == -1) {
                    break;
                }

                imprime(arrPrint[j], T, e, time, statistics, argv[3], N, algorithm);
            }

            free(statistics);

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
            unsigned long *statistics = malloc(2 * sizeof(unsigned long));
            statistics[0] = 0;
            statistics[1] = 0;
            clock_t start, stop;
            start = clock();
            insertionSort(e, 0, N - 1, statistics);  //melhor
            //insertionSort2(e, 0, N - 1, statistics);
            stop = clock();
            char *algorithm = "Insertion Sort";
            // Output
            double time = ((double)stop - start) / CLOCKS_PER_SEC;
            for (int j = 0; j < 3; j++) {
                if (arrPrint[j] == -1) {
                    break;
                }

                imprime(arrPrint[j], T, e, time, statistics, argv[3], N, algorithm);
            }
            free(statistics);

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
            unsigned long *statistics = malloc(2 * sizeof(unsigned long));
            statistics[0] = 0;
            statistics[1] = 0;
            clock_t start, stop;
            start = clock();
            shellSort(e, 0, N - 1, statistics);
            stop = clock();
            char *algorithm = "Shell Sort";
            // Output
            double time = ((double)stop - start) / CLOCKS_PER_SEC;
            for (int j = 0; j < 3; j++) {
                if (arrPrint[j] == -1) {
                    break;
                }

                imprime(arrPrint[j], T, e, time, statistics, argv[3], N, algorithm);
            }
            free(statistics);
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
            unsigned long *statistics = malloc(2 * sizeof(unsigned long));
            statistics[0] = 0;
            statistics[1] = 0;
            clock_t start, stop;
            start = clock();
            quickSort(e, 0, N - 1, statistics);
            stop = clock();

            char *algorithm = "Quick Sort";
            // Output
            double time = ((double)stop - start) / CLOCKS_PER_SEC;
            for (int j = 0; j < 3; j++) {
                if (arrPrint[j] == -1) {
                    break;
                }

                imprime(arrPrint[j], T, e, time, statistics, argv[3], N, algorithm);
            }

            free(statistics);

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
            unsigned long *statistics = malloc(2 * sizeof(unsigned long));
            statistics[0] = 0;
            statistics[1] = 0;
            clock_t start, stop;
            start = clock();
            heapSort(e, 0, N - 1, statistics);
            stop = clock();
            char *algorithm = "Heap Sort";
            // Output
            double time = ((double)stop - start) / CLOCKS_PER_SEC;
            for (int j = 0; j < 3; j++) {
                if (arrPrint[j] == -1) {
                    break;
                }

                imprime(arrPrint[j], T, e, time, statistics, argv[3], N, algorithm);
            }
            free(statistics);

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

        // if (selected == 0) {
        //     printf("Método de ordenação não encontrado\n");
        //     break;
        // }
    }

    free(e);
}