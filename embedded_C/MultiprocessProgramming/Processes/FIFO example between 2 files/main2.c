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
    int fd = open("sum", O_RDONLY);
    if(fd == -1){
        printf("Error occured during open()");
        return 1;
    }
    if(read(fd, arr, sizeof(int)*5) == -1){
        return 2;
    }

    int i, sum = 0;
    for(i = 0; i < 5; i++){
        sum += arr[i];
    }
    printf("The sum is: %d\n", sum);
    close(fd);

    return 0;
}
