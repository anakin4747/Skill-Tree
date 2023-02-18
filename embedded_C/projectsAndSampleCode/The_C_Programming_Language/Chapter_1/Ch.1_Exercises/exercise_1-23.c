#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
    int c, old_c = 0, sl_comment, ml_comment, quote;
    sl_comment = ml_comment = quote = OUT;


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


    // Main logic for coping file and checking state 

    while((c = fgetc(old_file_ptr)) != EOF){    // While the old file is not at the end
        if((c == '\"' || c == '\'') && sl_comment != IN && ml_comment != IN && quote != IN) // If you read a " or ' and not in a comment or quote
            quote = IN;     // You just entered a quote
        else if((c == '\"' || c == '\'') && quote == IN)    // If you read a " or ' and you are in a quote
            quote = OUT;    // You just left a quote
        if((old_c == '/' && c == '/') && quote != IN && ml_comment != IN)   // If you read // and not in a quote 
            sl_comment = IN;    // You just entered a single line comment
        if((old_c == '/' && c == '*') && quote != IN && sl_comment != IN)   // If you read /* and not in a quote
            ml_comment = IN;    // You just entered a multi line comment
        if((old_c == '*' && c == '/') && ml_comment == IN)   // If you read */ and are in a multi line comment but not a single line comment or a quote
            ml_comment = OUT;   // You just left a multi line comment
        if(c == '\n' && sl_comment == IN)   // If you read '\n' and are in a single line comment
            sl_comment = OUT;   // You just left a single line comment
        if((c != '/' && sl_comment == OUT && ml_comment == OUT) || quote == IN) // If you do not read a '/' and are outside a comment or are in a quote 
            fputc(c, new_file_ptr);     // Copy char from old file to new
        old_c = c;  // Save last char for checking
    }


    // Close opened files

    fclose(new_file_ptr);
    fclose(old_file_ptr);

    return 0;
}