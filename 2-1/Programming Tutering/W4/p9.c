// [W4, for, Lv4] Triangle! (3rd Edition) (for문 심화2)
// Write a program that prints the following triangle shape.
// You MUST use printf statements that only of a single asterisk('*'), a single blank(' '), or a single line break('\n'). Maximize your use of iteration (with nested for statement) and minimize the number of printf statements.

// No input value
//         *
//       * *
//     *   *
//   *     *
// *       *
//   *     *
//     *   *
//       * *
//         * 

#include <stdio.h>

int main(){
  
  for(int i = 0; i < 5; ++i){
    for(int j = 8 - 2*i; j > 0; --j){
      printf(" ");
    }
    if(i != 0){
      printf("*");
      for(int j = 1 + 2*(i-1); j > 0; --j){
        printf(" ");
      }
    }
    printf("*");
    printf("\n");
  }
  for(int i = 3; i >= 0; --i){
    for(int j = 8 - 2*i; j > 0; --j){
      printf(" ");
    }
    if(i != 0){
      printf("*");
      for(int j = 1 + 2*(i-1); j > 0; --j){
        printf(" ");
      }
    }
    printf("*");
    printf("\n");
  }









  return 0;
}














// #include <stdio.h>

// int main(){
//   for(int i = 0; i < 5; ++i){
//     for(int j = 8 - 2*i; j > 0; --j) printf(" ");
//     if(i != 0) printf("*");
//     for(int j = 1+2*(i-1); j > 0; --j) printf(" ");
//     printf("*");
//     printf("\n");
//   }
//   for(int i = 3; i >= 0; --i){
//     for(int j = 8 - 2*i; j > 0; --j) printf(" ");
//     if(i != 0) printf("*");
//     for(int j = 1+2*(i-1); j > 0; --j) printf(" ");
//     printf("*");
//     printf("\n");
//   }
// }


// 코드
// #include <stdio.h>
// int main()
// { 	
// 	int n = 0;
// 	for(int i = 0; i < 9; i++){
// 		if(9 - 2*i < 0) n = (9 - 2*i)*(-1) + 2;
// 		else n = 9 - 2*i;
// 		for(int j = 0; j < 8; j++){
// 			if(j+1 == n) printf("*");
// 			else printf(" ");
// 		}
// 		printf("*\n");
// 	}	
// 	return 0;
// }