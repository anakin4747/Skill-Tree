#include <stdio.h>

// Program to print lines in reverse

#define MAXLINE 1000
#define END_OF_FILE 'X'

int get_line(char line[], int limit);
char* reverse(char line[], int length);

int main(){

	int length;
    char line[MAXLINE];
	// Declaring and initializing ints and strings

	while((length = get_line(line, MAXLINE)) > 0)
		printf("%s", reverse(line, length)); // Print the string "line"
	return 0;
}

int get_line(char line[], int limit){
	int c, i;

	for(i = 0; i < limit - 1 && (c = getchar()) != END_OF_FILE && c != '\n'; ++i)
		/*   While the char count i is less than the max word line - 1, -1 to account for '\0',
			 and the char is not an end of file char and not a new line char keep on collecting chars from stdin

			 Note that the order of these expressions matters. c = getchar() needs to occur before c != '\n' or
			 else it would be referring to the previous value of c.

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

char* reverse(char line[], int length){
	char temp;	// Temporary swapping variable
	length = length - 2;	// Move index down 2 to preserve position of '\n' and '\0'

	for(int i = 0; i < (length + 1) / 2; i++){ // For half the length of the string swap chars
				// This works because once you reach the center element of the string it is fully reversed
		temp = line[i];		// Temporarily save the indexed element
		line[i] = line[length - i]; // Overwrite the indexed element with the element at the mirrored index
		line[length - i] = temp;	// Save old indexed element to the mirrored index
	}
	length = length + 2;	// Move index back to keep '\n' and '\0' at the end
	return line;		// Return a pointer to the reversed string/character array
}
