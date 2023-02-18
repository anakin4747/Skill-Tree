#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define MAXLINE 1000
#define END_OF_FILE 'X'

int getline(char *s, int max);

int main(int argc, char *argv[]){
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	
	while(--argc > 0 && (*++argv)[0] == '-'){ 
		// If the options are not joined like -x and -n
		// Then this will account for it by decrementing count 
		// and moving to the next argument
		while(c = *++argv[0]){ // Iterate through each char of argv[1]
			switch(c){
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: Illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}
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

	return 0;
}


int getline(char *s, int max){
	int c;
	char *n = s;
	while(--max > 0 && (c = getchar()) != END_OF_FILE && c != '\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';
	return s - n;
}
