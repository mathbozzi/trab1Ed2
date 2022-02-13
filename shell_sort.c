#include "element.h"

void shellSort(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    int h = 1;
    while (h < (hi - lo) / 9) {  // 3x+1 sequencia
        h = 3 * h + 1;           // 1, 4, 13, 40, 121, 364, ...
    }
    while (h > 0) {  // h-sort
        for (int i = lo + h; i <= hi; i++) {
            int j = i;  // Insertion sort
            Element v = elements[i];
            comparision++;
            int comp2 = 0;
            while (j >= lo + h && more(v, elements[j - h])) {
                comp2++;
                changes++;
                elements[j] = elements[j - h];
                j -= h;
            }
            comparision = +comp2;
            elements[j] = v;
        }
        h /= 3;  // proximo incremento de h
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}
