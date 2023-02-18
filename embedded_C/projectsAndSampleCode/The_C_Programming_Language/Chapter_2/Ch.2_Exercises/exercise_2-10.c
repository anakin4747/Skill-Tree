#include <stdio.h>

int lower(char c);

int main(int argc, char *argv[]){
	printf("%c %c\n", lower('C'), lower('c'));

	return 0;
}

int lower(char c){
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
