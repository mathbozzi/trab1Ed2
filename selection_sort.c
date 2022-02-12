#include "element.h"

void selectionSort(Element *elements, int lo, int hi, unsigned long statistics[2]) {
    int comparision = 0;
    int changes = 0;
    for (int i = lo; i < hi; i++) {
        int min = i;
        for (int j = i + 1; j <= hi; j++) {
            comparision++;
            if (more(elements[j], elements[min])) {
                min = j;
            }
        }
        changes++;
        swap(elements[i], elements[min]);
    }
    statistics[0] = comparision;
    statistics[1] = changes;
}
