// W4, loop, Lv2] Print digit in n notation (입력 반복문2)
// Make a program that accepts a number and prints the digit of the number in n notation.
// 10진수를 n진수로 변환했을 때 자릿수 구하기




#include <stdio.h>

int main(){
  int num, notation;
  int count = 0;

  scanf("%d %d", &num, &notation);

  while(num > 0){
    num /= notation;
    count++;
  }

  printf("%d", count);


  return 0;
}













// #include <stdio.h>

// int main(){
//   int num;
//   int notation;
//   int count = 0;

//   printf("Number: ");
//   scanf("%d" , &num);
//   printf("Notation: ");
//   scanf("%d", &notation);

//   while(num > 0){
//     num /= notation;
//     count++;
//   }

//   printf("%d", count);

//   return 0;
// }


// 코드
// #include <stdio.h>
// int main() {

// 	int input = 0;
// 	int n = 0;
// 	int digit = 0;
	
// 	scanf("%d", &input);
// 	scanf("%d", &n);
// 	while(1){
// 		digit++;
// 		if(input / n == 0) break;
// 		input /= n;
// 	}
// 	printf("%d\n", digit);
// 	return 0;
// }