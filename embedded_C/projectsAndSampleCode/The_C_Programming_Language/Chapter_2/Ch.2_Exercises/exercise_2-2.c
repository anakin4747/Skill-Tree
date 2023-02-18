#include <stdio.h>

#define END_OF_FILE 'X'

int main(){
    int c, lim, i = 0;
    char s[100];
    
    while(i < lim -1){
        if((c = getchar()) != '\n')
            if(c != END_OF_FILE)
                s[i] = c;
        i++;
    }
    return 0;
}

/*
    for(i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/