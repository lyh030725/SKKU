//
//  main.c
//  Q2
//
//  Created by 이용하 on 2023/04/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

int sum = 0;
int count = 0;
int max_len = 0;

void InitializeTable(Node* table[] , int size){
    for(int i = 0; i < size; ++i){
        Node* node = (Node*)malloc(sizeof(Node));
        (node)->val = -1;
        (node)->next = NULL;
        table[i] = node;
    }
}

void PrintHashTable(Node* table[], int size){
    for(int i = 0; i < size; ++i){
        count = 0;
        Node* start = table[i];
        printf("%dth line:", i);
        while(table[i]){
            printf("%d", table[i]->val);
            if(table[i]->next){
                printf("->");
            }
            table[i] = table[i]->next;
            count++;
        }
        if(count > max_len){
            max_len = count;
        }
        sum += count;
        table[i] = start;
        printf("\n");
    }
    printf("Longest length of all chains: %d\n", max_len);
    printf("Average length of all chains: %f\n", (double)sum/size);
}

void InsertHashTable(Node* table[], int item, int size){
    int key = item % size;
    if(table[key]->val == -1){
        table[key]->val = item;
    }
    else{
        Node* start = table[key];
        while(table[key]->next){
            table[key] = table[key]->next;
        }
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->val = item;
        temp->next = NULL;
        table[key]->next = temp;
        table[key] = start;
    }
}

void FreeTable(Node* table[], int size){
    for(int i = 0; i < size; ++i){
        while(table[i]){
            Node* temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    
    Node* table_1[11] = {};
    Node* table_2[8] = {};
    Node* table_3[7] = {};
    
    InitializeTable(table_1,11);
    InitializeTable(table_2,8);
    InitializeTable(table_3,7);
    
    int rand_sequence[60] = {};
    for(int i = 0; i < 60; ++i){
        rand_sequence[i] = rand()%1000;
        for(int j = 0; j < i; ++j){
            if(rand_sequence[i] == rand_sequence[j]){
                rand_sequence[i] = rand()%1000;
                j = 0;
            }
        }
    }
    
    for(int i = 0; i < 60; ++i){
        InsertHashTable(table_1, rand_sequence[i], 11);
    }
    
    for(int i = 0; i < 60; ++i){
        InsertHashTable(table_2, rand_sequence[i], 8);
    }
    
    for(int i = 0; i < 60; ++i){
        InsertHashTable(table_3, rand_sequence[i], 7);
    }
    
    printf("[Table 1]\n");
    PrintHashTable(table_1, 11);
    printf("\n");
    
    printf("[Table 2]\n");
    PrintHashTable(table_2, 8);
    printf("\n");
    
    printf("[Table 3]\n");
    PrintHashTable(table_3, 7);
    printf("\n");
    
    FreeTable(table_1, 11);
    FreeTable(table_2, 8);
    FreeTable(table_3, 7);
    
    
    
    return 0;
}
