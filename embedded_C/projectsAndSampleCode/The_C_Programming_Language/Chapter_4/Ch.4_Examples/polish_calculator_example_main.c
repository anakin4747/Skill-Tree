#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100	
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);	
void push(double);
double pop(void);

int main(int argc, char *argv[]){
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){	// While not the end of the file
		switch(type) {
			case NUMBER:	// If getop() returned '0'
				push(atof(s));
				break;
			case '+':
				push(pop() + pop()); // Since the order of these operands doesnt matter you can do it like this
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				// Order of operands matter now so you need to force the program to execute the pop for operand 2 to happen first
				// If they are on the same line there is not guarantee that the pops will occur in the desired order
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


int sp = 0;	// Next free stack position
double val[MAXVAL]; // Stack

void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if(sp > 0)	
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}



int getch(void);
void ungetch(int);

int getop(char s[]){
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
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


char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
