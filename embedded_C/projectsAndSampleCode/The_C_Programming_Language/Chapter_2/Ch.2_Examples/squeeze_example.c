#include <stdio.h>

char *squeeze(char s[], char c[]);

int main(int argc, char *argv[]){
    printf("%s\n", squeeze(argv[1], argv[2])); // Input an argument with running this program
    return 0;
}

char *squeeze(char s[], char c[]){
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++)   // While not the end of string s[]
        if(s[i] != c[0])       // If not the specified char, c
            s[j++] = s[i];  // Copy the value over then immediately increment j
                            // j will on increment if not the char c
    s[j] = '\0';    // Add NULL char to terminate string
    return s;
}