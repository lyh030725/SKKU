// Write a C program that accepts the user's resident registration number up to the 7th digit. Then, print the user's date of birth and gender.

// Input Form: YYMMDDG (YY: Year, MM: Month, DD: Day, G: Gender)

// Gender means

//     1 - male (born 1900-1999)
//     2 - female (born 1900-1999)
//     3 - male (born 2000-present)
//     4 - female (born 2000-present)

/* Use following sentences for output
"Enter first seven digit of your resident registration number : "
"You born on ★ / ☆ / ★.\n"
"Your Gender is male (born 1900-1999)\n"
"Your Gender is female (born 1900-1999)\n"
"Your Gender is male (born 2000-present)\n"
"Your Gender is female (born 2000-present)\n"
*/

#include <stdio.h>

int main(){
  int input;
  scanf("%d", &input);

  switch (input % 10)
  {
    case 1:
    printf("You born on %d / %d / %d.\n" , 1900 + input/100000 , input/1000%100, input/10%100);
    printf("Your Gender is male (born 1900-1999)\n");
    break;
    
    case 2:
    printf("You born on %d / %d / %d.\n" , 1900 + input/100000 , input/1000%100, input/10%100);
    printf("Your Gender is female (born 1900-1999)\n");
    break;

    case 3:
    printf("You born on %d / %d / %d.\n" , 2000 + input/100000 , input/1000%100, input/10%100);
    printf("Your Gender is male (born 2000 - present)\n");
    break;

    case 4:
    printf("You born on %d / %d / %d.\n" , 2000 + input/100000 , input/1000%100, input/10%100);
    printf("Your Gender is female (born 2000 - present)\n");
    break;
  
    default:
    break;
  }
  
  


  return 0;
}















// #include <stdio.h>
// int main() {
// 	int num = 0;
// 	printf("Enter first seven digit of your resident registration number : ");
// 	scanf("%d", &num);
// 	if(num % 10 == 1){
// 		printf("You born on %d / %d / %d.\n", 1900 + num/100000, (num/1000)%100, (num/10)%100);
// 		printf("Your Gender is male (born 1900-1999)\n");
// 	}
// 	else if(num % 10 == 2){
// 		printf("You born on %d / %d / %d.\n", 1900 + num/100000, (num/1000)%100, (num/10)%100);
// 		printf("Your Gender is female (born 1900-1999)\n");
// 	}
// 	else if(num % 10 == 3){
// 		printf("You born on %d / %d / %d.\n", 2000 + num/100000, (num/1000)%100, (num/10)%100);
// 		printf("Your Gender is male (born 2000-present)\n");
// 	}
// 	else if(num % 10 == 4){
// 		printf("You born on %d / %d / %d.\n", 2000 + num/100000, (num/1000)%100, (num/10)%100);
// 		printf("Your Gender is female (born 2000-present)\n");
// 	}
	
// }
