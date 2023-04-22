/*[W5, function call, Lv2] Calculate function
Make 'calculate' function that satisfies the following conditions:
1. get three inputs of first(flaot), second(float) and operator(integer)
2. calculates depending on operand
 - when operator = 1, do first + second
 - when operator = 2, do first - second
 - when operator = 3, do first * second
 - when operator = 4, do fist / second
 3. the operator is always one of 1~4 and the second is not zero.
*/

float calculate(float first, float second, int operator){
  switch (operator)
  {
  case 1:
    return first + second;

  case 2:
    return first - second;
  case 3:
    return first * second;
  case 4:
    return first / second;
  
  default:
    return -1;
    break;
  }
}

#include <stdio.h>

int main(){
  float first, second;
  int operator;

  scanf("%f %f %d", &first, &second, &operator);

  printf("%f\n", calculate(first, second, operator));

  return 0;
}

// float calculate(float first, float second, int operand){
//   switch (operand)
//   {
//   case 1:
//     return first + second;
//   case 2:
//     return first - second;
//   case 3:
//     return first * second;
//   case 4:
//     return first / second;  
//   default:
//     return -1;
//     break;
//   }
// }