#include <stdio.h>

int main(){

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 150;
	step = 10;

	celsius = lower;
	printf("Celsius to Faherienheit  Conversion\nCelsius Fahr\n");
	while(celsius <= upper){
		fahr = celsius / (5.0 / 9.0) + 32.0;
		printf("%3.0f    %6.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
