#include <stdio.h>

#define END_OF_FILE 'Z'
/* count characters in input; 1st version */ 
main(){
    long nc;
    nc = 0;
    while (getchar() != END_OF_FILE)
        ++nc; 
    printf("%ld\n", nc);
}