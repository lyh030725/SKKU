//[W6, recursive, Lv1]
//1263
//3 + 6 + 2 + 1 = 12

#include <stdio.h>

int digitSum(int num){
  if(num < 10){
    printf("%d = ", num);
    return num;
  }
  printf("%d + ", num%10);

  return num%10 + digitSum(num/10);
}


int main(){
  int a;
  scanf("%d", &a);
  printf("%d\n", digitSum(a));

  return 0;
}






















// #include <stdio.h>


// int digitSum(int num){
//   if(num < 10){
//     printf("%d = ", num%10);
//     return num;
//   }
//   printf("%d + ",num%10);
//   return num%10 + digitSum(num/10);
// }

