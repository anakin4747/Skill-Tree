#include <stdio.h>

void str_cat(char *, char *);

int main(int argc, char **argv){
    char *s = argv[1], *t = argv[2];
    str_cat(s, t);
    printf("%s\n", s);
	return 0;
}

void str_cat(char *s, char *t){
	while(*++s)
        ;   // This moves s to point to the last char, '\0', of the string s
    while((*s++ = *t++))
        ;
}