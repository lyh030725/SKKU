//[W5, function call, Lv1] Average function
//Make a function that requires three values and return their average.


float average(float first, float second, float third){
  return (first + second + third) / 3;
}


#include <stdio.h>

int main(){
  float first, second, third;
  scanf("%f %f %f", &first, &second, &third);

  printf("Average: %f\n", average(first, second, third));


  return 0;
}

// float average(float first, float second, float third){
//   return (first + second + third)/3;
// }