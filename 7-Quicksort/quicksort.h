#ifndef QUICKSORT_H
#define QUICKSORT_H

#define asc_des(t,i,j) (t?(i>j):(i<j)) // A[i] is current elem, A[j] is pivot.

typedef char * byte_pointer;

typedef enum{
    ASC, DES
}ASC_DES; 

void swap(byte_pointer a, byte_pointer b, int size);
int partition(int arr[], int p, int r, ASC_DES t);
void quicksort_work(int arr[], int p, int r, ASC_DES t);
void quicksort_asc(int arr[], int p, int r);
void quicksort_des(int arr[], int p, int r);

#endif // !QUICKSORT_H