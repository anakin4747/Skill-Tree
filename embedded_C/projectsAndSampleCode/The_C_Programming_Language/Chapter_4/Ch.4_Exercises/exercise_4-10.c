#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define VAR_FOUND '1'
#define SIN_FOUND '2'
#define EXP_FOUND '3'
#define POW_FOUND '4'
#define LAST_FOUND '5'

#define MAXOP 100	
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

double peak(void);
void duplic(double []);
void swap(void);
void clear(void);

void prompt_variables(void);
int collect_var_values(void);
void print_vars(void);
double get_var_value(char []);

char variables[23]; // 26 letters in the alphabet minus s, e, and p

float var_values[23];

int current_variable_index;

size_t bufsize = BUFSIZE;
char *buf;	// Buffer


int main(int argc, char *argv[]){
    
	int type, i;
	double op2, top;
	char s[MAXOP];
	double copy[MAXVAL];
	
	prompt_variables();
	current_variable_index = collect_var_values();
	print_vars();

    printf("\nPlease enter operands and operations in Reverse Polish form.\n"
		"Noramly 1 + 2 = 3 but with this calculator you need to type 1 2 + to get 3.\n"
		"Available binary operations are +, -, *, /, %%, and pow.\n"
        "Available unary operations are sin and exp.\n"
        "The keyword last is reserved for the previous result.\n");

	fflush(stdin); 
	/*	Similar in the buffer of getch and ungetch
		getchar() also has a buffer which needs to be cleared
		or else it will stay in the way. A \n would hang in the buffer after
	
	*/

	while((type = getline(&buf, &bufsize, stdin)) != EOF){	// While not the end of the file
		switch(type){
			case NUMBER:	// If getop() returned '0'
				push(atof(s));
				break;
			case VAR_FOUND:
				push(get_var_value(s));
				break;
			case '+':
				push(pop() + pop()); 
				// Since the order of these operands 
				// doesnt matter you can do it like this
				break;
			case '*':
				// clear();
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				/* 	
					Order of operands matter now so you need to force 
					the program to execute the pop for 
					operand 2 to happen first
				
					If they are on the same line there is 
					not guarantee that the pops will occur 
					in the desired order
				*/			
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
			case SIN_FOUND:
				push(sin(pop()));
				break;
			case EXP_FOUND:
				push(exp(pop()));
				break;
			case POW_FOUND:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case LAST_FOUND:
				push(top);
				break;
			case '\n':
				top = peak(); 
				printf(" = %.8g\n\n", pop()); 
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

void prompt_variables(void){
    



	int i;
	char c;
	printf("\nIf you wish to use any variables please "
		   "enter their single char now\nHit enter once finished.\n");
	i = 0; 
	while((c = getchar()) != '\n'){
		if(isalpha(c)){
			variables[i++] = c;
		}
	}
	variables[i] = '\0';
}

int collect_var_values(void){
	int i;
	char s[20];
	for(i = 0; variables[i] != '\0'; i++){
		printf("Please input value for variable: %c\n", variables[i]);
		scanf(" %s", s);
		var_values[i] = atof(s);
	}
	return i;
}

void print_vars(void){
	int i;
	printf("Variables selected:\n");
	for(i = 0; variables[i] != '\0'; i++){
		printf("%c = %g\n", variables[i], var_values[i]);
	}
}
double get_var_value(char s[]){
	int i;
	for(i = 0; s[0] != variables[i] && variables[i] == '\0'; i++)
		;
	if(variables[i] == '\0'){
		printf("Error fetching variable, not variable found.\n");
		return -1;
	} else
		return var_values[i];
}

int sp = 0;	// Next free stack position
double val[MAXVAL]; // Stack

void push(double f){
	int k;
	if(sp < MAXVAL){ // If there is space on the stack
		val[sp++] = f;	// Add the float and increment the index
	} else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	char c;
	if(sp > 0){	// If the stack is not empty
		return val[--sp]; 
		// Decrement to get the top float then return it
	} else {
		printf("error in pop: stack empty\n");
		return 0.0;
	}
}

double peak(void){
	if(sp > 0){	// If the stack is not empty
		return val[sp - 1]; 
		// Return the top float without actually decrementing sp
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



