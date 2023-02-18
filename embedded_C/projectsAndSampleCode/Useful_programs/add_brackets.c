#include <stdio.h>

#define IN 1
#define OUT 0

/*
    Make a program that scans a file to check for syntax errors and checks if lines
    of code are not properly bracketed, like a lot of the time you type some 
    conditional statements without a bracket because you think you'll only need 
    one line, but you come back to it and add more lines which are tabbed in so 
    they are meant to be a part of the conditional block. These will actually 
    be run outside the conditional leading to a logical error. And have it ask if
    I want to fix them then fix it for me.

*/

int main(int argc, char *argv[]){
    int c;


    // Opening files and error checking

    FILE * old_file_ptr;
    FILE * new_file_ptr;

    if((old_file_ptr = fopen(argv[1], "r")) == NULL){
        printf("No file by that name\n");
        return 1;
    }

    if((new_file_ptr = fopen(argv[2], "w")) == NULL){
        printf("Failed to open new file\n");
        return 1;
    }

    while((c = getchar()) != EOF){
        // Check after )'s to see if the next char is a \n
    }


    // Close opened files

    fclose(new_file_ptr);
    fclose(old_file_ptr);

    return 0;
}