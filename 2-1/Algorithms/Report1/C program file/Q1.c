//
//  main.c
//  Insertion-Sort
//
//  Created by 이용하 on 2023/03/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A_LEN 100

int INSERTION_SORT(int arr[], int arr_len){
    int count = 0;
    for(int j = 1; j < arr_len; ++j){
        int key = arr[j];
        int i;
        for(i = j-1; i >= 0 && arr[i] > key; --i){
            arr[i+1] = arr[i];
            count++;
        }
        arr[i+1] = key;
    }
    return count;
}

void ALREADY_SORTED(int arr[], int arr_len){
    for(int i = 0; i < arr_len; ++i){
        arr[i] = i+1;
    }
}

void REVERSELY_SORTED(int arr[], int arr_len){
    for(int i = 0; i < A_LEN; ++i){
        arr[i] = 100-i;
    }
}

int main(int argc, const char * argv[]) {
    
    int A[100] = {};
    
    srand(time(NULL));
    
    for(int i = 0; i < A_LEN; ++i){
        A[i] = rand()%1000;
        
        for(int j = 0; j < i; ++j){
            if(A[i] == A[j]){
                A[i] = rand()%1000;
                j=0;
            }
        }
        
    }
    printf("1) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    int count = INSERTION_SORT(A,A_LEN);
    
    printf("1) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    printf("1) comparison count : %d\n\n", count);
    
    
    ALREADY_SORTED(A, A_LEN);
    
    printf("2) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    count = INSERTION_SORT(A,A_LEN);
    
    printf("2) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    printf("2) comparison count : %d\n\n", count);
    
    REVERSELY_SORTED(A, A_LEN);
    
    printf("3) Before: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    count = INSERTION_SORT(A,A_LEN);
    
    printf("3) After: ");
    for(int i = 0; i < A_LEN; ++i){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    printf("3) comparison count : %d\n\n", count);
    
    
    return 0;
}
