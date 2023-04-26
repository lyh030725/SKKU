//
//  main.cpp
//  10757
//
//  Created by 이용하 on 2023/01/09.
//

#include <iostream>
#include <string.h>


using namespace std;

void reverse(char arr[]){
    int len = strlen(arr);
    
    for(int i = 0; i < len/2; ++i){
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

int main(int argc, const char * argv[]) {
    
    char A[10001] = {};
    char B[10001] = {};
    
    cin >> A >> B;
    
    int len_a = strlen(A);
    int len_b = strlen(B);
    int max_len = (len_a > len_b) ? len_a : len_b;
    
    reverse(A);
    reverse(B);
    
    char sum[10002] = {};
    reverse(sum);
    
    
    for(int i = 0; i < max_len; ++i){
        int num1 = A[i] - '0';
        int num2 = B[i] - '0';
        
        if(num1 + num2 >= 10){
            sum[i+1] = 1;
            sum[i] += num1 + num2 - 10 + '0';
        }
        else{
            sum[i] += num1 + num2 + '0';
        }
    }
    reverse(sum);
    
    if(sum[0] == 1)
        sum[0] = '1';
    
    for(int i = 0; i < sizeof(sum); ++i){
        cout << sum[i];
    }
    
    

    
    
    return 0;
}
