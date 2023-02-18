// Program to print a histogram of the length of words in its input

#include <stdio.h>

#define END_OF_FILE 'X'

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 10  // x axis
#define MAX_WORD_FREQ 5     // y axis

int main(){
	int c, i, j, length, state = OUT;
	i = j = length = 0;
    int length_freqs[MAX_WORD_LENGTH];
    for(i = 0; i < MAX_WORD_LENGTH; i++)
        length_freqs[i] = 0;
    // Declaring and initializing variables
    
	while((c = getchar()) != END_OF_FILE){  // Constantly read from stdin
	    ++length;       // Increment the length the current word every char
        if(c == ' ' || c == '\n' || c == '\t'){
            ++length_freqs[length - 2];     // Increment the value associated with each length of a word
                // Subtract 2 because the first 1 corrects the index and the second removes the whitespace char
            state = OUT;  // Leaving a word
            length = 0;   // After leaving a word reset length for the next word
        } else if(state == OUT){
            state = IN;   // Entering a word
        }
	}
	// The above while loop accepts words and generates array values which holds the frequency of word sizes
	printf("\n Histogram of the length of words entered\n");
    for(i = MAX_WORD_FREQ; i > 0; i--){ 
        printf("%d ", i);   // Print y axis
        for(j = 0; j < MAX_WORD_LENGTH; j++){
            if(i - 1 < length_freqs[j]) 
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < MAX_WORD_LENGTH; i++)
        printf("%d ", i + 1); // Print x axis
    printf("\n");
	return 0;
}