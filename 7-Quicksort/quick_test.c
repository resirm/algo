#include <stdio.h>
#include "quicksort.h"

int main(){
    int a[] = {12,54,66,24,5,22,88,45,42,32,63,2,6,1,8,33,52};
    int b[] = {12,54,66,24,5,22,88,45,42,32,63,2,6,1,8,33,52};
    int len = sizeof(a)/sizeof(int);
    printf("Original array: \n");
    for(int i = 0; i < len-1; ++i){
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[len-1]);
    quicksort_asc(a, 0, len-1);
    quicksort_des(b, 0, len-1);
    printf("Ascending array: \n");
    for(int i = 0; i < len-1; ++i){
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[len-1]);
    printf("Decending array: \n");
    for(int i = 0; i < len-1; ++i){
        printf("%d, ", b[i]);
    }
    printf("%d\n", b[len-1]);
    return 0;
}