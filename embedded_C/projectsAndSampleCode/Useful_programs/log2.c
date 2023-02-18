
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
	char str[64];
	char *str_ptr = str;
	double x, res;

	if(argc < 2){
		printf("\n\tPlease input a value now: ");
		do{
			scanf("%s", str_ptr);
			x = atof(str);
			while(*str_ptr++){
				ZZ
			}
		}while(1);
		
	} else {
		x = atof(argv[1]);
	}

	res = log(x) / log(2);

	printf("\n\tLog2(%g) = %g\n\n", x, res);

    return 0;
}
