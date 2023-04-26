//
//  main.cpp
//  2839
//
//  Created by 이용하 on 2023/01/09.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    for(int i = N/5; i >= 0; --i){
        for(int j = 0; j <= N/3; ++j){
            if(N == 5*i + 3*j){
                cout << i+j << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    
    
    return 0;
}
