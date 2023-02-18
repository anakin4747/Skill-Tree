#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_binary(unsigned x);

int main(int argc, char *argv[]){
    print_binary(pow(2, 31));
    return 0;
}

void print_binary(unsigned x){
    if (x >> 1)     // Check if x shifted right one still holds value
        print_binary(x >> 1);   // If it does call the function on x shifted right one
        // Once the recursion ends, x = 0
    printf("%d", (x & 1));  // Print every bit in the lsb while the recursion calls return
}