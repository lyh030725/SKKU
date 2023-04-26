//
//  main.c
//  Q1
//
//  Created by 이용하 on 2023/04/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int count_1 = 0;
int count_2 = 0;
int count_3 = 0;
int count_4 = 0;


void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void PrintArray(int arr[]){
    for(int i = 0; i < N; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void RandomizeArray(int arr[]){
    for(int i = 0; i < N; ++i){
        arr[i] = rand()%1000;
        for(int j = 0; j < i; ++j){
            if(arr[i] == arr[j]){
                arr[i] = rand()%1000;
                j = 0;
            }
        }
    }
}

void AlmostSorted(int arr[]){
    for(int i = 0; i < 90 ; ++i){
        arr[i] = i+1;
    }
    for(int i = 90; i < 100; ++i){
        arr[i] = rand()%10 + 91;
        for(int j = 0; j < i; ++j){
            if(arr[i] == arr[j]){
                arr[i] = rand()%10 + 91;
                j = 0;
            }
        }
    }
}

void AlmostReverselySorted(int arr[]){
    for(int i = 0; i < 10; ++i){
        arr[i] = rand()%10 + 91;
        for(int j = 0; j < i; ++j){
            if(arr[i] == arr[j]){
                arr[i] = rand()%10 + 91;
                j = 0;
            }
        }
    }
    
    for(int i = 10; i < 100 ; ++i){
        arr[i] = 100-i;
    }
}

int GetMedianIndex(int arr[]){
    if(arr[0] > arr[1]){
        if(arr[1] < arr[2]){
            if(arr[2] > arr[0]){
                return 0;
            }
            else{
                return 2;
            }
        }
        else{
            return 1;
        }
    }
    else{
        if(arr[0] < arr[2]){
            if(arr[2] > arr[1]){
                return 1;
            }
            else{
                return 2;
            }
        }
        else{
            return 0;
        }
    }
}

int Partition_1(int arr[], int start, int end){
    int x = arr[start];
    int i = start;
    for(int j = start+1; j <= end; ++j){
        if(arr[j] <= x){
            count_1++;
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[start], &arr[i]);
    return i;
}

void QuickSort_1(int arr[], int start , int end){
    if(start < end){
        int pivot = Partition_1(arr, start, end);
        QuickSort_1(arr, start, pivot-1);
        QuickSort_1(arr, pivot+1, end);
    }
}

int Partition_2(int arr[], int start, int end){
    int mid = GetMedianIndex(arr);
    Swap(&arr[mid], &arr[start]);
    int x = arr[start];
    int i = start;
    for(int j = start+1; j <= end; ++j){
        if(arr[j] <= x){
            count_2++;
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[start], &arr[i]);
    return i;
}

void QuickSort_2(int arr[], int start , int end){
    if(start < end){
        int pivot = Partition_2(arr, start, end);
        QuickSort_2(arr, start, pivot-1);
        QuickSort_2(arr, pivot+1, end);
    }
}

int Partition_3(int arr[], int start, int end){
    int rand_idx = rand()%(end-start+1) + start;
    Swap(&arr[rand_idx], &arr[start]);
    int x = arr[start];
    int i = start;
    for(int j = start+1; j <= end; ++j){
        if(arr[j] <= x){
            count_3++;
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[start], &arr[i]);
    return i;
}

void QuickSort_3(int arr[], int start , int end){
    if(start < end){
        int pivot = Partition_3(arr, start, end);
        QuickSort_3(arr, start, pivot-1);
        QuickSort_3(arr, pivot+1, end);
    }
}

int Partition_4(int arr[], int start, int end){
    int len = end-start+1;
    int rand_idx = rand()%(len) + start;
    while(rand_idx <= (0.1)*len+start || rand_idx >= (0.9)*len+start){
        rand_idx = rand()%(len) + start;
    }
    Swap(&arr[rand_idx], &arr[start]);
    int x = arr[start];
    int i = start;
    for(int j = start+1; j <= end; ++j){
        if(arr[j] <= x){
            count_4++;
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[start], &arr[i]);
    return i;
}

void QuickSort_4(int arr[], int start , int end){
    if(start < end){
        int pivot = Partition_4(arr, start, end);
        QuickSort_4(arr, start, pivot-1);
        QuickSort_4(arr, pivot+1, end);
    }
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int A[N] = {};
    
//    RandomizeArray(A);
//
//    PrintArray(A);
//
//    QuickSort_2(A, 0, N-1);
//
//    PrintArray(A);
    
    printf("1-1) ");
    RandomizeArray(A);
    PrintArray(A);
    QuickSort_1(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_1);
    count_1 = 0;
    printf("\n");
    
    printf("1-2) ");
    AlmostSorted(A);
    PrintArray(A);
    QuickSort_1(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_1);
    count_1 = 0;
    printf("\n");
    
    printf("1-3) ");
    AlmostReverselySorted(A);
    PrintArray(A);
    QuickSort_1(A, 0, N-1);
    PrintArray(A);
    printf("comparison count : %d\n", count_1);
    count_1 = 0;
    printf("\n");
    printf("\n");
    
    printf("2-1) ");
    RandomizeArray(A);
    PrintArray(A);
    QuickSort_2(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_2);
    count_2 = 0;
    printf("\n");
    
    printf("2-2) ");
    AlmostSorted(A);
    PrintArray(A);
    QuickSort_2(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_2);
    count_2 = 0;
    printf("\n");
     
    printf("2-3) ");
    AlmostReverselySorted(A);
    PrintArray(A);
    QuickSort_2(A, 0, N-1);
    PrintArray(A);
    printf("comparison count : %d\n", count_2);
    count_2 = 0;
    printf("\n");
    
    printf("\n");
    
    printf("3-1) ");
    RandomizeArray(A);
    PrintArray(A);
    QuickSort_3(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_3);
    count_3 = 0;
    printf("\n");
    
    printf("3-2) ");
    AlmostSorted(A);
    PrintArray(A);
    QuickSort_3(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_3);
    count_3 = 0;
    printf("\n");
    
    printf("3-3) ");
    AlmostReverselySorted(A);
    PrintArray(A);
    QuickSort_3(A, 0, N-1);
    PrintArray(A);
    printf("comparison count : %d\n", count_3);
    count_3 = 0;
    printf("\n");
    
    printf("\n");
    
    printf("4-1) ");
    RandomizeArray(A);
    PrintArray(A);
    QuickSort_4(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_4);
    count_4 = 0;
    printf("\n");
    
    printf("4-2) ");
    AlmostSorted(A);
    PrintArray(A);
    QuickSort_4(A, 0, N-1);
    PrintArray(A);
    printf("comparison count: %d\n",count_4);
    count_4 = 0;
    printf("\n");
    
    printf("4-3) ");
    AlmostReverselySorted(A);
    PrintArray(A);
    QuickSort_4(A, 0, N-1);
    PrintArray(A);
    printf("comparison count : %d\n", count_4);
    count_4 = 0;
    printf("\n");
    
    
    return 0;
}
