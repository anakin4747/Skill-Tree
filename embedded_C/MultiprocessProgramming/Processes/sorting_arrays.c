#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(){

    int i, temp, swapped;
    int howMany = 10;
    int goals[howMany];

    for(i = 0; i < howMany; i++){
        goals[i] = (rand() % 25) + 1;
    }

    printf("Orignal list\n");
    for(i = 0; i < howMany; i++){
        printf("%d \n", goals[i]);
    }

    return 0;
}