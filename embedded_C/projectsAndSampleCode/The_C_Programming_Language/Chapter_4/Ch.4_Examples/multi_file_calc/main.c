#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100	

extern char variables[]; 
extern float var_values[];
extern int current_variable_index;

int main(int argc, char *argv[]){
	int type, i;
	double op2, top;
	char s[MAXOP];
	double copy[MAXVAL];
	
	prompt_variables();
	current_variable_index = collect_var_values();
	print_vars();

    printf("\nPlease enter operands and operations in Reverse Polish form.\n"
		"Normally 1 + 2 = 3 but with this calculator you need to type 1 2 + to get 3.\n"
		"Available binary operations are +, -, *, /, %%, and pow.\n"
        "Available unary operations are sin and exp.\n"
        "The keyword last is reserved for the previous result.\n");

	fflush(stdin); 
	/*	Similar in the buffer of getch and ungetch
		getchar() also has a buffer which needs to be cleared
		or else it will stay in the way. A \n would hang in the buffer after
	
	*/

	while((type = getop(s)) != EOF){	// While not the end of the file
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