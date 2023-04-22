// Write a C program that accepts three integers from user. If the three integers satisfy the triangle inequality, then print "Possible". Otherwise, print "Impossible".

// NOTE: The triangle inequality is, 'Sum of the lengths of any two sides of triangle must be greater than the length of the third side.'

// Additional Note: All input value is positive and less than or equal to 100 (1 <= all input value <= 100)

#include <stdio.h>

int main(){
  int a,b,c;

  scanf("%d %d %d", &a, &b, &c);

  if(a+b > c && b + c > a && c + a > b){
    printf("Possible");
  }
  else{
    printf("Impossible");
  }

}












// #include <stdio.h>
// int main() {	

// 	int a = 0, b = 0, c = 0;
// 	scanf("%d %d %d", &a, &b, &c);
// 	if(a+b>c){
// 		if(b+c>a){
// 			if(c+a>b){
// 				printf("Possible");
// 			}
// 			else printf("Impossible");
// 		}
// 		else printf("Impossible");
// 	}
// 	else printf("Impossible");
	
// 	return 0;
// }
/* Copy & Paste below sentences for print is recommended
"Possible"
"Impossible"
*/