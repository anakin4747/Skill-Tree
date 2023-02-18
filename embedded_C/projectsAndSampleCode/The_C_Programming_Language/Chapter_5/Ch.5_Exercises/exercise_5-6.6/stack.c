#include <stdio.h>
#include "calc.h"


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
