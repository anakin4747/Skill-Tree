#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigtstp(int sig){
    printf("\nStop not allowed\n");
}

void handle_sigcont(int sig){
    printf("Input number: ");
    fflush(stdout);
}

int main(int argc, char* argv[]){
    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa, NULL);

    // signal(SIGTSTP, &handle_sigtstp);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, 5 * x);

    return 0;
}