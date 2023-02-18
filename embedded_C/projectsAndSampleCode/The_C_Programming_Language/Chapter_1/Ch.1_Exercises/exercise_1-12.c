
// Program to Print 1 word per line

#include <stdio.h>

#define END_OF_FILE 'X'
#define IN 1
#define OUT 0

int main(){
	int c, state;
	state = OUT;

	while((c = getchar()) != END_OF_FILE){
		putchar(c); // Print the input
		if(c == ' ' || c == '\n' || c == '\t'){ // If the char is a space, newline, or tab 
		    state = OUT;  	// It is no longer in a word so change state to reflect that fact
		    putchar('\n');	// A word just ended so print a newline char
		} else if(state == OUT){ // If the char is not a space, newline, or tab and you were outside a word
		    state = IN; // You are now in a word so change the state to reflect that fact
		}
	}
	return 0;
}