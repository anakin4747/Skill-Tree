#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

pthread_mutex_t mutex;

void * routine(){
	for(int i = 0; i < 1000000; i++){
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(){
	// We will make an array of threads
	pthread_t th[9];
	
	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < (int)(sizeof(th) / sizeof(th[0])); i++){
		if(pthread_create(&th[i], NULL, &routine, NULL) != 0){
			return 1;
		}
	}

	// These need to be seperate for loops for parallel execution

	for(int i = 0; i < (int)(sizeof(th) / sizeof(th[0])); i++){
		if(pthread_join(th[i], NULL) != 0){
			return 2;
		}
		// Note that the threads will not always finish at the same time
		// We are just waiting for them in order
	}

	pthread_mutex_destroy(&mutex);

	printf("Number of mails: %d\n", mails);
    return 0;
}
