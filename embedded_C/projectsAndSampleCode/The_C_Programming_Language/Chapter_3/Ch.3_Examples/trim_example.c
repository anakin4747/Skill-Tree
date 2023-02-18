#include <stdio.h>
#include <string.h>

char * trim(char s[]);

int main(int argc, char *argv[]){
	printf("%s\n", trim(argv[1]));
	return 0;
}

char * trim(char s[]){
	
	int n;
	
	for(n = strlen(s)-1; n >= 0; n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break; 
		// While traversing the string backwards check if the current item 
		// is not a space, tab or new line break out of traversing the string
	s[n + 1] = '\0'; // Add a null terminator to cut the string off once no more whitespace is detected
	return s;
}
