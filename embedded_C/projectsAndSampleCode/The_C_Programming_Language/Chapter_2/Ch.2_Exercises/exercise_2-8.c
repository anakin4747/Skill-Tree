#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

void convertToBinary(unsigned a);

int main(int argc, char *argv[]){

	int x = 0b10101010;
	int n = 3, p = 4;

	int result = x ^ (((1<<n)-1) << p);
	convertToBinary(result);
	printf("\n");
	convertToBinary(invert(x, p, n));

	return 0;
}

unsigned invert(unsigned x, int p, int n){
	int mask = (~(~0 << n) << p);
	//return (x | mask) & ~(x & mask);
	return x ^ mask;
}

void convertToBinary(unsigned a){
	if (a > 1)
		convertToBinary(a / 2);
	printf("%d", a % 2);
}