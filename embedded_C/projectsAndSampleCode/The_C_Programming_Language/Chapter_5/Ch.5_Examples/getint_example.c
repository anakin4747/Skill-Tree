#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define END_OF_FILE 'X'

int main(int argc, char *argv[]){
    
    int n, array[SIZE], getint(int *); 
        // Declaring an int, an array, and a function which returns an int

    for(n = 0; n < SIZE && getint(&array[n]) != END_OF_FILE; n++)
        ;
        // Iterate through the array calling getint on every int in array[]
        // This populates the array

    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
            // Printing all elements of the array
    return 0;
}

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign;

    while(isspace(c = getch()))
        ;
        // Skip whitespace

    if(!isdigit(c) && c != END_OF_FILE && c != '+' && c != '-'){
        ungetch(c); // Push back on input if not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
        // If the char is '-' make sign equal to -1 else sign is 1
    if(c == '-' || c == '+')
       c = getch();
            // If c is a sign move past it and get the next char
    for(*pn = 0; isdigit(c); c = getch())  // While c is a digit get the next char
        *pn = 10 * *pn + (c - '0'); // Convert the value at *pn from a char to an int
    *pn *= sign; // Reapply the sign to the newly converted value
    if(c != END_OF_FILE)
        ungetch(c);
    return c;
}



// Getch and Ungetch allow for undoing a read from stdin
// By providing a buffer you can "put a char back" by putting it on the buffer
// And then the next time you need the next input just pull from the buffer before stdin
// And once the buffer is empty just pull from stdin again

#define BUFSIZE 100

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
