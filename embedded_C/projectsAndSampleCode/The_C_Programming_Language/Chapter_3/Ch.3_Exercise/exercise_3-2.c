#include <stdio.h>

#define SIZE 40

char * escape(char s[], char t[]);
char * rev_escape(char s[], char t[]);

int main(int argc, char *argv[]){
    char s[SIZE] = "\\t\t\n\\\\n Wh\tat", t[SIZE];
    printf("%s\n", rev_escape(s, t));

    return 0;
}

char * escape(char s[], char t[]){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++){
        switch(s[i]){
            case '\\':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
    return t;
}

char * rev_escape(char s[], char t[]){
    int i, j;       // I think this works but I honestly dont know how to test it
    for(i = j = 0; s[i] != '\0'; i++){
        if(s[i - 1] == '\\' && s[i] == 't'){
            t[j++] = '\t';
        } else if(s[i - 1] == '\\' && s[i] == 'n'){
            t[j++] = '\n';
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
    return t;
}