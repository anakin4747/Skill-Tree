#include <stdio.h>

#define END_OF_FILE 'Z'

int main(){
	// This program reads a char from stdin and writes it to stdout
	int c;
	
	c = getchar();
	while(c != END_OF_FILE){
		putchar(c);
		c = getchar();
	}
	return 0;
}