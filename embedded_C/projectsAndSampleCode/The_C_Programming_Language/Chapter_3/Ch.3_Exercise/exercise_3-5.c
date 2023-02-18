#include <stdio.h>
#include <string.h>

#define SIZE 40

void itob(int n, char s[], int b);

int main(int argc, char *argv[]){
    char s1[SIZE] = "a-8", s2[SIZE];
    printf("%s\n", expand(s1, s2));
    return 0;
}

void itob(int n, char s[], int b){
    int i, sign;
    if((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /*getnextdigit*/
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/*
 Write a function expand(s1,s2) that expands shorthand notations
 like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
 Allow for letters of either case and digits, and be prepared to handle cases 
 like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.


    2^31
*/