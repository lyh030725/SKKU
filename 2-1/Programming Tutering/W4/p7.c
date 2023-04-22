// [W4, while, Lv4] Prime Tester (while문 심화)
// User gives multiple input numbers and you need to check whether each input from user is prime or not.

// When user types '-1', stop getting input from user.

// Use the any method you want.

// #include <stdio.h>

// int main(){
//   while(1){
//     int input;
//     scanf("%d", &input);
//     if(input == -1) {break;}
//     int isprime = 1;

//     if(input == 0 || input == 1){
//       printf("%d is Not prime\n", input);
//       continue;
//     }
//     for(int i = 2; i < input; ++i){
//       if(input % i == 0){
//         isprime = 0;
//         printf("%d is Not prime\n", input);
//         break;
//       }
//     }
//     if(isprime){
//       printf("%d is prime\n", input);
//     }
//   }
//   return 0;
// }

// 코드
// #include <stdio.h>
// int main() {
// 	int prime = 1;
// 	int num = 0;
// 	while(1){
// 		prime = 1;
// 		scanf("%d", &num);
// 		if(num == -1){
// 			break;
// 		}
// 		if(num == 1){
// 			printf("%d is not prime\n", num);
// 			continue;
// 		}
// 		for(int i = 2; i < num; i++){
// 			if(num % i == 0){
// 				prime = 0;
// 				printf("%d is not prime\n", num);
// 				break;
// 			}
// 		}
// 		if(prime == 1){
// 			printf("%d is prime\n", num);
// 		}
// 	}
// 	return 0;
// }