#include <stdio.h>

int atoi(char s[]);

int main(int argc, char *argv[]){
	printf("%d\n", atoi(argv[1]));
	return 0;
}

void shellsort(int v[], int n){
	int gap, i, j, temp;

	for(gap = n / 2; gap > 0; gap /=2) // This loop controls the gap between 
			// compared elements shrinking the gap by a factor of 2 
			// with each pass until there are not gaps
		for(i = gap; i < n; i++) // This loop steps along all elements
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
				// This loop compares pairs of elements
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}