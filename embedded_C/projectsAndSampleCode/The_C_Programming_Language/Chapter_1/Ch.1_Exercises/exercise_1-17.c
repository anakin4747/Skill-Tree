#include <stdio.h>

// Program to print all input lines that are longer than 80

#define MAXLINE 1000
#define END_OF_FILE 'X'

int get_line(char line[], int limit);

int main(){

    int length, max;
    char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	// Declaring and initializing ints and strings

	while((length = get_line(line, MAXLINE)) > 0)
		if(length > 80)
			printf("%s", line); // Print the string "line"
	return 0;
}

int get_line(char line[], int limit){
	int c, i;

	for(i = 0; i < limit - 1 && (c = getchar()) != END_OF_FILE && c != '\n'; ++i)
		/*   While the char count i is less than the max word line - 1, -1 to account for '\0',
			 and the char is not an end of file char and not a new line char keep on collecting chars from stdin

			 Note that the order of these expressions matters. c = getchar() needs to occur before c != '\n' or
			 else it would be referring to th previous value of c.

			 Also note that the program will only end if it read two EOF or \n chars in any combination
			 This is because the while loop in main only breaks if i is 0 and that will only occur if this loop
			 doesnt complete a single iteration.
		*/
		line[i] = c;
		// Store the char into the line string (char array)
	if(c == '\n'){ // If it is a new line, store the newline char
		line[i] = c;
		++i;
	}
	line[i] = '\0';	// Then store the null terminator at the end of the string
	return i;		// Return the length of that line
}
