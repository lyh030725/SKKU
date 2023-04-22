// [W4, break, Lv1] Find min and max (무한 반복문 기초)
// You need to find the min and max of numbers from the user input.

// When user types '-1', stop getting input from user and print the min and max of the input numbers and quit the program.

// User input numbers are between 0 and 100000.

// Use the while and break.

// #include <stdio.h>

// int main(){
//   int min = 100000;
//   int max = 0;
//   while(1){
//     int input;
//     scanf("%d", &input);
//     if(input == -1){
//       break;
//     }
//     if(input < min) min = input;
//     if(input > max) max = input;
//   }
//   printf("MIN: %d MAX: %d", min, max);


//   return 0;
// }



// 코드
// #include <stdio.h>
// int main() {

// 	int input = 0;
// 	int min=100000;
// 	int max=0;
	
// 	while (1) {
// 		scanf("%d", &input);
// 		if(input == -1) break;
// 		else if(input < min) min = input;
// 		else if(input > max) max = input;
// 	}
// 	printf("Min: %d\n", min);
// 	printf("Max: %d\n", max);
// 	return 0;
// }