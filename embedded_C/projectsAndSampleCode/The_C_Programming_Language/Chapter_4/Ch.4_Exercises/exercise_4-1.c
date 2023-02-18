#include <stdio.h>

#define MAXLINE 1000
#define END_OF_FILE 'X'

int strindex(char s[], char t);

int main(int argc, char *argv[]){

	printf("%d\n", strindex(argv[1], 't'));

	return 0;
}


int strindex(char s[], char t){
	int i, rightmost;
	for(i = 0, rightmost = 0; s[i] != '\0'; i++)
		if(s[i] == t)
			rightmost = i;
	if(rightmost > 0)
		return rightmost;
	else
	 	return -1;
}
