#include <stdio.h>

void printd(int);

int main(int argc, char *argv[]){

	printd(666);
	putchar('\n');
	printd(-666);
	putchar('\n');
	return 0;
}

void printd(int n){
	if(n < 0){	// If negative
		putchar('-'); // Print negative
		n = -n;	// Then treat as positive
	}
	if(n / 10){	// If n is at least divisible by 10
		printd(n / 10);
		// Recursively call yourself with n / 10
		// This will continue to call itself until
		// n < 10 since the integer division will 
		// result in rounding down
	}
	putchar(n % 10 + '0');	// Once you exit the last call
	// Print the char of the digit
}

