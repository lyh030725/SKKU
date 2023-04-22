#include <stdio.h>
#include <stdlib.h>

int main(){
  int arr[30];

  for(int i =0; i < 30; ++i){
    arr[i] = 1+rand()%10;
  }

  for(int i =0; i < 30; ++i){
    printf("%d ",arr[i]);
  }
  printf("\n");

  int count = 0;
 
  
  for(int i =0; i < 30; ++i){
    if(arr[i] == 1){
      count ++;
      for(int j = i; j < 29; ++j){
        arr[j] = arr[j+1];
      }
    }
  }

  count = 30 - count;

  for(int i =0; i < count; ++i){
    printf("%d ", arr[i]);
  }

  return 0;
}









// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//   int seed;
//   scanf("%d", &seed);
//   srand(seed);

//   int data[30] = {};
//   for(int i = 0; i < 30; ++i){
//     data[i] = 1+rand()%10;
//   }

//   for(int i = 0; i < 30; ++i){
//     printf("%d ",data[i]);
//   }

//   puts("");
//   int count = 0;

//   for(int i = 0; i < 30; ++i){
//     if(data[i] == 1){
//       count++;
//       if(i != 29){
//         data[i] = data[i+1];
//       }
//     }
//   }
//   count = 30 - count;

//   for(int i = 0; i < count; ++i){
//     printf("%d ", data[i]);
//   }

//   puts("");

//   return 0;
// }