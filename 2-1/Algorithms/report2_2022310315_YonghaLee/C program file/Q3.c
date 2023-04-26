//
//  main.c
//  Q3
//
//  Created by 이용하 on 2023/04/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node{
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int key;
    char color;
}Node;

int row;
int col;
char** print_matrix;

Node* NIL(void){
    Node* nil = (Node*)malloc(sizeof(Node));
    nil->parent = NULL;
    nil->left = NULL;
    nil->right = NULL;
    nil->key = -1;
    nil->color = 'B';
    return nil;
}

void LEFT_ROTATE(Node** T, Node* x){
    Node* y = ((x)->right);
    (x)->right = (y)->left;
    if(y && (y)->left){
        (y)->left->parent = x;
    }
    if(y){
        (y)->parent = (x)->parent;
    }
    if(!(x)->parent){
        *T = y;
    }
    else if((x) == (x)->parent->left){
        (x)->parent->left = (y);
    }
    else{
        (x)->parent->right = (y);
    }
    if(y){
        (y)->left = (x);
    }
    (x)->parent = (y);
}

Node* Search(Node*T, int k){
    if(T){
        if(T->key == k){
            return T;
        }
        else if(T->key > k){
            return Search(T->left, k);
        }
        else{
            return Search(T->right, k);
        }
    }
    else{
        return NULL;
    }
}

void RIGHT_ROTATE(Node** T, Node* x){
    Node* y = ((x)->left);
    (x)->left = (y)->right;
    if(y && (y)->right){
        (y)->right->parent = x;
    }
    if(y){
        (y)->parent = (x)->parent;
    }
    if(!(x)->parent){
        *T = y;
    }
    else if((x) == (x)->parent->right){
        (x)->parent->right = (y);
    }
    else{
        (x)->parent->left = (y);
    }
    if(y){
        (y)->right = (x);
    }
    (x)->parent = (y);
}
void RB_INSERT_FIXUP(Node** T, Node* z){
    Node* y = NULL;
    
    while( z->parent && (z)->parent->color == 'R'){
        if((z)->parent == (z)->parent->parent->left){
            y = (z)->parent->parent->right;
            if(y && y->color == 'R'){
                (z)->parent->color = 'B';
                y->color = 'B';
                (z)->parent->parent->color = 'R';
                (z) = (z)->parent->parent;
            }
            else{
                if((z) == (z)->parent->right){
                    (z) = (z)->parent;
                    LEFT_ROTATE(T, z);
                }
                (z)->parent->color = 'B';
                (z)->parent->parent->color = 'R';
                RIGHT_ROTATE(T, ((z)->parent->parent));
            }
        }
        else{
            y = (z)->parent->parent->left;
            if(y && y->color == 'R'){
                (z)->parent->color = 'B';
                y->color = 'B';
                (z)->parent->parent->color = 'R';
                (z) = (z)->parent->parent;
            }
            else{
                if((z) == (z)->parent->left){
                    (z) = (z)->parent;
                    RIGHT_ROTATE(T, z);
                }
                (z)->parent->color = 'B';
                (z)->parent->parent->color = 'R';
                LEFT_ROTATE(T, ((z)->parent->parent));
            }
        }
    }
    (*T)->color = 'B';
}

