#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 5

void max_min(int *a, int n, int *max, int *min){
  int i = 0;
  *max = a[i];
  *min = a[i];

  for( i = 0; i < n; i++){
    if( a[i] >= *max){
      *max = a[i];
    }
    if(a[i] <= *min){
      *min = a[i];
    }
  }

}

int main(void){
  int my_array[] = {7, 2, 3, 4, 1};
  int biggest, smallest;
  max_min(my_array, ARRAY_SIZE, &biggest, &smallest);
  printf("Max value is %d:    Min value is %d\n", biggest, smallest);
}
