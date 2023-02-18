#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
    
    int pid1 = fork();
    if(pid1 < 0){ 
        printf("Error creating process\n");
        return 2;
    }

    if(pid1 == 0){
        sleep(4);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    } 

    int pid2 = fork();
    if(pid2 < 0){ 
        printf("Error creating process\n");
        return 5;
    }

    if(pid2 == 0){
        // in child process 2
        sleep(1);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    } 

    int pid1_result = waitpid(pid1, NULL, 0);
    printf("Waited for %d\n", pid1_result);    
    int pid2_result = waitpid(pid2, NULL, 0);     
    printf("Waited for %d\n", pid2_result);    
    return 0;
}