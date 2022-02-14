#ifndef ELEMENT_H
#define ELEMENT_H
#include <stdio.h>

typedef int Element;

#define value(A) (A)
#define more(A, B) (value(B) < value(A))
#define less(A, B) (value(A) < value(B))
#define swap(A, B)     \
    {                  \
        Element t = A; \
        A = B;         \
        B = t;         \
    }

#endif /*ELEMENT_H*/
