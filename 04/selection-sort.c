#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void selection_sort(int *a, int n){
    int i, j, y = 0;
    for(i = 0; i < n; i++){
        
        j = i;

        for(y = i+1; y < n; y++){   //finds the smallest item
            if(a[y] < a[j]){
                j = y;
            }
        }

        int smaller_number = a[j];  //swaps the item with whatever is at
        a[j] = a[i];                //position index right now
        a[i] = smaller_number;
    
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
    selection_sort(my_array, count);
    end = clock();

    //prints the sorted numbers
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }

    //prints how many elements were sorted and how long it took
    fprintf(stderr, "%d %f\n", count, ((end-start) / (double)CLOCKS_PER_SEC));

    return EXIT_SUCCESS;

}
