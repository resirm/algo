#include <stdio.h>
#include "priority_queue.h"

// All the solutions for 6.5 except 6.5-9

int main(){
    // Current max_heap_insert assumes insertion is safe, 
    // i.e. index out of range while inserting to heap A won't happen. 
    int a[20] = {5,13,2,25,7,17,20,8,4};
    heap A = {a, 9, 9};
    // heap_sort(A, MAX_HEAPIFY);
    build_heap(&A, 0, MIN_HEAPIFY);
    for(int i = 0; i < A.heap_size; ++i){
        if(i < A.heap_size-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    min_heap_insert(&A, 6);
    for(int i = 0; i < A.heap_size; ++i){
        if(i < A.heap_size-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    heap_extract_minimum(&A);
    for(int i = 0; i < A.heap_size; ++i){
        if(i < A.heap_size-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    min_heap_delete(&A, 1);
    for(int i = 0; i < A.heap_size; ++i){
        if(i < A.heap_size-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    int len = A.length = A.heap_size;
    heap_sort(&A, MIN_HEAPIFY);
    for(int i = 0; i < len; ++i){
        if(i < len-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
}