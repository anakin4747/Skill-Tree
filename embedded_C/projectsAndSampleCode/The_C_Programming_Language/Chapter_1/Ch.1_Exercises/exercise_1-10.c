
// Program to copy input to output but replace tabs, backspaces, and backslashes with their respective escape characters

#include <stdio.h>

#define END_OF_FILE 'X'

int main(){
	int c;

	while((c = getchar()) != END_OF_FILE){
		switch(c){
			case '\t':
				printf("\\t");	// Works
				break;
			case '\b':
				printf("\\b");	// Doesnt work
				break;
			case '\\':
			    	printf("\\");// Works I guess
				break;
			default:
				putchar(c);
				break;
		}
	}
	return 0;
}