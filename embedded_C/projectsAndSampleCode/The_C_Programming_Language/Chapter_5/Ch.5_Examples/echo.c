#include <stdio.h>

int main(int argc, char *argv[]){
	int i;
	
	while(--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");
	return 0;
}