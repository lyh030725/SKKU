// [W4, for, Lv2] Triangle! (1st Edition) (for문 심화)
// Write a program that prints the following triangle shape with the height of n (3<= n <= 20).
// You MUST use printf statements that only of a single asterisk('*'), a single blank(' '), or a single line break('\n'). Maximize your use of iteration (with nested for statement) and minimize the number of printf statements.

#include <stdio.h>

int main(){
  int h;
  scanf("%d", &h);

  for(int i = 0; i < h; ++i){
    for(int j = h-1-i; j > 0; --j){
      printf(" ");
    }
    for(int j = 1+2*i; j > 0; --j){
      printf("*");
    }

    printf("\n");
  }



  return 0;
}







// #include <stdio.h>
// int main(){
//   int h;
//   scanf("%d", &h);
//   for(int i = 0; i < h; ++i){
//     for(int j = h-1-i; j > 0; --j){
//       printf(" ");
//     }
//     for(int k = 1+2*i; k > 0; --k){
//       printf("*");
//     }
//     printf("\n");
//   }

//   return 0;
// }




// 코드
// #include <stdio.h>
// int main()
// { 	
// 	int n;
	
// 	scanf("%d", &n);
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n - i - 1; j++) printf(" ");
// 		for(int k = n; k > n - 2*i - 1; k--) printf("*");
// 		printf("\n");
// 	}
// 	return 0;
// }