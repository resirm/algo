#include<stdio.h>

typedef struct subarray{
    int begin;
    int end;
    int sum;
} maxSubArray;

maxSubArray findMaxSubarray(int arr[], int len){
    int i;
    maxSubArray max_i = {0, 1, arr[0]}, max = {0, 1, arr[0]};
    for(i = 1; i < len; ++i){
        if(max_i.sum < 0){
            max_i.begin = i;
            max_i.end = i+1;
            max_i.sum = arr[i];
        }else{
            ++max_i.end;
            max_i.sum += arr[i];
        }
        if(max.sum < max_i.sum){
            max.begin = max_i.begin;
            max.end = max_i.end;
            max.sum = max_i.sum;
        }
    }
    return max;
}

int main(){
    int arr[] = {99,2,-1,3,4,5,-1,-2,-5,2};
    maxSubArray maxSub = findMaxSubarray(arr, sizeof(arr)/sizeof(int));
    int beg = maxSub.begin, end = maxSub.end, sum = maxSub.sum, i;
    for(i = beg; i < end; ++i){
        printf("%d, ", arr[i]);
    }
    printf("sum: %d", sum);
    return 0;
}