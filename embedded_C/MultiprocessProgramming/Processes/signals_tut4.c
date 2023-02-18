#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int x = 0;

void handle_sigusr1(int sig){
    if(x == 0){
        printf("You are actually a fucking idiot\n");
    }
}


int main(int argc, char* argv[]){
    int pid = fork();

    if(pid == -1){
        return 1;
    }

    if(pid == 0){
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        printf("What is the result of 3 x 5?: ");
        scanf("%d", &x);
        if(x == 15){
            printf("Right!\n");

        } else {
            printf("Wrong!\n");
        }
        wait(NULL);
    }

    return 0;
}