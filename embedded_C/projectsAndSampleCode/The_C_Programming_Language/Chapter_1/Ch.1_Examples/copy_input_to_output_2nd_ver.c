#include <stdio.h>

#define END_OF_FILE 'Z'

int main(){
	// This program reads a char from stdin and writes it to stdout
	int c;
	
	while((c = getchar()) != END_OF_FILE){
		putchar(c);
	}
	return 0;
}