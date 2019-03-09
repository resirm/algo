#include <stdio.h>
#include <stdbool.h>

#define PARENT(i)   ((i+1)/2)
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

void exchange(int *i, int *j){
    int t = *i;
    *i = *j;
    *j = t;
}

void heapify_work(heap A, int node, MIN_MAX type){
    int left, right, largest_smallest;
    while(true){
        left = LEFT(node);
        right = RIGHT(node);
        if(left < A.heap_size && LESS_GREATER(type, A.node[left], A.node[node]))
            largest_smallest = left;
        else
            largest_smallest = node;
        if(right < A.heap_size && LESS_GREATER(type, A.node[right], A.node[largest_smallest]))
            largest_smallest = right;
        if(node == largest_smallest)
            return;
        int temp = A.node[node];
        A.node[node] = A.node[largest_smallest];
        A.node[largest_smallest] = temp;
        node = largest_smallest;
    }
}

void build_heap(heap A, int node, MIN_MAX type){
    A.heap_size = A.length;
    int i;
    for(i = A.heap_size/2-1; i >= 0; --i){
        heapify_work(A, i, type);
    }
}

void heap_sort(heap A, MIN_MAX type){
    build_heap(A, 0, type);
    for(int i = A.length-1; i > 0; --i){
        exchange(&A.node[0], &A.node[i]);
        A.heap_size -= 1;
        heapify_work(A, 0, type);
    }
}

int main(){
    int a[] = {5,13,2,25,7,17,20,8,4};
    heap A = {a, sizeof(a)/sizeof(int), sizeof(a)/sizeof(int)};
    heap_sort(A, MAX_HEAPIFY);
    for(int i = 0; i < A.length; ++i){
        if(i < A.length-1)
            printf("%d, ", A.node[i]);
        else
            printf("%d\n", A.node[i]);
    }
    return 0;
}