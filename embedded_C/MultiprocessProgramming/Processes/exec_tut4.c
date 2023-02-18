#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == -1) { return 1;}

    if(pid == 0){

        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if(file == -1){
            return 2;
        }
        printf("The fd to pingResults: %d\n", file);
        dup2(file, STDOUT_FILENO);
        close(file);

        int err  = execlp("ping", "ping", "-c", "1", "google.com", "|", "grep", "\"rtt\"", NULL);
        if(err == -1){
            printf("Could not find program to execute!\n");
            return 2;
        }
    } else {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)){
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode == 0){
                printf("Success!\n");
            } else {
                printf("Failure with status code %d\n", statusCode);
            }
        }
        printf("Some post processing goes here\n");
    }
    return 0;
}