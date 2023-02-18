#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define END_OF_FILE 'X'

int getline(char *line, int max);

int main(int argc, char *argv[]){
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	printf("argc = %d\n", argc);

	while(--argc > 0 && (*++argv)[0] == '-'){
		printf("argc = %d\n", argc);
		// Decrement argc before checking so that it doesnt count argv[0]
		// Increment argv to get argv[1], (*++argv), and take the value of that
		// then access the first char of that value with [0]
		while(c = *++argv[0]){
			// Since it already points at argv[1]
			// Increment through each char of argv[1]
			// This loop ends at the end of the argv[1]
			switch (c) {
				case 'x':
					except = 1;
					//putchar(c);
					break;
				case 'n':
					number = 1;
					//putchar(c);
					break;
				default:
					printf("find: Illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
		argc--;
		if(argc != 1)
			printf("Usage: find -x -n pattern\n");
		else 
			while(getline(line, MAXLINE) > 0){
				lineno++;
				if((strstr(line, *argv) != NULL) != except){
					if(number)
						printf("%ld:", lineno);
					printf("%s", line);
					found++;
				}
			}
		return found;
	}
}



int getline(char *s, int lim){
	int c;
	char *n = s;
	while(--lim > 0 && (c = getchar()) != END_OF_FILE && c != '\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';
	return s - n;
}