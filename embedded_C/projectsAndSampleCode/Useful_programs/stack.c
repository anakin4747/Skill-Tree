#include <stdio.h>

#define STACKSIZE 3

static char stack[STACKSIZE];
static char *stack_ptr = stack;

void push(char c){
    if(stack_ptr >= stack + STACKSIZE){
        printf("Error: Stack full\n");
        return;
    } else 
        *stack_ptr++ = c;
}

char pop(void){
    if(stack_ptr <= stack)
        return 0;
    else
        return *--stack_ptr;
}
