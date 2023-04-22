//[W6, recursion, Lv3]

#include <stdio.h>
#include <stdlib.h>

int MAGIC_NUMBER;

int FindNumber(int start, int finish){
  int mid = (start + finish) / 2;
  printf("start : %d finish: %d mid: %d\n", start, finish, mid);
  if(mid == MAGIC_NUMBER){
    printf("%d is MAGIC NUMBER !!\n", mid);
    return mid;
  }
  if(mid > MAGIC_NUMBER){
    printf("%d is bigger than MIAGIC NUMBER\n", mid);
    return FindNumber(start,mid-1);
  }
  if(mid < MAGIC_NUMBER){
    printf("%d is smaller than MIAGIC NUMBER\n", mid);
    return FindNumber(mid+1, finish);
  }
}


int main(){
  int start, finish;
  scanf("%d %d", &start, &finish);
  //MAGIC~
  MAGIC_NUMBER = start + rand()%(finish-start);

  printf("%d\n", MAGIC_NUMBER == FindNumber(start, finish));

}














// #include <stdio.h>
// #include <stdlib.h>

// int MAGIC_NUMBER;

// int FindNumber(int start, int finish){
//   int mid = (start + finish) / 2;
//   printf("start: %d finish: %d\n", start, finish);
//   printf("mid: %d\n", mid);
//   if(mid == MAGIC_NUMBER){
//     printf("MAGIC NUMBER is %d !!\n", MAGIC_NUMBER);
//     return mid;
//   }
//   if(mid > MAGIC_NUMBER){
//     printf("%d is bigger than MAGIC NUMBER\n", mid);
//     return FindNumber(start, mid-1);
//   }
//   else{
//     printf("%d is smaller than MAGIC NUMBER\n", mid);
//     return FindNumber(mid+1, finish);
//   }
// }

