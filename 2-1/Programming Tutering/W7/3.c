//[W7, getchar, Lv1, Lv2, Lv3] Alphabet Counter 1,2,3


#include <stdio.h>

int main(){
  int c;

  while((c=getchar())!= EOF){
    if('A' <= c && c <= 'Z'){
      printf("%c", c+32);
    }
    else{
      printf("%c", c-32);
    }
  }

  return 0;
}










// #include <stdio.h>

// int main(){
//   int c;
//   int count = 0;
//   while((c = getchar()) != EOF){
//     if(c == 'a' || c == 'A'){
//       count++;
//     }
//   }
//   printf("The number of 'a' or 'A' is %d.", count);
// }

// #include <stdio.h>

// int main(){
//   int c;
//   int count = 0;
//   while((c = getchar()) != EOF){
//     if( 'a' <= c && c <= 'z'){
//       count++;
//     }
//   }
//   printf("The number of lowercase alphabets is %d.", count);
// }

// #include <stdio.h>

// int main(){
//   int c;
//   int star_count = 0;
//   int flag_count = 0;
//   while((c = getchar()) != EOF){
//     switch (c)
//     {
//     case 'S':
//       flag_count++;
//       break;
//     case 'T':
//       if(flag_count == 1){
//         flag_count++;
//       }
//       break;
//     case 'A':
//       if(flag_count == 2){
//         flag_count++;
//       }
//       break;
//     case 'R':
//       if(flag_count == 3){
//         star_count++;
//       }
//       break;
//     default:
//       flag_count = 0;
//       break;
//     }
//   }
//   printf("The number of STAR is %d.", star_count);
// }