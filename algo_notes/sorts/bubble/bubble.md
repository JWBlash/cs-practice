# Bubble Sort

## Time Complexities:
Best: Ω(n)  
Avg: Θ(n^2)  
Worst: O(n^2)  

## Space Complexity:
Worst: O(1)

## Pseudocode:
```
void function bubbleSort(sortableList) {  
    swapped = false;  
    do {  
        for (int i = 0; i < sortableList.len - 1; i++) {  
            if (sortableList[i] < sortableList[i+1]) {  
                swap(sortableList[i], sortableList[i+1]);  
                swapped = true;  
            }  
    } while (swapped isn't false);  
}  
``` 

## Notes:
Stops when no swaps are conducted.
