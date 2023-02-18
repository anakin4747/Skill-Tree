#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(int argc, char *argv[]){
    printf("////**//**/*/*/////***/%d\n", getbits(argv[1], argv[2], argv[3])); // Input an argument with running this program //*/*/''""
    return 0;
}

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p + 1 - n)) & ~(~0 << n);
    /*
        On the right of the & operator, the ~0 will be an int filled with 1s
        the << n pushs the 1s n places to the left, padding the right with n
        number of 0s. This value then gets complimented again with ~ so now
        the value is 1s for the n lsbs and 0 for the rest of the word.

            This way of doing it is smart since it doesnt make any assumptions of
            the machines size of int

        That was all to build a bitmask, next the bitmask gets ANDed with 
        everything on the left side of & to clear all values to the left 
        of the n number of 1s

        On the left of the operator &, the position, p, plus 1 minus n
        calculates the lsb of x which this function retrieves, it then
        shifts x by that many places left to make this n range of bits
        sit at the lsbs.

        This then gets bitmasked to clear all the bits left of p in x.
        The only thing remaining is the range of n bits in x. 

        

    */
}