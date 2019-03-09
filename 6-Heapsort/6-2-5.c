#include <stdio.h>
#include "heapsort.h"


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