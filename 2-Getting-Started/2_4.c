#include <stdio.h>
#include <malloc.h>

int merge(int A[], int p, int q, int r) {
    int i, j, k, inversions = 0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L;
    int *R;
    L = malloc(n1*sizeof(int));
    R = malloc(n2*sizeof(int));

    for (i = 0; i < n1; i++) L[i] = A[p + i];
    for (j = 0; j < n2; j++) R[j] = A[q + j + 1];

    for(i = 0, j = 0; i < n1 && j < n2;) {
        if (L[i] > 2*R[j]){
            inversions += n1 - i;
            j++;
        }else{
            i++;
        }
    }
    for(i = 0, j = 0, k = p; k <= r; k++) {
        if (i == n1) {
            A[k] = R[j++];
        } else if (j == n2) {
            A[k] = L[i++];
        } else if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            // int ind = 0;
            // while(i+ind < n1){
            //     if(L[i+ind] > 2*R[j]){
            //         inversions += n1 - i - ind;
            //         break;
            //     }else{
            //         ind++;
            //     }
            // }
        }
    }
    free(L);
    free(R);

    return inversions;
}

int merge_sort(int A[], int p, int r) {
    if (p < r) {
        int inversions = 0;
        int q = (p + r) / 2;
        inversions += merge_sort(A, p, q);
        inversions += merge_sort(A, q + 1, r);
        inversions += merge(A, p, q, r);
        return inversions;
    } else {
        return 0;
    }
}

int main(){
    // int A[] = {1,3,2,3,1,6,5,7,2,2,3,1};
    // int A[] = {1,2,7,1,2,3};
    int A[] = {1,2,7,1,2,3,6,1,2};
    int inv = merge_sort(A,0,sizeof(A)/sizeof(int)-1);
    printf("%d", inv);
    return 0;
}