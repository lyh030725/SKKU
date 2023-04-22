//[W6, recursive, Lv1] power function
//4^2
//4*4*1
#include <stdio.h>

int power(int num, int exp){
  if(exp == 0){
    return 1;
  }

  return num * power(num, exp-1);
}


int main(){
  int a,b;
  scanf("%d %d", &a, &b);
  printf("%d\n",power(a,b));

  return 0;
}
















// #include <stdio.h>

// int power(int base, int exponent){
//   if(exponent == 1)
//     return base;

//   return base * power(base, exponent-1);
// }

// int main(){
//   int a,b;
//   scanf("%d %d", &a, &b);
//   printf("%d\n",power(a,b));

//   return 0;
// }