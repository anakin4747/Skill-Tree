#include <stdio.h>

#define MAXLINE 1000
#define END_OF_FILE 'X'

int get_line(char line[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // Globally defined string

int main(int argc, char *argv[]){

	char line[MAXLINE];
	int found = 0;

	while(get_line(line, MAXLINE) > 0) // While there is still a line to get, get it
		if(strindex(line, argv[1]) >= 0){
			printf("%s", line);
			found++;
		}
	return found;
}

int get_line(char s[], int lim){
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != END_OF_FILE && c != '\n') // While there is space in the array and the string is not done and the char is not a newline
		s[i++] = c; // Copy char to string and increment index
	if(c == '\n')	// After the line has been copied add a newline to the string
		s[i++] = c;		
	s[i] = '\0';	// Terminate the string
	return i;	// Return the index
}

int strindex(char s[], char t[]){
	int i, j, k;
	for(i = 0; s[i] != '\0'; i++){	// While the string/line is not done iterate through it
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // If s matches t
			// Iterate through the line at index j and through string t in parallel
			;
		if(k > 0 && t[k] == '\0') // Now check if all of t matched
				// If k did not increment the full length of t then t[k]
				// would not equal '\0'
			return i;	// Return index of string
	}
 	return -1;	// If you didnt hit the other return then it did not match and return -1

}
