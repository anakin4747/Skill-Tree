
// Program to print a histogram of the frequencies of different characters in its input

#include <stdio.h>
#include <ctype.h>

#define END_OF_FILE '\n'
#define IN 1
#define OUT 0
#define MAX_CHAR_FREQ 20


int main(){
	int c, i, j, length, state = OUT;
	i = j = length = 0;
	int char_freqs[94];

	for(i = 0; i < 94; i++)
		char_freqs[i] = 0;
	printf("Input characters then hit enter to print histogram\nIf it doesnt look correct zoom out to get the full x axis in view then rerun it.\n");
	while((c = getchar()) != END_OF_FILE){
		if(c >= '!' && c <= '~')
			++char_freqs[c - '!'];
	}
	printf("\n\t Histogram of character frequencies\n");
	for(i = MAX_CHAR_FREQ; i > 0; i--){
		if(i >= 10)
			printf("%d ", i);
		else
			printf("%d  ", i);
		for(j = 0; j < 94; j++){
			if(i - 1 < char_freqs[j])
				printf("# ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("   ");
	for(i = 0; i < 94; i++)
		printf("%c ", (char)(i + 33));
	return 0;
}
