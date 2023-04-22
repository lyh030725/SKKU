/*[W5, logical operator, Lv3] Do the same 6
*/
#include <stdio.h>

int func1(int a, int b){
  if( b <= 5){
    if( a > 5 ){
      a++;
      return a;
    }
    return a;
  }
  return a;
}

int func2(int a, int b){
  if((b <= 5 && a > 5) && a++)
  {
    return a;
  }
  else{
    return a;
  }
}

// int func2(int a, int b){
//   if( (b <= 5 && a > 5) && a++)
//   {
//     return a;
//   }
//   else{
//     return a;
//   }
// }

int main(){
  int a,b;
  scanf("%d %d", &a, &b);

  if(func1(a,b) != func2(a,b)){
    printf("There's some difference with %d %d !\n", func1(a,b), func2(a,b));
  }
  else{
    printf("Well done!");
  }
}