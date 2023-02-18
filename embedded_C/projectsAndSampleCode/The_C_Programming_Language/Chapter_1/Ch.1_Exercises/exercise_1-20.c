#include <stdio.h>

// A program to  replace tabs in the input with a TABSTOP number of  spaces

#define END_OF_FILE 'X'
#define TABSTOP 4

int main(){
	int c, i;

	while((c = getchar()) != END_OF_FILE){
		if(c == '\t')
			for(i = 0; i < TABSTOP; i++)
				putchar(' ');
		else
			putchar(c);
	}
	return 0;
}
