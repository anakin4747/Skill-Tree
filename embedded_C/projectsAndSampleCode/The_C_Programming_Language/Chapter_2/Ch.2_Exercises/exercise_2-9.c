#include <stdio.h>

int bitcount(unsigned x);

void convertToBinary(unsigned a);

int main(int argc, char *argv[]){

	int x = 0b10101010;
	
	convertToBinary(x);
	printf("\n%d", bitcount(x));

	return 0;
}

int bitcount(unsigned x){
	int b;
	for(b = 0; x != 0; x &= x - 1) // Remove the rightmost 1 from x until x is empty  
		b++; // Increment count
	return b++;	// Return count
}

void convertToBinary(unsigned a){
	if (a > 1)
		convertToBinary(a / 2);
	printf("%d", a % 2);
}