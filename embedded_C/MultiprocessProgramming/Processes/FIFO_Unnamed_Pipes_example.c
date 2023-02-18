#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>  //for opening fifos

int main(int argc, char* argv []){
    if(mkfifo("myfifo1", 0777) == -1){
        if(errno != EEXIST){ // is error not just that the file already exists?
            printf("Could not create fifo file\n");
            return 1;
        }
    }
    printf("Opening...\n");
    int fd = open("myfifo1", O_WRONLY); //open(file, flag); O_WRONLY flag is for writing, O_RDWR is for reading and writing
    if(fd == -1){
        printf("Error occured with open()\n");
        return 2;
    }
    printf("Opened\n");
    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1){ // writing to the named pipe with error checking
        printf("Error occured with write()\n");
        return 3;
    }
    printf("Written\n");
    close(fd);
    printf("Closed\n");
    return 0;
}

/*
Note: 
    From Linux Manual Pages:
    FIFOs
       Opening the read or write end of a FIFO blocks until the other
       end is also opened (by another process or thread).  See fifo(7)
       for further details.

This is why this code will hang after Opening...

To make it stop hanging either change O_WRONLY to O_RDWR or run cat myfifo1 in a separate terminal
*/
