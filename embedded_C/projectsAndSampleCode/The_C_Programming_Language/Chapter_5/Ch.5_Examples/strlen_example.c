#include <stdio.h>

int str_len(char *);

int main(int argc, char **argv){

	printf("%d\n", str_len(argv[1]));
	return 0;
}

int str_len(char *s){
	int n;
	for(n = 0; *s != '\0'; s++) // While the value of s (*s) is not \0 increment pointer
		n++;	// and keep track of how many times you incremented the pointer
	return n;	// Return the count
}

