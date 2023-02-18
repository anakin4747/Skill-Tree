#include <stdio.h>

char *squeeze(char s[], char c[]);
int no_char_present(char s, char c[]);

int main(int argc, char *argv[]){
    printf("%s\n", squeeze(argv[1], argv[2])); // Input an argument with running this program
    return 0;
}

char *squeeze(char s[], char c[]){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)   // While not the end of string s[]
        if(no_char_present(s[i], c))    // If char s[i] isnt in string c
            s[j++] = s[i];      // Copy the value over then immediately increment j
                            // j will on increment if not the char c
    s[j] = '\0';    // Add NULL char to terminate string
    return s;
}

int no_char_present(char s, char c[]){
    for(int i = 0; c[i] != '\0'; i++) // While not the end of string c[]
        if(s == c[i])       // char s equals char c[i]
            return 0;       // return false to indicate s was present in c
    return 1;           // If the for loop completes then return true since s was never in c
}