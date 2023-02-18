
// Program to copy input to output but replace multiple consecutive spaces with a single space

#include <stdio.h>

#define END_OF_FILE 'X'

#define IN 1
#define OUT 0

int main(){
	int c;
	int spaces = OUT;	// Variable to indicate whether the input is currently a string of spaces
				// Initially OUTside a string of spaces

	while((c = getchar()) != END_OF_FILE){
		if(c == ' ')	// If the char is a string you enter a string of spaces
			spaces = IN;	// changing state to reflect that
		else if (spaces == IN){	// If char is not a space and you are in a string of spaces 
			spaces = OUT;	// Set state to OUT to reflect leaving a string of spaces
			putchar(' ');   // After leaving the string of spaces print a single space
			putchar(c);
		}	
		else		// If not a space and not in a string of spaces
		    putchar(c); // Print char
	}
	return 0;
}