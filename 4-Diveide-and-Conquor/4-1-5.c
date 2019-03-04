#include<stdio.h>
#include<malloc.h>

typedef struct subarray{
    int begin;
    int end;
    int sum;
} maxSubArray;

maxSubArray findMaxSubarray(int arr[], int len){
    maxSubArray *max_i;
    max_i = malloc(len*sizeof(maxSubArray));
    int i;
    max_i[0].begin = 0;
    max_i[0].end = 0;
    max_i[0].sum = 0;
    for(i = 1; i < len; ++i){
        if(max_i[i-1].sum < 0){
            max_i[i].begin = i;
            max_i[i].end = i+1;
            max_i[i].sum = arr[i];
        }else{
            max_i[i].begin = max_i[i-1].begin;
            max_i[i].end = max_i[i-1].end+1;
            max_i[i].sum = max_i[i-1].sum+arr[i];
        }
    }

    maxSubArray *max = &max_i[0];
    for(i = 1; i < len; ++i){
        if(max->sum < max_i[i].sum){
            max = &max_i[i];
        }
    }
    maxSubArray maxRst = {max->begin, max->end, max->sum};
    free(max_i);
    return maxRst;
}

int main(){
    int arr[] = {1,2,-1,3,4,5,-1,-2,-5,2};
    maxSubArray maxSub = findMaxSubarray(arr, sizeof(arr)/sizeof(int));
    int beg = maxSub.begin, end = maxSub.end, sum = maxSub.sum, i;
    for(i = beg; i < end; ++i){
        printf("%d, ", arr[i]);
    }
    printf("sum: %d", sum);
    return 0;
}