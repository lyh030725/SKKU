#include <iostream>

using namespace std;

class floor{
public:
    int floor;
    int room;
    int people;
};


int main(){
    

    int T;
    cin >> T;
    
    floor* floor_list = new floor[T];
    
    int max_floor = 1;
    int max_room = 1;
    
    for(int i = 0; i< T; ++i){
        cin >> floor_list[i].floor >> floor_list[i].room;
        if(max_floor < floor_list[i].floor){
            max_floor = floor_list[i].floor;
        }
        if(max_room < floor_list[i].room){
            max_room = floor_list[i].room;
        }
    }
    
    int people_list[max_floor+1][max_room+1];
    
    for(int i = 0; i <= max_floor; ++i){
        for(int j = 0; j <= max_room; ++j){
            people_list[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= max_room; ++i){
        people_list[0][i] = i;
    }
    
    
    for(int i = 1; i <= max_floor; ++i){
        for(int j = 1; j <= max_room; ++j){
            for(int k = 1; k <= j; ++k){
                people_list[i][j] += people_list[i-1][k];
            }
        }
    }
    
    for(int i =0; i < T; ++i){
        cout << people_list[floor_list[i].floor][floor_list[i].room] << '\n';
    }
    
    
    
    
    
    
    return 0;
    
}
