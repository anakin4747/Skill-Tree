#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_OF_FILE 'X'
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void q_sort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void get_cmd_line_args(int argc, char **argv, int *numeric, int *reverse);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0, reverse = 0;

	get_cmd_line_args(argc, argv, &numeric, &reverse);	

	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		q_sort((void**) lineptr, 0, nlines - 1, 
				(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		// The fourth argument in q_sort is a function pointer
		// that returns an int and accepts two void pointers
		// as arguments. The function gets selected by the ternary 
		// expression, then gets casted to all the properties just listed
		writelines(lineptr, nlines, reverse);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
	return 0;
}

void get_cmd_line_args(int argc, char **argv, int *numeric, int *reverse){
	char c;
	while(--argc > 0 && **++argv == '-')
		while(c = *++(*argv))
			switch (c){
				case 'n':
					*numeric = 1;
					break;
				case 'r':
					*reverse = 1;
					break;
				default:
					printf("Illegal argument %c\n", c);
					break;
			}
}


int numcmp(const char *s1, const char *s2){
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}

void q_sort(void *v[], int left, int right, int (*comp)(void *, void*)){
	int i, last;

	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last - 1, comp);
	q_sort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j){
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


#define MAXLEN 1000
int getline(char *, int);

char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;

	while((len = getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse){
	if(reverse)
		for(; *lineptr; lineptr++)
			;
	while(nlines-- + reverse > 0)
		printf("%s\n", reverse ? *lineptr-- : *lineptr++);
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

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

void afree(char *p){
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
