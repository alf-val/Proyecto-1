#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


/**
 * La funcion goes_before compara el valor absoluto de dos numeros a y b,
 * si abs(a) < abs(b), de ser iguales los valores absolutos devuelve
 * verdadero si a <= b
 */ 
static void insert(int a[], unsigned int i) {
    while(i > 0 && goes_before(a[i], a[i-1])){
        swap(a, i, i-1);
        i--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, i - 1));
        insert(a, i);
    }
}
