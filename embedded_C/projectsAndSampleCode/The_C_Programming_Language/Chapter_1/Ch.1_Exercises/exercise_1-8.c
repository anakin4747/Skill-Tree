#include <stdio.h>

#define END_OF_FILE 'X'

int main(){
	int c;
	int blanks, tabs, newlines;
	blanks = tabs = newlines = 0;

	while((c = getchar()) != END_OF_FILE){
		if(c == ' ')
			blanks++;
		else if (c == '\t')
			tabs++;
		else if (c == '\n')
			newlines++;
	}
	printf("There were %d blanks, %d tabs, and %d newlines.\n", blanks, tabs, newlines);
	return 0;
}