#include<stdio.h>
#include<stdint.h>
#include "priority_queue.h"

int heap_min_max(heap A){ return A.node[0]; } // non-empty of A shuold be promised by the caller.
int heap_maximum(heap A){ return heap_min_max(A); }
int heap_minimum(heap A){ return heap_min_max(A); }


int heap_extract_min_max(heap *A, MIN_MAX type){
    if(!A->heap_size){
        printf("Error! Empty heap->");
        return INT32_MIN;
    }
    int min_max = A->node[0];
    A->node[0] = A->node[A->heap_size-1];
    A->heap_size -= 1;
    heapify_work(A, 0, type);
    return min_max;
}

int heap_extract_minimum(heap *A){
    return heap_extract_min_max(A, MIN_HEAPIFY);
}

int heap_extract_maximum(heap *A){
    return heap_extract_min_max(A, MAX_HEAPIFY);
}

void heap_inc_dec_key(heap *A, int i, int key, MIN_MAX type){
    if(LESS_GREATER(type, A->node[i], key)){
        if(type == MAX_HEAPIFY)
            printf("Error! new val is less than current value at insertion point->");
        else
            printf("Error! new val is larger than current value at insertion point->");
        return;
    }
    
    while(i > 0 && LESS_GREATER(type, key, A->node[PARENT(i)])){
        // exchange(&A->node[i], &A->node[PARENT(i)]);
        A->node[i] = A->node[PARENT(i)];
        i = PARENT(i);
    }
    A->node[i] = key;
}

void heap_increase_key(heap *A, int i, int key){
    heap_inc_dec_key(A, i, key, MAX_HEAPIFY);
}

void heap_decrease_key(heap *A, int i, int key){
    heap_inc_dec_key(A, i, key, MIN_HEAPIFY);
}

void heap_insert(heap *A, int key, MIN_MAX type){
    A->heap_size += 1;
    if(A->heap_size > A->length)
        ++A->length;
    if(type == MAX_HEAPIFY)
        A->node[A->heap_size-1] = INT32_MIN;
    else
        A->node[A->heap_size-1] = INT32_MAX;
    heap_inc_dec_key(A, A->heap_size-1, key, type);
}

void max_heap_insert(heap *A, int key){
    heap_insert(A, key, MAX_HEAPIFY);
}

void min_heap_insert(heap *A, int key){
    heap_insert(A, key, MIN_HEAPIFY);
}

void heap_delete(heap *A, int node, MIN_MAX type){
    A->node[node] = A->node[A->heap_size-1];
    A->heap_size -= 1;
    heapify_work(A, node, type);
}

void max_heap_delete(heap *A, int node){
    heap_delete(A, node, MAX_HEAPIFY);
}

void min_heap_delete(heap *A, int node){
    heap_delete(A, node, MIN_HEAPIFY);
}
