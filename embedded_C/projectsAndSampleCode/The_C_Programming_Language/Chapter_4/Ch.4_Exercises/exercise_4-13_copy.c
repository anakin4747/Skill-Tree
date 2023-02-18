#include <stdio.h>

#define SIZE 100

char *recursive_reverse(char []);

int main(int argc, char *argv[]){
    printf("%s\n", recursive_reverse(argv[1]));

	return 0;
}

char *recursive_reverse(char s[]){
    static int i = 0;
	if(s[i] != '\0'){
		recursive_reverse(s[++i]);
	} else 
		return s;
}

