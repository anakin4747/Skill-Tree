#include <stdio.h>

void str_n_cpy(char *, char *, int);
void str_n_cat(char *, char *, int);
int str_n_cmp(char *, char *, int);

int main(int argc, char **argv){
    char str[40];
	str_n_cpy(str, "Copy this bitch", 8);
	printf("%s\n", str);

    char str2[40] = "whay", str3[40] = "what";
    str_n_cat(str2, str3, 3);
    printf("%s %d\n", str2, str_n_cmp(str2, str3, 3));
	return 0;
}

void str_n_cpy(char *s, char *t, int n){
    for(int i = 1; (*s++ = *t++) && i < n; i++) // While the value at t is not equal to '\0' which is just 0 
		;	
}

void str_n_cat(char *s, char *t, int n){
	while(*++s)
        ;   // This moves s to point to the last char, '\0', of the string s
    for(int i = 1; (*s++ = *t++) && i < n; i++) // While the value at t is not equal to '\0' which is just 0 
		;
}

int str_n_cmp(char *s, char *t, int n){
    for(int i = 1; *s == *t && i < n; s++, t++, i++)   // cannot simplify to for(; *s++ == *t++;) since the ++ needs to occur after the if statement
        if(!*s) // equivalent to if(*s == '\0')
            return 0;
    return *s - *t;
}

