#include <stdio.h> 

char *str_cat(char s[], char c[]);

int main(int argc, char *argv[]){
    printf("%s\n", str_cat(argv[1], argv[2])); // Input an argument with running this program
    return 0;
}

char *str_cat(char s[], char c[]){
    int i, j;

    i = j = 0;

    while(s[i] != '\0') // Find the length of the string
        i++;
    while((s[i++] = c[j++]) != '\0') // At the end of s copy the first char of c then immediately 
        ;                            //increment i and j to copy the rest of c into s
    s[i] = '\0';    // Add NULL char to terminate string
    return s;
}