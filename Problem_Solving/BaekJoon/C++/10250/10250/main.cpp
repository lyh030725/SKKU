//
//  main.cpp
//  10250
//
//  Created by 이용하 on 2023/01/08.
//

#include <iostream>

using namespace std;

class Hotel{
public:
    int height;
    int width;
    int th;
};


int main() {
   
    int T;
    cin >> T;
    
    Hotel* hotels = new Hotel[T];
    
    for(int i = 0; i < T; ++i){
        cin >> hotels[i].height >> hotels[i].width >> hotels[i].th;
    }
    
    for(int i = 0; i < T; ++i){
        int Y;
        int X;
        X = (hotels[i].th-1) / hotels[i].height + 1;
        Y = hotels[i].th % hotels[i].height;
        if(Y == 0)
            Y = hotels[i].height;
        if(X < 10){
            cout << Y << "0" << X << endl;
        }
        else{
            cout << Y << X << endl;
        }
    }
    
    
    
    return 0;
}
