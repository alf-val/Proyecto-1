#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    while(i > 0 && goes_before(a[i], a[i-1])){
        swap(a, i, i-1);
        i--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
