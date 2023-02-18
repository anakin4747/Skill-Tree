#include <stdio.h>

#define END_OF_FILE 'X'
#define MAX_LINE_SIZE 8

int main(){

	int c, i;
	i = 0;

	while((c = getchar()) != END_OF_FILE){
		if(c != '\n')
			i++;
		else
			i = 0;


		if(i > MAX_LINE_SIZE){// If i is bigger than the max size line
			if(c == ' ' || c == '\t'){ // And the char is whitespace
				putchar('\n');
				i = 0;
			} else
				putchar(c);
		} else
			putchar(c);
	}
	return 0;
}
