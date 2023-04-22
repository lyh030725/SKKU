#include <stdio.h>
#include <stdlib.h>

int main(){
  int arr[10];

  for(int i = 0; i < 10; ++i){
    arr[i] = i;
  }
  int n;
  scanf("%d", &n);

  for(int i = 0; i < 10; ++i){
    printf("%d ", arr[i]);
  }
  
  printf("\n");

  for(int i = 0; i < n; ++i){
    int x = rand()%10;
    int y = rand()%10;

    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }

  for(int i = 0; i < 10; ++i){
    printf("%d ", arr[i]);
  }

  return 0;
}








// #include <stdio.h>

// int main(){
//   int x,y;
//   scanf("%d %d", &x, &y);

//   int arr[10] = {};

//   for(int i = 0; i < 10; ++i){
//     arr[i] = i;
//     printf("%d ", arr[i]);
//   }
//   int temp = arr[x];
//   arr[x] = arr[y];
//   arr[y] = temp;

//   printf("\n");

//   for(int i = 0; i < 10; ++i){
//     printf("%d ", arr[i]);
//   }

//   return 0;
// }







// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//   int n;
//   scanf("%d", &n);

//   int arr[10] = {};

//   for(int i = 0; i < 10; ++i){
//     arr[i] = i;
//     printf("%d ", arr[i]);
//   }
//   for(int i = 0; i < n; ++i){
//     int x = rand()%10;
//     int y = rand()%10;
//     int temp = arr[x];
//     arr[x] = arr[y];
//     arr[y] = temp;
//   }
  

//   printf("\n");

//   for(int i = 0; i < 10; ++i){
//     printf("%d ", arr[i]);
//   }

//   return 0;
// }