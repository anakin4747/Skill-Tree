#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>  //for opening fifos

int main(int argc, char* argv []){
    int arr[5];
    srand(time(NULL));
    int i;
    for(i = 0; i < 5; i++){
        arr[i] = rand() % 100;
        printf("Generated %d\n", arr[i]);
    }

    int fd = open("sum", O_WRONLY);
    if(fd == -1){
        printf("Error occured during open()");
        return 1;
    }

    
    if(write(fd, arr, sizeof(int)*5) == -1){
        printf("Error occured during write()");
        return 2;
    }

    close(fd);

    return 0;
}
