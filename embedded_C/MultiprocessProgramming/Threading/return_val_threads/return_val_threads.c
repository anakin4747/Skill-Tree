#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* roll_dice(){
	int value = (rand() % 6) + 1;

	// Since we cannot return addresses of local variables
	// inside functions because that memory will be deallocated
	// after the function returns we need to store it somewhere on the heap
	int* result = malloc(sizeof(int));
	*result = value;
	return  (void*)result;
}

int main(void){
	int* res;
	srand(time(NULL));
	pthread_t th;
	if(pthread_create(&th, NULL, &roll_dice, NULL) != 0){
		return 1;
	}
	if(pthread_join(th, (void**)&res) != 0){
		return 2;
	}
	printf("Result is 66%d\n", *res);

	// Since we called malloc we need to call free
	// We cant call free in the roll_dice function
	// because the data hasnt been used yet so we
	// need to do it in main
	free(res);

	return 0;
}
