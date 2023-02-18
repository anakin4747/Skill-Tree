#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 500
#define BUFSIZE 1000
#define END_OF_FILE 'X'

char *lineptr[MAXLINES];

int all_digits(char *s);
int readlines(char *lineptr[], char *bufp, int nlines);
void writelines(char *lineptr[], int nlines, int ntail);

int main(int argc, char *argv[]){
	int nlines;	// Number of lines
	int num_tailing_lines = 10;	
	char c, buffer[BUFSIZE];
	char *bufp = buffer;

	if(**++argv == '-' && all_digits(++*argv) && atoi(*argv) < MAXLINES)
		num_tailing_lines = atoi(*argv);


	if((nlines = readlines(lineptr, bufp, MAXLINES)) >= 0){ 
		// Read lines and save number of lines read
		printf("\n");
		writelines(lineptr, nlines, num_tailing_lines);
		// Print sorted lines
		return 0;
	} else {
		// If the input was too big, readlines() returns a -1
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], char *bufp, int maxlines){
	int len, nlines;
	char *p, *buf_start, line[MAXLEN];
	buf_start = bufp;
	nlines = 0;

	while((len = getline(line, MAXLEN)) > 0){  
		// Get the next line, save it in line and save the length in len
		if(nlines >= maxlines || buf_start + BUFSIZE - bufp < len)
			return -1; // Too big an input or ran out of storage
		else {
			bufp += len;
			p = bufp - len;
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int ntail){
	lineptr += nlines - ntail;
	while(ntail-- > 0)
		printf("%s\n", *lineptr++);
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

int all_digits(char *s){
	char *n;
	for(n = s; *n; n++)
		;
	for(; isdigit(*s); s++)
		;
	return n == s;
}
