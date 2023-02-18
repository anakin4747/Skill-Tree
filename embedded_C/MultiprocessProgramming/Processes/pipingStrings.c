#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


// 2 Processes
// 1) Child process should generate random numbers and send them to the parent
// 2) Parent process is going to sum all the numbers and print the result

int main(int argc, char* argv[]){
    int p1[2]; // A pipe for writing from child to parent and reading parent from child
    

    // Making pipes & fork and error checking
    if(pipe(p1) == -1){ return 1;}
    
    int pid = fork();
    if(pid < 0){ return 2;}

    if(pid == 0){
        // in child process
        // generates an array of rand ints and sends it to parent process

        close(p1[0]); // close the pipe for reading parent from child
        
        char string[] = "This is a string";
        int n = sizeof(string);
        
        printf("String: %s", string);
        
        if(write(p1[1], &n, sizeof(int)) < 0){ return 4;};
        printf("\nSent n = %d\n", n);
        if(write(p1[1], string, sizeof(string)) < 0){ return 4;};
        close(p1[1]); 
        

    } else {
        // in parent process
        // take pointer to array and iterate through array to calculate sum then print

        close(p1[1]);
        int n;
        if(read(p1[0], &n, sizeof(int)) < 0){ return 6;};

        char* ptr = (char*) malloc((n*sizeof(char)) + 1);
        printf("Recieved n = %d\n", n);
        if(read(p1[0], ptr, sizeof(char) * n) < 0){ return 6;};

        
        printf("Result is %s\n", ptr);

        close(p1[0]); 
        wait(NULL);
    }


    
    return 0;
}