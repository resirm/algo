#include <stdio.h>
#include <stdbool.h>

#define PARENT(i)   ((i+1)/2)
#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (2*i+2)

typedef struct{
    int *node;
    int length;
    int heap_size;
} heap;

void max_heapify(heap A, int node){
    int left, right, largest;
    while(true){
        left = LEFT(node);
        right = RIGHT(node);
        if(left < A.heap_size && A.node[left] > A.node[node])
            largest = left;
        else
            largest = node;
        if(right < A.heap_size && A.node[right] > A.node[largest])
            largest = right;
        if(node == largest)
            return;
        int temp = A.node[node];
        A.node[node] = A.node[largest];
        A.node[largest] = temp;
        node = largest;
    }
}