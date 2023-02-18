#include <stdio.h>

#define swap(t, x, y) {t = x; x = y; y = t;}

int main(int argc, char *argv[]){
    int t, x = 6, y = 9;
    printf("x = %d, y = %d\n", x, y);
    swap(t, x, y);
    printf("x swapped = %d, y swapped = %d\n", x, y);

	return 0;
}


