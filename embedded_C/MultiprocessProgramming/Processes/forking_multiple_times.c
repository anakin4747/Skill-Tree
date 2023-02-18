#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char* argv[]){
    int id1 = fork();
    int id2 = fork();
    if(id1 == 0){
        if(id2 == 0){
            printf("We are child process y\n");
        } else {
            printf("We are child process x\n");
        }
    } else{
        if(id2 == 0){
            printf("We are child process z\n");
        } else {
            printf("We are the main process!\n");
        }
    }
    /*
    Tree diagram that represents the processes

                main    
            id1=x,id2=z             
           /           \
      child x          child z
    id1=0,id2=y      id1=x,id2=0
        |
      child y
    id1=0,id2=0

    */
    while(wait(NULL) != -1 || errno != ECHILD){ 
        /*
        to prevent orphaning a process you have to wait until all 
        children have completed
        if you just use wait(NULL) it will only wait for the first process to return
        thats the reason for this while loop to check if there are anymore children
        */
        printf("Waited for a child to finish\n");
    }
    return 0;
}
