#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Tests if the memory allocation is working.
*
* @return result of the memory allocation.
* @param s - size of the memory blcok.
*/
void *emalloc(size_t s){
    void *result = malloc(s);
    if(result == NULL){
        fprintf(stderr, "Memory alloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/*
* Reallocates the memory and tests to make sure it has not failed.
*
* @return the result of the memory allocation.
* @param obj - being used for reallocation.
* @param s - size of the memory block.
*/
void *erealloc(void *obj, size_t s){
    void *result = realloc(obj, s);
    if(result == NULL){
        fprintf(stderr, "Memory alloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/*
* Takes in the string, and size while it is not alphanumeric. Get each char,
* if it is isalnum, add it to char array, determine if the array is the 
* terminating null.
*/
int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c);

    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}

/*
* Tests to see if the input is a prime number.
*
* @return 0 if not a prime, otherwise return 1.
* @param x - The number that is being checked.
*/
int is_prime(int x){
    int i;
    for(i = 2;  i < x; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

/*
* If number is a prime, go to next prime.
*
* @return x, a prime, if it is a prime. Then return the prime that is next in
* the list.
* @param n - is the number for checking to see if it is a prime.
*/
int next_prime(int n) {
    int x = n;
    if(is_prime(x)) {
        return x;
    }
    
    return next_prime(x + 1);
}
