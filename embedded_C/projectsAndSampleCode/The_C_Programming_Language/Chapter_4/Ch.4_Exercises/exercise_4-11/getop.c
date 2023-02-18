#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */ 
static int bufp = 0;


int getop(char s[]){ // Gets next char or numeric operand
	int i, c, old_c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;	// Skip white space
	s[1] = '\0';	// Null terminate white space

	if(isalpha(c)){
		i = 0;
		old_c = c;
		s[++i] = c = getch();
		if(isalpha(old_c) && isspace(c))
			return VAR_FOUND;
		while(isalpha(s[++i] = c = getch()))
			;
        s[i] = '\0';
        ungetch(c);
		if(!strcmp(s, "sin")){
			return SIN_FOUND;
		} else if(!strcmp(s, "exp")){
			return EXP_FOUND;
		} else if(!strcmp(s, "pow")){
			return POW_FOUND;
		} else if(!strcmp(s, "last")){
			return LAST_FOUND;
		} else {
			return -1;
		}
	}
	if(!isdigit(c) && c != '.' && c != '-'){ 
		// If c isnt a digit and period or a negative
		return c;
	}
	if(c == '-'){	// Negative number functonality
		if(isdigit(c = getch())){
			s[0] = '-';
			s[1] = c;
		} else {
			ungetch(c);
			return '-';
		}
	}
	i = 1;
	if(isdigit(c))	// If c is a digit
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}
