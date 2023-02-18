
// Program to count the frequency of digits in stdin

#include <stdio.h>

#define END_OF_FILE 'X'

int main(){
	int c, i, num_of_whitespace, num_of_other;
	int num_of_digits[10];
	
	num_of_whitespace = num_of_other = 0;
	for(i = 0; i < 10; ++i)
	    num_of_digits[i] = 0;

	while((c = getchar()) != END_OF_FILE){
        if(c >= '0' && c <= '9'){   // ASCII value of chars '0' and '9' are 30 and 39 respectively
            // So if the ASCII value of c is between 30 and 39 execute this block
            ++num_of_digits[c - '0']; // Increment the value at the index of c - 30 
            // This value is limited by the previous if statement to only ever result in a value of 0 to 9
            
            // The "y = x - '0'" statement is how you convert from a char integer, x, to a standard int, y.
        } else if(c == ' ' || c == '\n' || c == '\t')
            ++num_of_whitespace;
        else
            ++num_of_other;
	}
	printf("Digits =");
	for(i = 0; i < 10; ++i)
	    printf(" %d", num_of_digits[i]);
	printf(", White space = %d, other = %d\n", num_of_whitespace, num_of_other);
	return 0;
}