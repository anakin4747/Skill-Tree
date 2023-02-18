#include <stdio.h>

// A program to  replace a string of spaces in the input with tabs and spaces

#define END_OF_FILE 'X'
#define TABSTOP 12	// 12 was the size of tab on my kali linux terminal
#define IN 1
#define OUT 0

void print_whitespace(int length);

int main(){
	int c, length, state;
	state = OUT;
	length = 0;

	while((c = getchar()) != END_OF_FILE){
		if(c != ' '){	 // If char is not a space you are either not in a string of spaces or just left one
			if(state == IN){	// If you just left the string
				print_whitespace(length);	// Print whitespace then the char
				putchar(c);
			} else
				putchar(c);		// Otherwise just print the char
			state = OUT; // In either case the state should be set to OUT
			length = 0;		 // And the length of the string of spaces, length, should be reset to 0
		} else if(state == OUT) // If the char was a space and the state was OUT
			state = IN;		// Set state to reflect that you are in a string of spaces
		if(state = IN && c == ' ') // If you are in a string and the current char is a space
			length++;		// Increment the length of the string
	}
	return 0;
}

void print_whitespace(int length){
	int i;
	for(i = 0; i < length / TABSTOP; i++)	// For every TABSTOP in length print a tab
		putchar('\t');			// Note: for a more visual understanding of this code replace '\t' with 't'
	for(i = 0; i < length % TABSTOP; i++)	// For every space that doesnt get replaced with a tab print a space
		putchar(' ');			// Note: for a more visual understanding replace ' ' with 's'
}
