//[W7, conditional operator] 3 number max



#include <stdio.h>

int main(){
  int x,y,z;
  scanf("%d %d %d", &x, &y, &z);
  int max = 0;

  (x>y) ? ((x>z)?(max = x):(max = z)):((y>z)?(max = y):(max = z));

  printf("max : %d", max);

  return 0;
}










// #include <stdio.h>

// int main(){
//   int x,y,z;
//   scanf("%d %d %d", &x, &y, &z);

//   int max = 0;
//   (x>y)?((x>z)?(max = x):(max = z)):((y>z)?(max=y):(max=z));

//   if(x>y){
//     if(x>z){
//       max = x;
//     }
//     else{
//       max = z;
//     }
//   }
//   else{
//     if(y>z){
//       max = y;
//     }
//     else{
//       max = z;
//     }
//   }
//   printf("max : %d", max);
// }