#include <stdio.h>
#include <ctype.h>

int atoi_func1(char *);
int atoi_func2(char *);

int main(int argc, char *argv[]){
    printf("%d\n", atoi_func1(argv[1])); 
    printf("%d\n", atoi_func2(argv[1])); 
    return 0;
}

int atoi_func1(char *s){
    int n = 0;
    while(*s >= '0' && *s <= '9') 
        n = 10 * n + (*s++ - '0');    
    return n;
}

int atoi_func2(char *s){
	int n, sign;

	while(isspace(*s))
		s++;

	sign = (*s == '-') ? -1 : 1;
	if(*s == '+' || *s == '-')
		s++;
    n = 0;
	while(isdigit(*s))
		n = 10 * n + (*s++ - '0');
	return sign * n;
}
