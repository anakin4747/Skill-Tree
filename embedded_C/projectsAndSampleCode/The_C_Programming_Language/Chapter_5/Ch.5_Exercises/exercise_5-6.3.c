#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 40

char *itoa(int n, char *s);
void strrev(char *s);

int main(int argc, char *argv[]){
	char *s = "hello";
	//int largest = -1 * pow(2, 31);

	
	strrev(s);
	printf("%s\n", s);
	return 0;
}

// char *itoa(int n, char *s){
// 	int sign;	
// 	char *t;

// 	if((sign = n) < 0) 
// 		n = -n;

// 	do{
// 		*s = n % 10 + '0';	
// 		s++;
// 	} while((n /= 10) > 0); 

// 	if(sign < 0)
// 		*s++ = '-';	
// 	*s = '\0';
// 	t = strrev(s);
// 	return s;
// }

void strrev(char *s){
	char *n = (char *)malloc(strlen(s) + 1);
	char temp;
	n = s;
	for(; *n; n++)
		;
	n--;
	while(n != s){
		temp = *n;
		*n-- = *s;
		*s++ = temp;
	}
	free(n);
}