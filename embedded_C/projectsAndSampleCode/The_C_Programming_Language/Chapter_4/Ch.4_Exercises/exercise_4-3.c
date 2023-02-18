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
		switch(type){
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
			case '%':
				op2 = pop();				
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor in modulo\n");
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
	if(sp < MAXVAL) // If there is space on the stack
		val[sp++] = f;	// Add the float and increment the index
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if(sp > 0)	// If the stack is not empty
		return val[--sp]; // Decrement to get the top float then return it
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

int getop(char s[]){ // Gets next char or numeric operand
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;	// Skip white space
	s[1] = '\0';	// Null terminate white space

	
	if(!isdigit(c) && c != '.' && c != '-'){ // If c isnt a digit and period or a negative
		return c;
	}
	if(c == '-'){
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

// Getch and Ungetch allow for undoing a read from stdin
// By providing a buffer you can "put a char back" by putting it on the buffer
// And then the next time you need the next input just pull from the buffer before stdin
// And once the buffer is empty just pull from stdin again

char buf[BUFSIZE];	// Buffer
int bufp = 0;		// Current index of buffer to keep track of buffer size
			// It points to the next open index

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
	// If the buffer is not empty return last added char and decrement buffer size
	// If the buffer is empty get a new char from stdin
	// Since bufp points to the next open index of buf[]
	// You need to decrement before accessing so that it takes the one
	// from the previous index
}

void ungetch(int c){
	if(bufp >= BUFSIZE)	// If buffer has reached capacity
		printf("ungetch: too many characters\n");// Print error
	else
		buf[bufp++] = c; // Add c to the next free position in the buffer
			// Increment buffer size to reflect increase
}
