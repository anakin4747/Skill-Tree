#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void convertToBinary(unsigned a);

int main(int argc, char *argv[]){

	int x = 0b10101010;
	int y = 0b01010101;
	int n = 3, p = 4;

	convertToBinary(setbits(x, p, n, y));

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	int result;
	int mask = ~(~(~0 << n) << p);
	result = x & mask;
	int yMask = (y & ~(~0 << n)) << p;
	return result | yMask;
}

void convertToBinary(unsigned a){
	if (a > 1)
		convertToBinary(a / 2);
	printf("%d", a % 2);
}