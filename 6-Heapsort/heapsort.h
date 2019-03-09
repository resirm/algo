#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdbool.h>

#define PARENT(i)   ((i-1)/2)
#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (2*i+2)
#define LESS_GREATER(t,i,j) (t?(i > j):(i < j)) 

typedef struct{
    int *node;
    int length;
    int heap_size;
} heap;

typedef enum{
    MIN_HEAPIFY,
    MAX_HEAPIFY
} MIN_MAX;

void exchange(int *i, int *j);
void heapify_work(heap *A, int node, MIN_MAX type);
void build_heap(heap *A, int node, MIN_MAX type);
void heap_sort(heap *A, MIN_MAX type);
void max_heapify(heap *A, int node);
void min_heapify(heap *A, int node);

#endif // !HEAPSORT_H

