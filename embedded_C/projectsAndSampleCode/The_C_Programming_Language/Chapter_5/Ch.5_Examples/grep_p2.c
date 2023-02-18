#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define END_OF_FILE 'X'

int getline(char *line, int max);

int main(int argc, char *argv[]){
	char line[MAXLINE];
	int found = 0;
	if(argc != 2)
		printf("Usage: find pattern\n");
	else
		while(getline(line, MAXLINE) > 0)
			if(strstr(line, argv[1]) != NULL){
				printf("%s", line);
				found++;
			}
	return found;
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
