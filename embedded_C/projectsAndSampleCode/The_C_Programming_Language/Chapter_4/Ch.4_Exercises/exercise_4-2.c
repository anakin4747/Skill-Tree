#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double atof_example(char s[]);

int main(int argc, char *argv[]){

	printf("%g\n", atof_example(argv[1]));
	return 0;
}


double atof_example(char s[]){
	double val, power;
	int i, sign, e_sign, sci_not;

	for(i = 0; isspace(s[i]); i++)
		;	// Skip white space
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++) // While the string is digits
		val = 10.0 * val + (s[i] - '0'); // Convert from chars to float
	if(s[i] == '.') // If there is a period skip it
		i++;
	for(power = 1.0; isdigit(s[i]); i++){ // Since this part is collecting the decimal places
		val = 10.0 * val + (s[i] - '0'); // This just keeps piling digits in the ones place
		power *= 10; // Power collects how many magnitudes got piled on
	}
	if(tolower(s[i]) == 'e'){
		i++;
		e_sign = (s[i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(sci_not = 0; isdigit(s[i]); i++)
			sci_not = 10 * sci_not + (s[i] - '0');
		return sign * val / power * pow(10, (e_sign) * sci_not);
	}	
	return sign * val / power;	// You then divide by power to get the decimal back in the right place
}
