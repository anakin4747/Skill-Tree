
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// To simulate a race condition
// We consider an example where several threads
// count some amount of mail
// Its really not important that this example isnt
// realistic

int mails = 0;
// Note that since this is global and threads share
// the same memory since theyre in the same process
// all threads can access mails

void * routine(){
	for(int i = 0; i < 100000; i++){
		mails++;
		// Operatios:
			// Read value of mails
			// Increment
			// Write mails
	}
	return NULL;
}
// function just increments the amount of mail
// With the limit of the for loop being 100 to program works as expected
// But as we increment the number of loops the program will begin to
// act irregularly, this is a race condition

// Since threads can be stopped and started by the operating system,
// the threads may be stopped in the middle of the 3 operations listed
// in the function. So if one thread read the value then stopped and the
// other thread kept going, then the first thread continued. The first
// thread would write over all the increments the second thread performed

int main(int argc, char** argv){
	pthread_t t1, t2;

	if(pthread_create(&t1, NULL, &routine, NULL) != 0){
		printf("Error creating t1\n");
		return 1;
	}
	if(pthread_create(&t2, NULL, &routine, NULL) != 0){
		printf("Error creating t2\n");
		return 2;
	}
	
	if(pthread_join(t1, NULL) != 0){
		return 3;
	}
	if(pthread_join(t2, NULL) != 0){
		return 4;
	}
	
	printf("Number of mails: %d\n", mails);
    return 0;
}
