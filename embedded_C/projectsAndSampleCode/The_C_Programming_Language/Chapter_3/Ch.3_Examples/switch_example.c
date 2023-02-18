#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[]){
	int c, i, num_white, num_other, num_digits[10];

	num_white = num_other = 0;
	for(i = 0; i < 10; i++)
		num_digits[i] = 0;
	
	FILE * ptr;

	if((ptr = fopen(argv[1], "r")) == NULL){
		printf("Failed to open file\n");
		return 1;
	}

	while((c = fgetc(ptr)) != EOF){
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			num_digits[c - '0']++;
			break;
		case ' ': case '\n': case '\t':
			num_white++;
			break;
		default:
			num_other++;
			break;
		}
	}
	fclose(ptr);
	printf("Digits =");
	for(i = 0; i < 10; i++)
		printf(" %d", num_digits[i]);
	printf(", white space = %d, other %d\n", num_white, num_other);	
	return 0;
}
