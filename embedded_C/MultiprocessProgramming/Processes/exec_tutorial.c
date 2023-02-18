#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char* argv[], char* envp[]){
    char* arr[] = {
        "ping2",
        "google.com",
        NULL
    };

    char* env[] = {
        "TEST=environment variable",
        NULL
    };
    execvpe("ping", arr, env);

    return 0;

}