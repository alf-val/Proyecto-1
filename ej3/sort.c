#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    unsigned int pivot = izq;
    unsigned int i = izq;

    for (unsigned int j = izq + 1; j <= der; ++j) {
        if (goes_before(a[j], a[pivot])) {
            i++;
            swap(a, j, i);
        }
    }

    swap(a, pivot, i);
    return i;
    
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv;
    if (der > izq){
        piv = partition(a, izq, der);
        quick_sort_rec(a, izq, (piv == 0) ? 0 : piv-1);
        quick_sort_rec(a, piv+1, der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

