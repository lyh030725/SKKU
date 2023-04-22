//[W6, recursive, Lv2]
//10-1 = 9
//9-2 = 7
//7-4 = 3
//3-8 = -5
//-5+1 = -4
//-4+2 = 2
//2-1 = 1

#include <stdio.h>

int countTo1(int num, int step, int direction){
  if(num == 1){
    printf("%d is 1 !\n", num);
    return 1;
  }

  if(direction){
    printf("%d - %d = %d\n", num ,step, num-step);
    if(num-step == 1){
      printf("%d is 1 !\n", num-step);
      return 1;
    }
    else{
      if(1 < (num-step)){
        return countTo1(num-step, step*2, 1);
      }
      else{
        return countTo1(num-step, 1, 0);
      }
    }
  }

  else{
    printf("%d + %d = %d\n", num ,step, num+step);
    if(num+step == 1){
      printf("%d is 1 !\n", num+step);
      return 1;
    }
    else{
      if(1 > (num+step)){
        return countTo1(num+step, step*2, 0);
      }
      else{
        return countTo1(num+step, 1, 1);
      }
    }
  }
}



int main(){
  int a;
  scanf("%d", &a);
  printf("%d\n", countTo1(a, 1, 1 < a));

  return 0;
}








// #include <stdio.h>

// int countTo1(int num, int step, int direction){
//   if(num == 1){
//     printf("%d is 1!\n",num);
//     return 1;
//   }
//   //counting dowm
//   if(direction){
//     printf("%d - %d = %d\n",num, step, num-step);
//     if(num-step == 1){
//       printf("%d is 1!\n", num-step);
//       return 1;
//     }
//     else{
//       if(1 < (num-step)){
//         printf("%d is bigger than 1\n", num-step);
//         return countTo1(num-step, step*2, 1);
//       }
//       else{
//         printf("%d is smaller than 1\n", num-step);
//         return countTo1(num-step, 1, 0);
//       }
        
//     }
//   }
//   //counting up
//   else{
//     printf("%d + %d = %d\n",num, step, num+step);
//     if(num+step == 1){
//       printf("%d is 1!\n", num+step);
//       return 1;
//     }
//     else{
//       if(1 > (num+step)){
//         printf("%d is smaller than 1\n", num+step);
//         return countTo1(num+step, step*2, 0);
//       }
//       else{
//         printf("%d is bigger than 1\n", num+step);
//         return countTo1(num+step, 1, 1);
//       }
//     }
//   }
  
// }

