//[W7, getchar, Lv1, Lv2, Lv3] Uppercase or Lowercase 1,2,3

#include <stdio.h>

int main(){
  int c;
  int star_count = 0;
  int flag_count = 0;
  while((c=getchar()) != EOF){
    switch (c)
    {
    case 'S':
      flag_count++;
      break;
    case 'T':
      if(flag_count == 1){
        flag_count++;
      }
      break;
    case 'A':
      if(flag_count == 2){
        flag_count++;
      }
      break;
    case 'R':
      if(flag_count == 3){
        star_count++;
        flag_count = 0;
      }
      break;
    default:
      flag_count = 0;
      break;
    }
  }
  printf("number : %d", star_count);
}













// #include <stdio.h>
// #include <string.h>

// int main(){
//   char str[100];
//   scanf("%s",str);
//   int len = strlen(str);

//   for(int i = 0; i < len; ++i){
//     if('A' <= str[i] && str[i]<= 'Z'){
//       printf("%c", str[i]+32);
//     }
//     else if('a' <= str[i] && str[i] <= 'z'){
//       printf("%c", str[i]-32);
//     }
//   }


//   return 0;
// }