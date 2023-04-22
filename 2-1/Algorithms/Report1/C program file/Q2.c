//
//  main.c
//  Bubble_Sort
//
//  Created by 이용하 on 2023/03/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A_LEN 100

int BUBBLE_SORT(int arr[], int arr_len){
    int count = 0;
    for(int i = 1; i < arr_len; ++i){
        for(int j = 0; j < arr_len - i; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

void ALREADY_SORTED(int arr[], int arr_len){
    for(int i = 0; i < arr_len; ++i){
        arr[i] = i+1;
    }
}

void REVERSELY_SORTED(int arr[], int arr_len){
    for(int i = 0; i < arr_len; ++i){
        arr[i] = 100-i;
    }
}

int main(int argc, const char * argv[]) {
    
    int A[A_LEN] = {};
    srand(time(NULL));
    
    for(int i = 0; i < A_LEN; ++i){
        A[i] = rand()% 1000;
        for(int j = 0; j < i; ++j){
            if(A[i] == A[j]){
                A[i] = rand()%1000;
                j = 0;
            }
        }
    }
    
    printf("1) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    int count = BUBBLE_SORT(A, A_LEN);
    
    printf("1) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("1) comparison count : %d\n\n", count);
    
    ALREADY_SORTED(A, A_LEN);
    
    printf("2) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    count = BUBBLE_SORT(A, A_LEN);
    
    printf("2) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("2) comparison count : %d\n\n", count);
    
    REVERSELY_SORTED(A,A_LEN);
    
    printf("3) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    count = BUBBLE_SORT(A, A_LEN);
    
    printf("3) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("3) comparison count : %d\n\n", count);
    
    
    return 0;
}
