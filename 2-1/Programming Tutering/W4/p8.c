
// [W4, iteration+, Lv4] Infinite loop: Calculator (무한 반복문 심화)
// Make a calculator that can perform plus, minus, multiplication, division, modular.

// First, ask user to do what kind of action. (1: +, 2: -, 3: *, 4: /, 5: %, 0: terminate)

// Then, get two integer input.

// Finally, perform the task and print out the result.

// When the program terminated with getting input 0, print out the number of the total calculation performed.










// #include <stdio.h>

// int main(){

//     int action, op1, op2, count = 0;
    
//     while(1){
//       printf("Input action(1: +, 2: -, 3: *, 4: /, 5: %%, 0: terminate): ");
//       scanf("%d", &action);

//       if(action == 0){
//       printf("Program ended. Thank you for using calculator %d times.", count);
//       break;
//       }
//       printf("Input two number to calculate: ");
// 	  	scanf("%d %d", &op1, &op2);

//       switch (action)
//       {
//         case 1:
//           printf("%d + %d = %d\n", op1,op2, op1+op2);
//           count++;
//           break;
//         case 2:
//           printf("%d - %d = %d\n", op1,op2, op1-op2);
//           count++;
//           break;
//         case 3:
//           printf("%d * %d = %d\n", op1,op2, op1*op2);
//           count++;
//           break;
//         case 4:
//           printf("%d / %d = %d\n", op1,op2, op1/op2);
//           count++;
//           break;
//         case 5:
//           printf("%d %% %d = %d\n", op1,op2, op1%op2);
//           count++;
//           break;

    
//         default:
//           break;
//     }
//     }
//     return 0;
//   }


// 코드
// #include <stdio.h>
// int main() {
// 	int tog = 0, op1 = 0, op2 = 0, count = 0;
	
// 	while(  1 ){
// 		printf("Input action(1: +, 2: -, 3: *, 4: /, 5: %, 0: terminate): ");
// 		scanf("%d", &tog);
// 		if(tog == 0){
// 			printf("Program ended. Thank you for using calculator %d times.", count);
// 			break;
// 		} 
// 		printf("Input two number to calculate: ");
// 		scanf("%d %d", &op1, &op2);
// 		switch(tog){
// 			case 1:
// 				printf("%d + %d = %d\n", op1, op2, op1+op2);
// 				count++;
// 				break;
// 			case 2:
// 				printf("%d - %d = %d\n", op1, op2, op1-op2);
// 				count++;
// 				break;
// 			case 3:
// 				printf("%d * %d = %d\n", op1, op2, op1*op2);
// 				count++;
// 				break;
// 			case 4:
// 				printf("%d / %d(Integer division) = %d\n", op1, op2, op1/op2);
// 				count++;
// 				break;
// 			case 5:
// 				printf("%d %% %d = %d\n", op1, op2, op1%op2);
// 				count++;
// 				break;
// 			default: break;
// 		}
// 	}
	
// 	return 0;
// }