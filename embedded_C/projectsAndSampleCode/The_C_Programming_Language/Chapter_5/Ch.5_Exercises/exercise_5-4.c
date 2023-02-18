#include <stdio.h>

int str_end(char *, char *);

int main(int argc, char **argv){
    char *s = argv[1], *t = argv[2];
    printf("%d\n", str_end(s, t));
	return 0;
}

int str_end(char *s, char *t){
    char * n = t;   // Save the address of the beginning of t
    for(; *s; s++)  // Move to the end of s
        ;
    for(; *t; t++)  // Move to the end of t
        ;
    for(; *s == *t && t != n; s--, t--) 
        ;   // While they *s and *t are equal and t has not reached its first char
            // Decrement both s and t
    return t == n ? 1 : 0;  
        // If t decremented until it matched n then all of t matched the end of s
        // so return 1 else return 0 
}

