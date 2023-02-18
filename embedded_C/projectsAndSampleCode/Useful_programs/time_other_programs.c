#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv){
    int id;
    char *program_to_run = argv[1];
    char cwd[256], ch = '/';
    getcwd(cwd, sizeof cwd);
    strncat(cwd, &ch, 1);
    char *abs_path = strcat(cwd, program_to_run);

    
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);

    if((id = fork()) == 0){
        // child process 
        execl(abs_path, abs_path, NULL);
        printf("FAILURE\n");
    }

    wait(NULL);

    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("Time taken %fs\n",secs);

    return 0;
}