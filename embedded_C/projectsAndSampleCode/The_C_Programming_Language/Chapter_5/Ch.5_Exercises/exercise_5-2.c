#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define END_OF_FILE 'X'
#define BUFSIZE 10

int main(){

	int n, getfloat(float *);
	float array[BUFSIZE];

	for(n = 0; n < BUFSIZE && getfloat(&array[n]) != END_OF_FILE; n++)
		;
	for(int i = 0; i < n; i++)
		printf("%g ", array[i]);

	return 0;
}

int getch(void);
void ungetch(int);

int getfloat(float *pn){

	int c, sign, e_sign = 1, exp = 1;
	float decimal;
	
	while(isspace(c = getch()))
		; // This skips white space as it will continue to get a new char until it is no longer white space
	if(!isdigit(c) && c != END_OF_FILE && c != '+' && c != '-' && c != '.'){
		ungetch(c); // If c is not a digit return 0 from getint call
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1; // Store sign to reapply later

	if(c == '+' || c == '-'){ // If there is a sign skip it 
		c = getch();
	}

	for(*pn = 0; isdigit(c); c = getch()) // While c is a digit get a new char
		*pn = 10 * *pn + (c - '0');
	if(c == '.'){
		c = getch();	
	}
	for(decimal = 1; isdigit(c); c = getch(), decimal *= 10) // While c is a digit get a new char
		*pn = 10 * *pn + (c - '0');
	if(tolower(c) == 'e'){
		c = getch();
		e_sign = (c == '-') ? -1 : 1;
		if(c == '+' || c == '-'){ // If there is a sign skip it 
			c = getch();
		}
		for(exp = 0; isdigit(c); c = getch()) // While c is a digit get a new char
			exp = 10 * exp + (c - '0');
	}
	*pn *= (sign / decimal) * pow(10, exp * e_sign); // Reapply sign
	if(c != END_OF_FILE)	// If it isnt the end of file out it back
		ungetch(c);
	return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("Error ungetched too many chars\n");
	else
		buf[bufp++] = c;	
}
