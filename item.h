#ifndef ITEM_H
#define ITEM_H

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(B) < key(A))
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    }

#endif
