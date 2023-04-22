//[W5, function call, Lv1] Star-printing machine
/*Here we have a star-printing machine. It basically accepts two integers, t and n, from user input, and it behaves as follows:
  when t is 1, print n stars(*)
  when t is 2, print n breaks(\n)
  when t is 3, terminate program
*/

#include <stdio.h>

void print_star(int num){
  for(int i = 0; i < num; ++i){
    printf("*");
  }
}

void print_break(int num){
  for(int i = 0; i < num; ++i){
    printf("\n");
  }
}

int main(){
  int type;
  int num;
  while(1){
    scanf("%d %d", &type, &num);
    switch (type)
    {
    case 1:
      print_star(num);
      break;
    case 2:
      print_break(num);
      break;
    case 3:
      return 0;
    default:
      break;
    }
  }
  return 0;
}


// void print_star(int num){
//   for(int i = 0; i < num; ++i){
//     printf("*");
//   }
// }

// void print_break(int num){
//   for(int i = 0; i < num; ++i){
//     printf("\n");
//   }
// }