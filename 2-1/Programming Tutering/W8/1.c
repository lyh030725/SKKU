#include <stdio.h>

int main(){
  int arr[10];

  for(int i = 0; i < 10; ++i){
    arr[i] = i;
  }

  
  int x,y;

  scanf("%d %d", &x, &y);

  for(int i = 0; i < 10; ++i){
    printf("%d ", arr[i]);
  }
  
  printf("\n");

  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;

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