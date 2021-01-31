#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// arrays
typedef struct arr_integer {
    int size;
    int *arr;
} arr_integer;

arr_integer alloc_arr_integer(int len) {
    printf("DEBUG: Entered alloc_arr_integer!\n");
    printf("DEBUG: Desired array length = %d\n", len);
    arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
    printf("DEBUG: Actual array length = %lu\n", sizeof(a));
    printf("DEBUG: Leaving...\n");
    return a;
}

// matrices
typedef struct matr_integer {
    int depth;
    arr_integer *arrint;
} matr_integer;

matr_integer alloc_matr_integer(int depth, int length) {
    printf("DEBUG: Entered alloc_matr_integer!\n");
    printf("DEBUG: Desired matrix depth = %d, desired array lengths = %d\n", depth, length);
    //I think my bug is here. Malloc is returning the size of the function, but I don't think it is
    //actually CALLING the function!
    printf("DEBUG: sizeof(alloc_arr_integer(length)) = %lu\n", sizeof(alloc_arr_integer(length)));
    matr_integer m = {depth, depth > 0 ? malloc(sizeof(alloc_arr_integer(length))) : NULL};
    printf("DEBUG: Actual matrix depth = %d, actual array lengths = %lu\n", m.depth, sizeof(m));
    printf("DEBUG: Leaving...\n");
    return m;
}

//void assign_matr_values(matr_integer *pmat) {
//    //loop through pmat and initialize its values 
//    for (int i = 0; i < pmat->size; i++) {
//        for (int j = 0; j < pmat->arrint->size; j++) {
//            pmat->arrint->arr[j] = 1;
//        }
//    }
//}

void assign_matr_values(matr_integer *pmat) {
    //loop through pmat and initialize its values 
    printf("DEBUG: Entered assign_matr_values!\n");
    arr_integer *parr;
    printf("DEBUG: before mar[][]\n");
    int mar[3][4] = {
        {0, 1, 1, 2}, 
        {0, 5, 0, 0}, 
        {2, 0, 3, 3}
    };
    printf("DEBUG: passed mar[][]\n");
    for (int i = 0; i < pmat->depth; i++) {
        printf("DEBUG: entered i loop\n");
        printf("DEBUG: i = %d, pmat->depth = %d\n", i, pmat->depth);
        printf("DEBUG: pmat->arrint->size = %d\n", pmat->arrint->size);
        for (int j = 0; j < pmat->arrint->size; j++) {
            printf("DEBUG: entered j loop\n");
            printf("DEBUG: j = %d, pmat->arrint->size = %d\n", i, pmat->arrint->size);
            printf("DEBUG: assigning %d to %d\n", pmat->arrint->arr[j], mar[i][j]);
            pmat->arrint->arr[j] = mar[i][j];
        }
    }
}

// prints
void printArrElements(arr_integer inputArray) {
    for (int i = 0; i < inputArray.size; i++) {
        printf("Element %d, %d\n", i, inputArray.arr[i]);
    }
}

void printMatElements(matr_integer *inputMatrix) {
    for (int i = 0; i < inputMatrix->depth; i++) {
        for (int j = 0; j < inputMatrix->arrint->size; j++) {
            printf("Array %d, Element %d, Value %d\n", i, j, inputMatrix->arrint->arr[j]);
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

    //int mar[3][4] = {
    //    {0, 1, 1, 2}, 
    //    {0, 5, 0, 0}, 
    //    {2, 0, 3, 3}
    //};

    matr_integer mars = alloc_matr_integer(3, 4);
    assign_matr_values(&mars);

    printArrElements(arrs);
    printf("Done with arrays!\n");
    printMatElements(&mars);
    printf("Done with matrix!\n");

    return 0;
}
