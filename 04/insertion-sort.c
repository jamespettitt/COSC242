#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void insertion_sort(int *a, int n){
    int key, i, j = 0;
    for(i = 1; i < n; i++){
        key = a[i];
        j = i-1;
        
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j= j-1;
        }
        
        a[j+1] = key;
    }
}

int main(void){
    int my_array[ARRAY_MAX];
    int i, count = 0;
    clock_t start, end;

    //while there is still another number to be counted,
    //add another number to the array
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }

    //starts the clock, does the sort, ends the clock
    start = clock();
    insertion_sort(my_array, count);
    end = clock();

    //prints the sorted numbers
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }

    //prints how many elements were sorted and how long it took
    fprintf(stderr, "%d %f\n", count, ((end-start) / (double)CLOCKS_PER_SEC));

    return EXIT_SUCCESS;

}
