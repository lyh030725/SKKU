// [W4, loop, Lv2] Count!!! (입력 반복문1)
// Make a program that first accepts N numbers and count the number of numbers which are not multiples of M. N and M are given as first two user inputs as follows.

// [Input]

// N M

// (N numbers)

// #include <stdio.h>

// int main(){
//   int N;
//   printf("N: ");
//   scanf("%d", &N);
//   int M;
//   printf("M: ");
//   scanf("%d", &M);

//   int count = 0;

//   for(int i = 0; i < N; ++i){
//     int num;
//     printf("Num: ");
//     scanf("%d", &num);
//     if(num % M != 0){
//       count++;
//     }
//   }
//   printf("count: %d", count);
//   return 0;
// }



// 코드
// #include <stdio.h>
// int main() {
// 	int N = 0, M = 0, temp = 0, count = 0;
// 	scanf("%d %d", &N, &M);
// 	for(int i = 0; i < N; i++){
// 		scanf("%d ", &temp);
// 		if(temp % M == 0) continue;
// 		count++;
// 	}
// 	printf("%d\n", count);
// 	return 0;
// }