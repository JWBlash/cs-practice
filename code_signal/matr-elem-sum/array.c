#include <stdio.h>
#include <stdlib.h>

// arrays
typedef struct arr_integer {
    int size;
    int *arr;
} arr_integer;

arr_integer alloc_arr_integer(int len) {
   arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
   return a;
}

// matrices
typedef struct matr_integer {
    int size;
    arr_integer *arrint;
} matr_integer;

matr_integer alloc_matr_integer(int depth, int length) {
    arr_integer a = alloc_arr_integer(length);
    matr_integer m = {depth, &a};
    return m;
}

// prints
void printArrElements(arr_integer inputArray) {
    for (int i = 0; i < inputArray.size; i++) {
        printf("Element %d, %d\n", i, inputArray.arr[i]);
    }
}

void printMatElements(matr_integer inputMatrix) {
    for (int i = 0; i < inputMatrix.size; i++) {
        for (int j = 0; j < inputMatrix.arrint->size; j++) {
            printf("Array %d, Element %d, Value %d\n", i, j, inputMatrix.arrint->arr[j]);
        }
    }
}

//codesignal guy
int matrSum(matr_integer matrix) {
}

// main
int main(void) {
    int ints[6] = {3, 6, -2, -5, 7, 3};
    arr_integer arrs = alloc_arr_integer(6);
    arrs.arr = ints;

    arr_integer mar[3][4] = {{0, 1, 1, 2}, 
                	    {0, 5, 0, 0}, 
          	            {2, 0, 3, 3}};
    matr_integer mars = alloc_matr_integer(3, 4);
    mars.arrint = mar;

    printArrElements(arrs);
    printMatElements(mars);

    return 0;
}
