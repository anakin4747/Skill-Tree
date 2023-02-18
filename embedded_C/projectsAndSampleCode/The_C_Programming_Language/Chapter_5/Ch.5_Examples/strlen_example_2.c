#include <stdio.h>
#include <stddef.h>

ptrdiff_t str_len(char *);

int main(int argc, char **argv){

	printf("%d\n", str_len(argv[1]));
	return 0;
}

ptrdiff_t str_len(char *s){
	char *p = s;	// Copy the pointer s to a new pointer p
	// The * is only there to define it as a pointer not
	// to access the value at p
    while (*p != '\0')	// While the value at p is not the end of a string
        p++;	// Increment the char pointer to the next char
	return p - s; 
	// Return the difference of the addresses
}

// ptrdiff_t is a signed int that will be big enough to hold the difference of 2 pointers
// It is used here because the p - s may return a value larger than an int can hold