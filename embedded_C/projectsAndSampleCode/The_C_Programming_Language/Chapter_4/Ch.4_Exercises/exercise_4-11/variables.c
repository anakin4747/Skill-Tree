#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100	

char variables[23]; // 26 letters in the alphabet minus s, e, and p
float var_values[23];
int current_variable_index;

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
