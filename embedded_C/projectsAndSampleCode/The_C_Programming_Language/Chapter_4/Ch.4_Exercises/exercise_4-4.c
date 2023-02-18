#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define MAXOP 100	
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);	
void push(double);
double pop(void);
double peak(void);
void duplic(double copy[]);
void swap(void);
void clear(void);

int main(int argc, char *argv[]){
	int type, i;
	double op2, top;
	char s[MAXOP];
	double copy[MAXVAL];

	printf("\nPlease enter operands and operations in Reverse Polish form.\n"
		"Noramly 1 + 2 = 3 but with this calculator you need to type 1 2 + to get 3.\n"
		"Available operations are +, -, *, /, and %%.\n"
		"\tHit enter when complete.\n");

	while((type = getop(s)) != EOF){	// While not the end of the file
		switch(type){
			case NUMBER:	// If getop() returned '0'
				push(atof(s));
				break;
			case '+':
				push(pop() + pop()); // Since the order of these operands doesnt matter you can do it like this
				break;
			case '*':
				// clear();
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				// Order of operands matter now so you need to force the program to execute the pop for operand 2 to happen first
				// If they are on the same line there is not guarantee that the pops will occur in the desired order
			case '/':
				// swap();
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
				top = peak(); // Had to use a variable to force peak() to be called first
				printf("\tpeak %.8g\n\tpop %.8g\n", top, pop()); // If the peak and pop are in the same printf line you cant be sure which will be called first
				// duplic(copy);
				// for(i = 0; floor(copy[i]) != 0; i++)
				//	;
				// for(i = i - 1; i >= 0; i--)
				//	printf("%.8g\n", copy[i]);
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
		printf("error in pop: stack empty\n");
		return 0.0;
	}
}

double peak(void){
	if(sp > 0){	// If the stack is not empty
		return val[sp - 1]; // Return the top float without actually decrementing sp
	} else {
		printf("error in peak: stack empty\n");
		return 0.0;
	}
}

void duplic(double stack_copy[]){
	int i;
	if(sp > 0){	// If the stack is not empty
		for(i = sp - 1; i >= 0; i--)
			stack_copy[i] = val[i]; 
	} else {
		printf("error: stack empty\n");
	}
	// Not perfect, probably requires a stack pointer too idk
}

void swap(void){
	double temp1, temp2;
	if(sp > 0){	// If the stack is not empty
		temp1 = pop();
		temp2 = pop();
		push(temp1);
		push(temp2);		
	} else {
		printf("error: stack empty\n");
	}
}

void clear(void){
	val[0] = 0.0;
	sp = 0;
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
