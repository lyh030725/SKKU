// Make a program that receives a five-digit number from a user and determines whether the digits of the number are all even. Assume that there are no wrong inputs from a user.

#include <stdio.h>

int main(){
  int num;
  scanf("%d", &num);
  int count = 0;
  int copy_num = num;

  while(num > 0){
      if(num % 10 % 2 == 1){
        printf("%d is not target", copy_num);
        break;
      }
      count++;
      num /= 10;
  }

  if(count == 5){
    printf("%d is target" , copy_num);
  }


  return 0;
}















// #include <stdio.h>

// int main()
// {
// 	int num = 0;
// 	scanf("%d", &num);
// 	if((num/10000)%2 == 0){
// 		if((num/1000)%2 == 0){
// 			if((num/100)%2 == 0){
// 				if((num/10)%2 == 0){
// 					if(num%2 == 0){
// 						printf("%d is our target.\n", num);
// 					}
// 					else{
// 						printf("%d is NOT our target.\n", num);
// 					}
// 				}
// 				else{
// 					printf("%d is NOT our target.\n", num);
// 				}
// 			}
// 			else{
// 				printf("%d is NOT our target.\n", num);
// 			}
// 		}
// 		else{
// 			printf("%d is NOT our target.\n", num);
// 		}
// 	}
// 	else{
// 		printf("%d is NOT our target.\n", num);
// 	}
//   return 0;
// }

/*
 * "★ is NOT our target."
 * "★ is our target."
*/