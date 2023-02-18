#include <stdio.h>

int atoi_func(char s[]);

int main(int argc, char *argv[]){
    printf("%d\n", atoi_func(argv[1])); // Input an argument with running this program
    return 0;
}

int atoi_func(char s[]){
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i) // While chars are between 0 and 9 inclusive
        n = 10 * n + (s[i] - '0');      // 10 * n takes the last value of n and multiplies it by 10 
                // to make room in the tenths place for the next n, the s[i] - '0' is the actual conversion from char to int
                // it subtracts the ASCII value of '0' to get the actual integer value
                // Say s[i] was '1', then the math would be 31 - 30 = 1 because 31 is the ASCII value of '1' and 30 for '0' 
    return n;
}