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

Really only decent complexity in the best case -- anything worse than that gets pretty ugly pretty quickly.  

Because of bubble sort's complexity, a lot of people consider it to be an algorithm just to be used for the sake of teaching algorithms. It's
probably not best to actually use it in any application.
