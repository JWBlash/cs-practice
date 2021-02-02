#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int depth;
    arr_integer *arrint;
} matr_integer;

matr_integer alloc_matr_integer(int depth, int length) {
    matr_integer m = {depth, depth > 0 ? malloc(depth * sizeof(alloc_arr_integer(length))) : NULL};

    if (depth > 0) {
        for (int i = 0; i < depth; i++) {
            m.arrint[i] = alloc_arr_integer(length);
        }
    } else {
        m.arrint = NULL;
    }
    return m;
}

// prints
void printArrElements(arr_integer inputArray) {
    for (int i = 0; i < inputArray.size; i++) {
        printf("Array[%d] = %d\n", i, inputArray.arr[i]);
    }
}

void printMatElements(matr_integer *inputMatrix) {
    for (int i = 0; i < inputMatrix->depth; i++) {
        for (int j = 0; j < inputMatrix->arrint->size; j++) {
            printf("Matrix[%d][%d] = %d\n", i, j, inputMatrix->arrint->arr[j]);
        }
    }
}

void assign_matr_values(matr_integer *pmat) {
    //loop through pmat and initialize its values 
    int intMatrix[3][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };
    arr_integer *parr;
    printf("sizeof(intMatrix) = %lu, sizeof(input) = %lu\n", sizeof(intMatrix), sizeof(&pmat));
    for (int i = 0; i < pmat->depth; i++) {
        for (int j = 0; j < pmat->arrint->size; j++) {
            pmat->arrint->arr[j] = intMatrix[i][j];
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

    matr_integer mars = alloc_matr_integer(3, 4);
    assign_matr_values(&mars);

    printArrElements(arrs);
    printf("Done with arrays!\n");
    printMatElements(&mars);
    printf("Done with matrix!\n");

    return 0;
}
