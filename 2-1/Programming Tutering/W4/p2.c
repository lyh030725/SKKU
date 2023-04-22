// [W4, for, Lv1] Counting zeros (Ver. 1) (for문 기초)
// Write a program that counts the number of zeros in an input value, n ( n is a 9-digit number). 

// Print the results as shown below. (Use 'for' statements.)




// #include <stdio.h>

// int main(){
//   int count = 0;
//   int n;
//   scanf("%d", &n);
//   while(n > 0){
//     if(n % 10 == 0){
//       count++;
//     }
//     n /= 10;
//   }

//   printf("%d", count);

//   return 0;
// }




// 코드
// #include <stdio.h>
// int main()
// {
// 	int n, i;
// 	int z_num = 0;
	
// 	scanf("%d", &n);
// 	for(int i = 0; i < 9; i++){
// 		if(n % 10 == 0) z_num++;
// 		n /= 10;
// 	}
// 	printf("The number of zeros: %d\n", z_num);

// 	return 0;
// }
