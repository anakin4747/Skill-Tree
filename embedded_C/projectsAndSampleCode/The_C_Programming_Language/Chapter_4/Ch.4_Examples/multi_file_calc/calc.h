#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define VAR_FOUND '1'
#define SIN_FOUND '2'
#define EXP_FOUND '3'
#define POW_FOUND '4'
#define LAST_FOUND '5'

#define MAXVAL 100


int getop(char []);
int getch(void);
void ungetch(int);

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


