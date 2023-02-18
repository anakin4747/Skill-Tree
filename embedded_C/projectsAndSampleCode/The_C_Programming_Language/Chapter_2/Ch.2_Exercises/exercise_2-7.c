#include <stdio.h>
#include <stdlib.h>

// Write a function invert(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, 
// leaving the other bits unchanged.

unsigned invert(unsigned x, int p, int n);
void print_binary(unsigned x);

int main(int argc, char *argv[]){
    print_binary(invert(0b10101010, 4, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n){
    return x ^ ~(~0 << n) << p;
    /*  ~0, is an int full of ones - This is portable because it does not assume the size of int
        ~(~0 << n), shifts the ones left n places, effectively padding the right with n number of zeros
        Then complimenting the whole thing making it all zeros except for n number of ones at the lsbs
        << p, then pushes these ones p places out to the left
        
        x ^ mask, will invert any bit in x only if the same bit is mask is high

        for an example: x = 0b10101010, p = 4, n = 3

        int mask = ~(~0 << n) << p;
        x ^ mask;

        ~0         mask == 0b1111...11111      Note that this method makes no assumptions of int size so it is portable
        ~0 << 3    mask == 0b1111...11000
        ~(0 << 3)  mask == 0b0000...00111 aka 0b111
        << p       mask == 0b000001110000 aka 0b1110000

                   nnnpppp
            mask  01110000
        ^    x    10101010
        __________________
        =         11011010

        The bitwise XOR, ^, compliments any bit in x that is a 1 in the mask 
    */
}

void print_binary(unsigned x){
    if (x >> 1)     // Check if x shifted right one still holds value
        print_binary(x >> 1);   // If it does call the function on x shifted right one
        // Once the recursion ends, x = 0
    printf("%d", (x & 1));  // Print every bit in the lsb while the recursion calls return
}