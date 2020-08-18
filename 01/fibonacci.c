#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int i = 0;
  int f = 0;
  int g = 1;
  int temp = 0;
  int count = 0;
  for (i = 0; i < 40; i++){
    printf("%d ", g);
    temp = g;
    g = g + f;
    f = temp;
    count ++;
    if( count == 5){
      count = 0;
      printf("\n");
    }
  }

  return EXIT_SUCCESS;
}
