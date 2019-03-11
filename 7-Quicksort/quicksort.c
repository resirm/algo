#include <stdio.h>
#include "quicksort.h"

void swap(byte_pointer a, byte_pointer b, int size){
    char t;
    for(int i = 0; i < size; ++i){
        t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}

int partition(int arr[], int p, int r, ASC_DES t){
    int i = p-1;
    for(int j = p; j < r; ++j){
        if(asc_des(t,arr[j],arr[r])){
            ++i;
            swap((byte_pointer)(arr+i), (byte_pointer)(arr+j), sizeof(int));
        }
    }
    swap((byte_pointer)(arr+i+1), (byte_pointer)(arr+r), sizeof(int));
    return i+1;
}

void quicksort_work(int arr[], int p, int r, ASC_DES t){
    if(p < r){
        int q = partition(arr, p, r, t);
        quicksort_work(arr, p, q-1, t);
        quicksort_work(arr, q+1, r, t);
    }
}

void quicksort_asc(int arr[], int p, int r){
    quicksort_work(arr, p, r, ASC);
}

void quicksort_des(int arr[], int p, int r){
    quicksort_work(arr, p, r, DES);
}