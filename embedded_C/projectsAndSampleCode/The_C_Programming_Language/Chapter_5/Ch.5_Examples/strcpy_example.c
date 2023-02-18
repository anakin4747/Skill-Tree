#include <stdio.h>

#define SIZE 40

void strcpy_arr(char *, char *);
void strcpy_ptr(char *, char *);

int main(int argc, char **argv){
	char str1[40], str2[40];
	strcpy_arr(str1, "Copy this bitch");
	strcpy_ptr(str2, str1);
	printf("%s\n", str2);
	return 0;
}

void strcpy_arr(char *s, char *t){
	int i;
	i = 0;

	while((s[i] = t[i]) != '\0')
		i++;	
}

void strcpy_ptr(char *s, char *t){
	while((*s++ = *t++)) // While the value at t is not equal to '\0' which is just 0 
		;	// copy the value to *s and increment both pointers
}


