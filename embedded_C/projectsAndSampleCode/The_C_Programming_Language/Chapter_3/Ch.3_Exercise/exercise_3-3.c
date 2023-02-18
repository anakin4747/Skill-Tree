#include <stdio.h>
#include <string.h>

#define SIZE 40

char * expand(char s1[], char s2[]);

int main(int argc, char *argv[]){
    char s1[SIZE] = "a-8", s2[SIZE];
    printf("%s\n", expand(s1, s2));

    return 0;
}

char * expand(char s1[], char s2[]){
    int i;
    char start = s1[0], end = s1[strlen(s1) - 1];
    if(start == '-')
        start = 'a';
    if(end == '-')
        end = '9';

    for(i = 0; start - 1 != end; i++, start++){
        s2[i] = start;
        if(start == 'z')
            start -= 75;
    }
    s2[i] = '\0';
    return s2;
}

/*
 Write a function expand(s1,s2) that expands shorthand notations
 like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
 Allow for letters of either case and digits, and be prepared to handle cases 
 like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.


*/