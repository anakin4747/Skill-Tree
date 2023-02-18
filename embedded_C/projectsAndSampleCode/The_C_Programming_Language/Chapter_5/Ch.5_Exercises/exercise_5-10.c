#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void push(float);
float pop(void);

int main(int argc, char *argv[]){
	float temp;
	int operand_count, operator_count;
	operand_count = operator_count = 0;
	while(--argc){
		if(isdigit(**++argv)){
			operand_count++;
			push(atof(*argv));
		} else {
			switch(**argv){
				case '+':
					operator_count++;
					push(pop() + pop());
					break;
				case '-':
					operator_count++;
					temp = pop();
					push(pop() - temp);
					break;
				case 'x':
					operator_count++;
					push(pop() * pop());
					break;
				case '/':
					operator_count++;
					if(temp = pop())
						push(pop() / temp);
					break;
				default:
					printf("Invalid input: %s\n", *argv);
					break;
			}
		}
	}

	if(operand_count != operator_count + 1)
		printf("Incomplete input, current result is %g.\n", pop());
	else
		printf("Result is %g.\n", pop());
}

#define STACKSIZE 40

static float stack[STACKSIZE];
static float *stack_ptr = stack;

float pop(void){
	if(stack_ptr <= stack)
		return 0;
	else
		return *--stack_ptr;
}

void push(float f){
	if(stack_ptr > stack + STACKSIZE){
		printf("Error: Stack full.\n");
		return;
	} else 
		*stack_ptr++ = f;
}
