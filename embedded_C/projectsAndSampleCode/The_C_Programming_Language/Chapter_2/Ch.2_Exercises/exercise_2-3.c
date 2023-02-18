#include <stdio.h>
#include <ctype.h>
#include <math.h>

double htoi(char s[]);

int main(int argc, char* argv[]){
	printf("%.0lf\n", htoi(argv[1]));
	return 0;
}

double htoi(char s[]){
	int length, j, x;	
	double n;
	if(s[0] == '0' && tolower(s[1]) == 'x')
		x = 2;
	else
		x = 0;
	for(length = 0; s[length] != '\0'; length++)
		;
	if(length >= 14){
		printf("Too big of an input.\n");
		return 0;
	}
	length--;
	
	n = 0;
	for(j = 0; (s[j + x] >= '0' && s[j + x] <= '9') || (tolower(s[j + x]) >= 'a' && tolower(s[j + x]) <= 'f'); ++j){
		if(s[j + x] >= '0' && s[j + x] <= '9')
			n += (s[j + x] - '0') * pow(16, length - j - x);
		else
			n += (tolower(s[j + x]) - 87) * pow(16, length - j - x);
	}
	return n;
}