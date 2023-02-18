#include <stdio.h>

// Program to print the longest string from stdin

#define MAXLINE 1000
#define END_OF_FILE 'X'

int get_line(char *, int);
void copy(char *, char *);

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

int get_line(char *line, int limit){
	int c;
	char *s = line;

	while(line - s < limit - 1 && (c = getchar()) != END_OF_FILE && c != '\n')
		*line++ = c;
		// Store the char into the line string (char array)
	if(c == '\n') // If it is a new line, store the newline char
		*line++ = c;
	*line = '\0';	// Then store the null terminator at the end of the string
	return line - s;		// Return the length of that line
}

void copy(char *to, char *from){
	while((*to++ = *from++)) // While the value at from is not equal to '\0' which is just 0 
		;	// copy the value to *to and increment both pointers
}