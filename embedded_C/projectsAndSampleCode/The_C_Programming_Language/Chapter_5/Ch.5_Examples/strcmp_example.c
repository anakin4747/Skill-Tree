#include <stdio.h>

int strcmp_arr(char *, char *);
int strcmp_ptr(char *, char *);

int main(int argc, char **argv){

	printf("with array %d, with pointers %d\n", strcmp_arr(argv[1], argv[2]), strcmp_ptr(argv[1], argv[2]));
	return 0;
}

int strcmp_arr(char *s, char *t){
	int i;

	for(i = 0; s[i] == t[i]; i++) // While values are equal keep iterating through them
        if(s[i] == '\0') // If you reached the end of s then they are the same
            return 0;  // We could check either t or s since this line wont be called unless one of them ends
    return s[i] - t[i];
}

int strcmp_ptr(char *s, char *t){
    for(; *s == *t; s++, t++)   // cannot simplify to for(; *s++ == *t++;) since the ++ needs to occur after the if statement
        if(!*s) // equivalent to if(*s == '\0')
            return 0;
    return *s - *t;
}
