
// Program to count words from stdin

#include <stdio.h>

#define END_OF_FILE 'X'
#define IN 1
#define OUT 0

int main(){
	int c, new_line, new_word, new_char, state;
	new_line = new_word = new_char = 0;
	state = OUT;

	while((c = getchar()) != END_OF_FILE){
		++new_char;     // Increment char counter every new getchar() call
		if(c == '\n')   // If the char was a new line character 
		    ++new_line; // Increment line counter
		if(c == ' ' || c == '\n' || c == '\t') // If the char is a space, newline, or tab 
		    state = OUT; // It is no longer in a word so change state to reflect that fact
		else if(state == OUT){ // If the char is not a space, newline, or tab and you were outside a word
		    state = IN; // You are now in a word so change the state to reflect that fact
		    ++new_word; // Since you are entering a new word, increment the word counter
		}
	}
	printf("The number of lines is %d, the number of words is %d, the number of characters is %d.\n", 
	    new_line, new_word, new_char);
	return 0;
}