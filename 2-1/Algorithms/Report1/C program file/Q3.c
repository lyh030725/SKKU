//
//  main.c
//  Linked_List
//
//  Created by 이용하 on 2023/03/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int key;
    struct LinkedList* next;
}LinkedList;

void insert(LinkedList** lst, int x);

void delete(LinkedList** lst);

void print(LinkedList* lst);


int main(int argc, const char * argv[]) {
    
    LinkedList* lst = NULL;
    
    for(int i = 0; i < 5; ++i){
        insert(&lst,i);
    }
    
    LinkedList* start = lst;
    
    for(int i = 0; i < 5; ++i){
        printf("%d ", lst->key);
        lst = lst->next;
    }
    printf("\n");
    
    lst = start;
    
    delete(&lst);
    delete(&lst);
    
    for(int i = 0; i < 3; ++i){
        printf("%d ", lst->key);
        lst = lst->next;
    }
    printf("\n");
    
    lst = start;
    
    
    print(lst);
    
    return 0;
}

void insert(LinkedList** lst, int x){
    if(!(*lst)){
        *lst = (LinkedList*)malloc(sizeof(LinkedList));
        (*lst)->key = x;
        (*lst)->next = NULL;
    }
    
    else{
        LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
        temp->next = *lst;
        temp->key = x;
        *lst = temp;
    }
        
}

void delete(LinkedList** lst){
    if(!(*lst)){
        return;
    }
    LinkedList* start = *lst;
    while((*lst)->next->next->next){
        (*lst) = (*lst)->next;
    }
    LinkedList* temp = (*lst)->next;
    (*lst)->next = (*lst)->next->next;
    free(temp);
    (*lst) = start;
    
}

void print(LinkedList* lst){
    int count = 0;
    LinkedList* copy_lst = lst;
    
    while(copy_lst){
        copy_lst = copy_lst->next;
        count++;
    }
    
    if(count % 2 == 0){
        for(int i = 0; i < count/2; ++i, lst = lst->next){
            if(i == count/2-1){
                printf("1st line : %d\n", lst->key);
                printf("2nd line : %d\n", lst->next->key);
            }
            
        }
    }
    else{
        for(int i = 0; i <= count/2; ++i, lst = lst->next){
            if(i == count/2){
                printf("1st line : %d\n", lst->key);
                printf("2nd line : %d\n", lst->next->key);
            }
        }
    }
    
    
}
