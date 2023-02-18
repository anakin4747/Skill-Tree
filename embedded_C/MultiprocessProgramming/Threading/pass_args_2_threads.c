#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// The goal is to have a thread to each print one unique value from the array
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg){
	int index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
	// Since we cannot free a in the create for loop we need 
	// to do so here
	return NULL;
}

int main(int argc, char **argv){
	pthread_t th[10];

	for(int i = 0; i < (int)(sizeof(th)/sizeof(th[0])); i++){
		// Added after first try did not work
		int* a = malloc(sizeof(int));
		*a = i;
		// Since i will get written over we to allocate space
		// for a variable that will not change while the thread
		// has access to it, note that for each iteration a will
		// be a different pointer

		if(pthread_create(th + i, NULL, &routine, a) != 0){

			return 1;
		}
		// Tried First
		// if(pthread_create(th + i, NULL, &routine, &i) != 0){
			// If you just pass in the address of i it will increment to 10 faster
			// than each thread would start
			// Or will at least not print them all incrementally
	}

	for(int i = 0; i < (int)(sizeof(th)/sizeof(th[0])); i++){
		if(pthread_join(th[i], NULL) != 0){
			return 1;
		}
	}
    return 0;
}
