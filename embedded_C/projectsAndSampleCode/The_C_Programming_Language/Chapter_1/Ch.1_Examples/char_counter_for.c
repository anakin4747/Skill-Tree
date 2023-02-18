#include <stdio.h>

#define END_OF_FILE 'Z'
/* count characters in input; 1st version */ 
main(){
    long nc;
    for (nc = 0; gechar() != EOF; ++nc)
        ;
    printf("%ld\n", nc);
}