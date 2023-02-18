#include <stdio.h>

// Program to print the longest string from stdin

#define MAXLINE 1000
#define END_OF_FILE 'X'

int get_line(char line[], int limit);
void copy(char to[], char from[]);

int main(){

    int length, max;
    char line[MAXLINE];
    char longest[MAXLINE];

	max = 0;

	while((length = get_line(line, MAXLINE)) > 0)
		// get_line() returns the length of the last line and loads the line into the "line" string
		if(length > max){	// If the returned length is greater than the max
			max = length;	// Save it as the new max
			copy(longest, line);	// Copy the newly modified string, "line", to the "longest" string
		}
	if(max > 0)	// Once the while loop breaks and the max wasnt an empty line
		printf("%s", longest); // Print the longest string
		// Without the if statement checking for an empty line, this line could print garbage if no line is typed
		// This is because the "longest" string was never initialized and never written over since copy() would never be called
	return 0;
}

int get_line(char line[], int limit){
	int c, i;

	for(i = 0; i < limit - 1 && (c = getchar()) != END_OF_FILE && c != '\n'; ++i)
		/*   While the char count i is less than the max word line - 1, -1 to account for '\0',
			 and the char is not an end of file char and not a new line char keep on collecting chars from stdin

			 Note that the order of these expressions matters. c = getchar() needs to occur before c != '\n' or
			 else it would be referring to th previous value of c.

			 Also note that the program will only end if it read the 2 EOF or \n chars in any combination
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

void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i; // While the char is never a string terminating null char copy each char from "from" to "to"
}
