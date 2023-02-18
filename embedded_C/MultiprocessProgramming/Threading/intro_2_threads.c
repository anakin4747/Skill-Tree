
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// Note you need to pass -pthread as a arg to gcc
// I have added it to the Makefile

void * routine(){
	printf("Test from my dick\n");
	sleep(3);
	printf("Ending thread\n");
	return NULL;
}
// Threads run functions

int main(int argc, char** argv){
	// If a something exists it needs to be stored somewhere
	// So the threads information will be stored in a pthread_t variable
	// pthread_t is just a struct
	// We need to allocate this memory as such
	pthread_t t1, t2;

	// We create a thread by using this function
	// We pass the address of the thread we wish to create,
	// NULL for default settings for now,
	// a pointer the function the thread will run,
	// and the parameters of the function which in our case is NULL
	if(pthread_create(&t1, NULL, &routine, NULL) != 0){
		printf("Error creating t1\n");
		return 1;
	}
	if(pthread_create(&t2, NULL, &routine, NULL) != 0){
		printf("Error creating t2\n");
		return 2;
	}
	
	// We have to wait for the thread to finish before the process
	// exits, so we will call pthread_join to make the main function
	// wait for the thread to end
	// We pass which thread to wait for, t1, and an address which
	// the return value of the function will be stored, in our case
	// NULL since the function does not return anything
	if(pthread_join(t1, NULL) != 0){
		return 3;
	}
	if(pthread_join(t2, NULL) != 0){
		return 4;
	}

    return 0;
}
