#include <stdio.h>
#include "priority_queue.h"

// All the solutions for 6.5 except 6.5-9

void build_min_heap_insert(heap *A, int arr[]){
    
    A->heap_size = 1;
    for(int i = 1; i < 9; ++i)
        heap_insert(A, arr[i], MIN_HEAPIFY);
}

int main(){
    // Current max_heap_insert assumes insertion is safe, 
    // i.e. index out of range while inserting to heap A won't happen.
    int s[20] = {5,13,2,25,7,17,20,8,4};
    int a[20] = {5,13,2,25,7,17,20,8,4};
    heap A = {a, 9, 9};
    int b[20] = {5};
    heap B = {b, 1, 1};
    // heap_sort(A, MAX_HEAPIFY);
    build_heap(&A, 0, MIN_HEAPIFY);
    for(int i = 0; i < A.heap_size; ++i){
        if(i < A.heap_size-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    build_min_heap_insert(&B, s);
    for(int i = 0; i < B.heap_size; ++i){
        if(i < B.heap_size-1)
            printf("%d, ", B.node[i]);
        else
            printf("%d\n", B.node[i]);
    }
}