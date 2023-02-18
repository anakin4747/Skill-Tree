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
    if(pid == -1){ return 2;}

    if(pid == 0){
        // in child process
        // generates an array of rand ints and sends it to parent process

        close(p1[0]); // close the pipe for reading parent from child
        

        int n, i;
        int arr[10];
        srand(time(NULL));
        n = rand() % 10 + 1;
        printf("Generated: ");
        for(i = 0; i < n; i++){
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
        }
        if(write(p1[1], &n, sizeof(int)) < 0){ return 4;};
        printf("\nSent n = %d\n", n);
        if(write(p1[1], arr, sizeof(int) * n) < 0){ return 4;};
        close(p1[1]); 
        

    } else {
        // in parent process
        // take pointer to array and iterate through array to calculate sum then print

        close(p1[1]);
        int n, i, sum = 0;
        int arr[10];
        if(read(p1[0], &n, sizeof(int)) < 0){ return 6;};
        printf("Recieved n = %d\n", n);
        if(read(p1[0], arr, sizeof(int) * n) < 0){ return 6;};

        for(i = 0; i < n; i++){
            sum += arr[i];
        }
        printf("Result is %d\n", sum);

        close(p1[0]); 
        wait(NULL);
    }


    
    return 0;
}