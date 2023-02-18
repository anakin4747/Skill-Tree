#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// So we saw the issue caused by race conditions
// Now we look at solutions for these issues

// Mutexes are one solution to this issue
// They are pretty much locks that show that variables
// are in use by other threads

// Note that mutexes slow down your code so its best
// to not use them if you dont have to

int mails = 0;

// We use the POSIX pthread_mutex_t struct to implement
pthread_mutex_t mutex;

void * routine(){
	for(int i = 0; i < 1000000; i++){
		// Lock this code from other threads
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		// Unlock
	}
	return NULL;
}

int main(int argc, char** argv){
	pthread_t t1, t2;
	
	// To initialize our mutex we will use this function
	// and pass the address of our mutex and other parameters
	// We wont touch on the other parameters for now so NULL
	pthread_mutex_init(&mutex, NULL);

	if(pthread_create(&t1, NULL, &routine, NULL) != 0){
		return 1;
	}
	if(pthread_create(&t2, NULL, &routine, NULL) != 0){
		return 2;
	}
	
	if(pthread_join(t1, NULL) != 0){
		return 3;
	}
	if(pthread_join(t2, NULL) != 0){
		return 4;
	}

	// We need to destroy to deallocate our mutex
	pthread_mutex_destroy(&mutex);

	printf("Number of mails: %d\n", mails);
    return 0;
}
