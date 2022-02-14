#include "element.h"

void insertionSort(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = hi; i > lo; i--) {
        comparision++;
        if (more(elements[i], elements[i - 1])) {
            changes++;
            swap(elements[i], elements[i - 1]);
        }
    }
    for (int i = lo + 2; i <= hi; i++) {
        int j = i;
        Element v = elements[i];
        comparision++;
        int comp2 = 0;
        while (more(v, elements[j - 1])) {
            comp2++;
            elements[j] = elements[j - 1];
            changes++;
            j--;
        }
        comparision += comp2;
        changes++;
        elements[j] = v;
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}

void insertionSort2(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = lo + 1; i <= hi; i++) {
        for (int j = i; j > lo; j--) {
            comparision++;
            if (more(elements[j], elements[j - 1])) {
                swap(elements[j - 1], elements[j]);
                changes++;
            }
        }
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}