#include <stdio.h>
#include <stdlib.h>

typedef struct arr_integer {
    int size;
    int *arr;
} arr_integer;

arr_integer alloc_arr_integer(int len) {
   arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
   return a;
}

void printAllElements(arr_integer inputArray) {
    for (int i = 0; i < inputArray.size; i++) {
        printf("Element %d, %d\n", i, inputArray.arr[i]);
    }
}

//codesignal guy
int adj(arr_integer inputArray) {
    int max = 0;
    for (int i = 0; i < (inputArray.size - 1); i++) {
        int temp = inputArray.arr[i] * inputArray.arr[i+1];
        if (temp >= max) {
            max = temp;
        }
        printf("temp %d, max = %d\n", temp, max);
    }
    return max;
}

int main(void) {
    int ints[6] = {3, 6, -2, -5, 7, 3};
    arr_integer arrs = alloc_arr_integer(6);
    arrs.arr = ints;
    printAllElements(arrs);

    int max = adj(arrs);
    printf("MAX: %d\n", max);

    return 0;
}
