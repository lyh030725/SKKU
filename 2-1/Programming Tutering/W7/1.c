//[W7,Random Number, Lv2] Random Array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sort(int arr[]){
  for(int i = 0; i < 99; ++i){
    for(int j = i+1; j < 100; ++j){
      if(arr[i] >= arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(){
  srand(time(NULL));
  int arr[100];
  for(int i = 0; i < 100; ++i){
    arr[i] = rand()%101;
    for(int j = 0; j < i; ++j){
      while(arr[i] == arr[j]){
        arr[i] = rand()%101;
        j = 0;
      }
    }
  }
  Sort(arr);

  for(int i = 0; i < 100; ++i){
    printf("%d ", arr[i]);
  }


  return 0;
}













// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>



// int main(){
//   int arr[100];

//   for(int i = 0; i < 100; ++i){
//     arr[i] = rand()%100;
//     for(int j = 0 ; j < i; ++j){
//       while(arr[i] == arr[j]){
//         arr[i] = rand()%100;
//         j = 0;
//       }
//     }
//   }
//   Sort(arr);
//   for(int i = 0; i < 100; ++i){
//     printf("%d ", arr[i]);
//   }
    
  

//   return 0;
// }