#include <stdio.h>

int bitcount(unsigned x);

void convertToBinary(unsigned a);

int main(int argc, char *argv[]){

	int x = 0b10101000;
	
	convertToBinary(x);
	printf("\n%d", bitcount(x));

	return 0;
}

int bitcount(unsigned x){
	int b;
	for(b = 0; x != 0; x >>= 1) // While x still holds value, shift all bits right 1 place
		if(x & 01) // If the lsb is 1 
			b++; // Increment count
	return b++;	// Return count
}

void convertToBinary(unsigned a){
	if (a > 1)
		convertToBinary(a / 2);
	printf("%d", a % 2);
}