void RB_INSERT(Node** T, int k){
    Node* z = (Node*)malloc(sizeof(Node));
    z->key = k;
    if(Search(*T, z->key)){
        return;
    }
    Node* y = NIL();
    Node* x = *T;
    
    while(x->key != -1){
        y = x;
        if((z)->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    (z)->parent = y;
    if(y->key == -1){
        z->parent = NULL;
        *T = z;
    }
    else if((z)->key < (y)->key){
        (y)->left = z;
    }
    else{
        (y)->right = z;
    }
    (z)->left = NIL();
    (z)->right = NIL();
    (z)->color = 'R';
    RB_INSERT_FIXUP(T, z);
}



Node* Successor(Node* T){
    Node* y;
    if(T->right->key != -1){
        T = T->right;
        while(T->left->key != -1){
            T = T->left;
        }
        return T;
    }
    else{
        y = T->parent;
        while(y && T == y->right){
            T = y;
            y = y->parent;
        }
        return y;
    }
}
void RB_DELETE_FIXUP(Node** T, Node* x){
    Node* w;
    Node* c;
    if( x->parent &&x == x->parent->left){
        w = x->parent->right;
        if(x->parent->color == 'R' && w->color == 'B' && w->left->color == 'B' && w->right->color == 'B'){
            x->parent->color = 'B';
            w->color = 'R';
        }
        else if(x->parent->color == 'B' && w->color == 'B' && w->left->color == 'B' && w->right->color == 'B'){
            w->color = 'R';
            RB_DELETE_FIXUP(T, x->parent);
        }
        else if(w->color == 'B' && w->right->color == 'R'){
            w->color = x->parent->color;
            w->right->color = 'B';
            x->parent->color = 'B';
            LEFT_ROTATE(T, x->parent);
        }
        else if(w->color == 'B' && w->right->color == 'B' && w->left->color == 'R'){
            w->left->color = 'B';
            w->color = 'R';
            w->right->color = 'B';
            c = w->left;
            RIGHT_ROTATE(T, w);
            w = c;
            w->color = x->parent->color;
            w->right->color = 'B';
            x->parent->color = 'B';
            LEFT_ROTATE(T, x->parent);
        }
        else if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            LEFT_ROTATE(T, x->parent);
            RB_DELETE_FIXUP(T, x);
        }
    }
    else if(x->parent &&x == x->parent->right){
        w = x->parent->left;
        if(x->parent->color == 'R' && w->color == 'B' && w->right->color == 'B' && w->left->color == 'B'){
            x->parent->color = 'B';
            w->color = 'R';
        }
        else if(x->parent->color == 'B' && w->color == 'B' && w->right->color == 'B' && w->left->color == 'B'){
            w->color = 'R';
            RB_DELETE_FIXUP(T, x->parent);
        }
        else if(w->color == 'B' && w->left->color == 'R'){
            w->color = x->parent->color;
            w->left->color = 'B';
            x->parent->color = 'B';
            RIGHT_ROTATE(T, x->parent);
        }
        else if(w->color == 'B' && w->left->color == 'B' && w->right->color == 'R'){
            w->right->color = 'B';
            w->color = 'R';
            w->left->color = 'B';
            c = w->right;
            LEFT_ROTATE(T, w);
            w = c;
            w->color = x->parent->color;
            w->left->color = 'B';
            x->parent->color = 'B';
            RIGHT_ROTATE(T, x->parent);
        }
        else if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            RIGHT_ROTATE(T, x->parent);
            RB_DELETE_FIXUP(T, x);
        }
    }
}

Node* RB_DELETE(Node** T, int k){
    Node* z = Search(*T, k);
    if(!z){
        return NULL;
    }
    Node* y;
    Node* x;

    if((z)->left->key == -1 || (z)->right->key == -1){
        y = z;
    }
    else{
        y = Successor(z);
    }
    if((y)->left->key != -1){
        x = y->left;
    }
    else{
        x = y->right;
    }
    if(x){
        (x)->parent = y->parent;
    }

    if(!y->parent){
        *T = x;
    }
    else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    if(y != z){
        (z)->key = y->key;
    }
    if(y->color == 'B'){
        RB_DELETE_FIXUP(T,x);
    }
    return y;
    
}

