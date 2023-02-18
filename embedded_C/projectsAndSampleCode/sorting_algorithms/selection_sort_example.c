#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(){
    int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
    int length = sizeof(a) / sizeof(int);
    
    for(int i = 0; i < length - 1; i++){    
        int min_pos = i;
        for(int j = i +1; j < length; j++){
            if(a[j] < a[min_pos]) 
                min_pos = j; 
                // To make this algorithm largest to smallest flip the < for >
            }
        
        if(min_pos != i){
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
    for(int i = 0; i < length; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}
