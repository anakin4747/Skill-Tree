#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char* argv[]){
    int fd[2];
    //fd[0] - read
    //fd[1] - write    
    if(pipe(fd) == -1){
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if(id == -1){
        printf("An error ocurred with forking\n");
        return 2;
    }
    if(id == 0){
        // child process
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if(write(fd[1], &x, sizeof(int)) == -1){
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1){
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        y *= 3;
        close(fd[0]);
        printf("Got from child process %d\n", y);
    }
    return 0;
}
