//[W5, function call, Lv1]
//Multiply a and b
/*The given code is not working correctly. With constideration of variavle scope, modify
the code to show the correct result.*/



#include <stdio.h>

int main(){
  int product = 0;
  int a,b;
  scanf("%d %d", &a, &b);
  

  product = a * b;
  printf("a=%d b=%d a*b=%d", a,b, product);
  return 0;
}

