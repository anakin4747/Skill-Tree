#include <stdio.h>

#define SIZE 100

void recursive_itoa(int, char []);

int main(int argc, char *argv[]){
    char s[SIZE];
    recursive_itoa(-123, s);
    printf("%s\n", s);

	return 0;
}

void recursive_itoa(int n, char s[]){
    static int i = 0;   
    // This int needs to be static so that the index of the 
    // string isnt updated every call of the function
	if(n < 0){	// If negative
		s[i++] = '-'; // Print negative
		n = -n;	// Then treat as positive
	}
	if(n / 10){	// If n is at least divisible by 10
		recursive_itoa(n / 10, s);
		// Recursively call yourself with n / 10
		// This will continue to call itself until
		// n < 10 since the integer division will 
		// result in rounding down
	}
	s[i++] = n % 10 + '0';	// Once you exit the last call
	// Save the char of the digit
}

/*

Adapt the ideas of recursive_itoa to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive routine.


*/