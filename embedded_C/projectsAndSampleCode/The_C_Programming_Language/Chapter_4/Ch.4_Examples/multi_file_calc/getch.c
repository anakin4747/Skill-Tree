#include <stdio.h>

#define BUFSIZE 100

// Getch and Ungetch allow for undoing a read from stdin
// By providing a buffer you can "put a char back" by putting it on the buffer
// And then the next time you need the next input just pull from the buffer before stdin
// And once the buffer is empty just pull from stdin again

char buf[BUFSIZE];	// Buffer
int bufp = 0;		// Current index of buffer to keep track of buffer size
			// It points to the next open index

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
	// If the buffer is not empty return last added char and decrement buffer size
	// If the buffer is empty get a new char from stdin
	// Since bufp points to the next open index of buf[]
	// You need to decrement before accessing so that it takes the one
	// from the previous index
}

void ungetch(int c){
	if(bufp >= BUFSIZE)	// If buffer has reached capacity
		printf("ungetch: too many characters\n");// Print error
	else
		buf[bufp++] = c; // Add c to the next free position in the buffer
			// Increment buffer size to reflect increase
}