Node* BST_INSERT(Node* T, Node* z){
    Node* y = NULL;
    Node* x = T;
    z->left = NIL();
    z->right = NIL();
    z->color = 'I';
    while(x->key != -1){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y;
    if(z->key < y->key){
        y->left = z;
    }
    else{
        y->right = z;
    }
    return z;
}

void BST_DELETE(Node** T, Node* z){
    Node* y;
    Node* x;
    if((z)->left->key == -1 || (z)->right->key == -1){
        y = z;
    }
    else{
        y = Successor(z);
    }
    if(y->left->key == -1){
        x = y->left;
    }
    else{
        x = y->right;
    }
    if(x){
        (x)->parent = y->parent;
    }

    if(!y->parent){
        *T = x;
    }
    else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    if(y != z){
        (z)->key = y->key;
    }
}




int GET_HEIGHT(Node* T){
    int  height = 0;
    
    if(T->key != -1){
        return 1+ (GET_HEIGHT(T->left) > GET_HEIGHT(T->right) ? (GET_HEIGHT(T->left)): (GET_HEIGHT(T->right)));
    }
    return height;
}

int GET_SPACE_NUM(int height){
    if(height == 1){
        return 0;
    }
    if(height == 2){
        return 2;
    }
    int space = 2;
    for(int i = 3; i <= height; ++i){
        space = 2*space + 1;
    }
    return space;
}

int GET_TOTAL_ROW_NUM(int height){
    if(height == 1){
        return 1;
    }
    if(height == 2){
        return 3;
    }
    int row = 3;
    for(int i = 3; i <= height; ++i){
        row = row + GET_SPACE_NUM(i)/2 + 1;
    }
    return row;
}

void MAKE_PRINT_MATRIX(Node* T){
    row = GET_TOTAL_ROW_NUM(GET_HEIGHT(T))+GET_HEIGHT(T);
    col = GET_SPACE_NUM(GET_HEIGHT(T))*2 + 2;
    print_matrix = (char**)malloc(sizeof(char*)*row);
    for(int i = 0; i < row; ++i){
        print_matrix[i] = (char*)malloc(sizeof(char)*col);
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            print_matrix[i][j] = ' ';
        }
    }
}

void FREE_PRINT_MARTIX(void){
    for(int i = 0; i < row; ++i){
        free(print_matrix[i]);
    }
    free(print_matrix);
}

int GET_ROW_NUM(Node* T, int height){
    int row = 0;
    while(T->parent){
        height++;
        row += GET_SPACE_NUM(height)/2 + 2;
        T = T->parent;
    }
    return row;
}

int GET_COL_NUM(Node* T, int height){
    Node* start = T;
    while(T->parent){
        T = T->parent;
    }
    int col = GET_SPACE_NUM(GET_HEIGHT(T));
    T = start;
    while(T->parent){
        height++;
        if(T == T->parent->left){
            col -= GET_SPACE_NUM(height)/2+1;
        }
        else if(T == T->parent->right){
            col += GET_SPACE_NUM(height)/2+1;
        }
        T = T->parent;
    }
    return col;
}

