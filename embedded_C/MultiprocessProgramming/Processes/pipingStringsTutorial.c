#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
    int p1[2]; // A pipe for writing from child to parent and reading parent from child
    

    // Making pipes & fork and error checking
    if(pipe(p1) == -1){ return 1;}
    
    int pid = fork();
    if(pid < 0){ return 2;}

    if(pid == 0){
        // in child process
       
        close(p1[0]); 
        
        char string[200];

        printf("Input string: ");
        fgets(string, 200, stdin);
        string[strlen(string) - 1] = '\0';
        
        printf("String: %s", string);

        int n = strlen(string) + 1;
        
        if(write(p1[1], &n, sizeof(int)) < 0){ return 4;};
        printf("\nSent n = %d\n", n);
        if(write(p1[1], string, sizeof(char) * n) < 0){ return 4;};
        close(p1[1]); 
        

    } else {
        // in parent process

        close(p1[1]);
        char str[200];
        int n;

        if(read(p1[0], &n, sizeof(int)) < 0){ return 6;};
        
        printf("Recieved n = %d\n", n);
        if(read(p1[0], str, sizeof(char) * n) < 0){ return 6;};

        printf("Result is %s\n", str);

        close(p1[0]); 
        wait(NULL);
    }


    
    return 0;
}