void PRINT_BST(Node* T){
    int height;
    int space;
    int row_local;
    int col_local;
    
    if(T->key == -1){
        return;
    }
    
    if(!T->parent){
        height = GET_HEIGHT(T);
        space = GET_SPACE_NUM(height);
        row_local = 0;
        col_local = space;
        MAKE_PRINT_MATRIX(T);
        print_matrix[row_local][col_local] = T->color;
        if(T->key < 10){
            print_matrix[row_local+1][col_local] = T->key + '0';
        }
        else{
            print_matrix[row_local+1][col_local] = T->key/10 + '0';
            print_matrix[row_local+1][col_local+1] = T->key%10 + '0';
        }
    }
    
    else{
        int count = 0;
        Node* start = T;
        while(T->parent){
            T = T->parent;
            count++;
        }
        height = GET_HEIGHT(T)-count;
        T = start;
        space = GET_SPACE_NUM(height);
        row_local = GET_ROW_NUM(T,height);
        col_local = GET_COL_NUM(T,height);
    }
    
    
    int i;
    for(i = 1; i <= space/2; ++i){
        if(T->left->key != -1){
            print_matrix[row_local+1+i][col_local-i] = '/';
        }
        if(T->right->key != -1){
            print_matrix[row_local+1+i][col_local+i] = '\\';
        }
    }
    if(T->left->key != -1){
        print_matrix[row_local+i+1][col_local-i] = T->left->color;
        if(T->left->key < 10){
            print_matrix[row_local+i+2][col_local-i] = T->left->key + '0';
        }
        else{
            print_matrix[row_local+i+2][col_local-i] = T->left->key/10 + '0';
            print_matrix[row_local+i+2][col_local-i+1] = T->left->key%10 + '0';
        }
    }
    if(T->right->key != -1){
        print_matrix[row_local+i+1][col_local+i] = T->right->color;
        if(T->right->key < 10){
            print_matrix[row_local+i+2][col_local+i] = T->right->key + '0';
        }
        else{
            print_matrix[row_local+i+2][col_local+i] = T->right->key/10 + '0';
            print_matrix[row_local+i+2][col_local+i+1] = T->right->key%10 + '0';
        }
    }
    
    if(T->left->key != -1){
        PRINT_BST(T->left);
    }
    if(T->right->key != -1){
        PRINT_BST(T->right);
    }
    
    if(!T->parent){
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                printf("%c", print_matrix[i][j]);
            }
            printf("\n");
        }
        FREE_PRINT_MARTIX();
    }

}
int Search_prime(Node*T, int k){
    Node* start = T;
    while(T){
        if(T->key == k){
            return k;
        }
        else if(T->key < k){
            T = T->right;
        }
        else{
            T = T->left;
        }
    }
    Node* y;
    T = start;
    Node* x = (Node*)malloc(sizeof(Node));
    x->key = k;
    x = BST_INSERT(T, x);
    int ret = -1;
    PRINT_BST(T);
    if(x->right->key != -1){
        x = x->right;
        while(x->left->key != -1){
            x = x->left;
        }
        if(x){
            ret = x->key;
        }
        BST_DELETE(&T, x);
        return ret;
    }
    else{
        y = x->parent;
        while(y && x == y->right){
            x = y;
            y = y->parent;
        }
        if(y){
            ret = y->key;
        }
        else{
            if(x->left->key != -1){
                x = x->left;
            }
            else{
                x = x->right;
            }
        }
        BST_DELETE(&T, x);
        return ret;
    }
    
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    Node* T = NIL();
    int A[15];
    
    for(int i = 0; i < 15; ++i){
        A[i] = rand()%50;
        for(int j = 0; j < i; ++j){
            if(A[i] == A[j]){
                A[i] = rand()%50;
                j = 0;
            }
        }
    }
    for(int i = 0; i < 15; ++i){
        RB_INSERT(&T, A[i]);
    }
    printf("2)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");

    RB_INSERT(&T, 12);
    printf("3-1)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    RB_INSERT(&T, 15);
    printf("3-2)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    RB_INSERT(&T, 41);
    printf("3-3)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    RB_INSERT(&T, 43);
    printf("3-4)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    RB_INSERT(&T, 5);
    printf("3-5)\n");
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    
    int search_rst;
    printf("4-1)\n");
    search_rst = Search_prime(T, 9);
    if(search_rst == 9){
        printf("%d is existed!\n", search_rst);
    }
    else if(search_rst == -1){
        printf("Successor of 9 is not existed");
    }
    else{
        printf("Successor of 9 is %d\n", search_rst);
    }
    printf("\n");
    printf("4-2)\n");
    search_rst = Search_prime(T, 42);
    if(search_rst == 42){
        printf("%d is existed!\n", search_rst);
    }
    else if(search_rst == -1){
        printf("Successor of 42 is not existed");
    }
    else{
        printf("Successor of 42 is %d\n", search_rst);
    }
    printf("\n");
    printf("4-3)\n");
    search_rst = Search_prime(T, 26);
    if(search_rst == 26){
        printf("%d is existed!\n", search_rst);
    }
    else if(search_rst == -1){
        printf("Successor of 26 is not existed");
    }
    else{
        printf("Successor of 26 is %d\n", search_rst);
    }
    printf("\n");
    printf("4-4)\n");
    search_rst = Search_prime(T, 3);
    if(search_rst == 3){
        printf("%d is existed!\n", search_rst);
    }
    else if(search_rst == -1){
        printf("Successor of 3 is not existed");
    }
    else{
        printf("Successor of 3 is %d\n", search_rst);
    }
    printf("\n");

    
    printf("5-1)\n");
    RB_DELETE(&T, 15);
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    printf("5-2)\n");
    RB_DELETE(&T, T->key);
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    printf("5-3)\n");
    RB_DELETE(&T, 43);
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    printf("5-4)\n");
    RB_DELETE(&T, 12);
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    printf("5-5)\n");
    RB_DELETE(&T, T->key);
    PRINT_BST(T);
    printf("\n");
    printf("\n");
    
    return 0;
}
